# include <stdio.h>

# include <string.h>

 

//Function declaration

  

void write();

void display(char date[]);

void displaycust(char name[]);

void displayall();

void delrec(char date[],char name[]);

void editrec(char date[],char name[]);

  

  

  

  

int main(){

  

    int ch=1;

    int op;

    char lookdate[20];

    char lookname[20];

    char password[10];

 

    printf("\n\t******  Welcome to BRTC Bus Trip Record Generator  ******\n");

    printf("\nPlease enter the provided password: ");

    scanf("%s",&password);

 

 

//Main Menu

  

    while(ch==1){

       if(strcmp(password,"BRTC123")==0){

 

        printf("\n\t******  BRTC Bus Trip Record Generator  ******\n");

  

        printf("\nMANAGE TRIPS");

 

 

        printf("\nPress 1  to create a trip");

        printf("\nPress 2 to edit a trip");

        printf("\nPress 3 to delete a trip");

  

        printf("\n");

  

        printf("\nDISPLAY TRIPS");

        printf("\nPress 4  to search trips for a specific departure date");

        printf("\nPress 5  to search trips for a specific customer");

        printf("\nPress 6  to display all trips");

  

        printf("\n");

  

        printf("\nPress 7 to exit the program");

  

        printf("\n\nEnter option:");

        scanf("%d",&op);

  

        switch(op){

  

            case 1: write();break;

            case 2: printf("Enter departure date and name to edit a trip.\n");

  

                    printf("Enter Departure date: ");

                    scanf("%s",&lookdate);

  

                    printf("Enter customer name: ");

                    scanf("%s",&lookname);

  

                    editrec(lookdate,lookname);

  

                    break;

            case 3: printf("Enter departure date and name to delete a trip.\n");

  

                    printf("Enter Departure date: ");

                    scanf("%s",&lookdate);

  

                    printf("Enter customer name: ");

                    scanf("%s",&lookname);

  

                    delrec(lookdate,lookname);

  

                    break;

  

            case 4: printf("Enter departure date to display:");scanf("%s",&lookdate);display(lookdate);break;

            case 5: printf("Enter customer name to display:");scanf("%s",&lookname);displaycust(lookname);break;

            case 6: displayall();break;

  

  

  

            case 7:ch=0;break;

  

        }

  

  

    }else{

        printf("Invalid password\n");

 

    }

  

    return 0;

  

}

 

//Create trip Function

  

void write(){

    FILE *fp;

    char departdate[20];

    char returndate[20];

    char startdes[20];

    char enddes[20];

    char cname[20];

    char mn[15];

    int cost;

    int seats;

    int totalcost;

  

  

    printf("\nEnter departure date:");

    scanf("%s",&departdate);

    printf("\nEnter return date:");

    scanf("%s",&returndate);

    printf("\nEnter departure location:");

 

    scanf("%s",&startdes);

    printf("\nEnter return location:");

    scanf("%s",&enddes);

    printf("\nEnter customer name:");

    scanf("%s",&cname);

    printf("\nEnter mobile number:");

    scanf("%s",&mn);

    printf("\nEnter cost per seat:");

    scanf("%d",&cost);

    printf("\nEnter number of seats:");

    scanf("%d",&seats);

  

    totalcost=seats*cost;

  

  

    fp=fopen("Record.txt","a");

    // a(apend mode) -instead of overwriting, new data is written just below the old data

  

    fprintf(fp,"\n%s %s %s %s %s %s %d %d %d\n",departdate,returndate,startdes,enddes,cname,mn,cost,seats,totalcost);

    printf("\nRecorded successfully\n\n");

    fclose(fp);

  

}

  

char departdater[20];

char returndater[20];

char startdesr[20];

 

char enddesr[20];

char cnamer[20];

char mnr[15];

int costr;

int seatsr;

int totalcostr;

 

//Display by departure date function


  

void display(char date[]){

  

    FILE *fp;

    int res;

  

  

    fp=fopen("Record.txt","r");

  

    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

  

    while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,&costr,&seatsr,&totalcostr)!=EOF){

        res=strcmp(departdater,date);

  

        if(res==0){

            printf("\nDeparture date: %s",departdater);

  

            printf("\nReturn date: %s",returndater);

  

            printf("\nDeparture location: %s",startdesr);

  

            printf("\nReturn location: %s",enddesr);

  

            printf("\nCustomer name:%s",cnamer);

  

            printf("\nMobile number: %s",mnr);

  

            printf("\nCost of trip per seat: %d",costr);

  

            printf("\nNo. of seats: %d",seatsr);

  

            printf("\nTotal cost: %d\n\n",totalcostr);

  

            printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

        }

    }

  

    fclose(fp);

  

}

 

//Display by customer name function

 

  

void displaycust(char name[]){

  

    FILE *fp;

    int res;

  

  

    fp=fopen("Record.txt","r");

  

    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

  

    while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,&costr,&seatsr,&totalcostr)!=EOF){

        res=strcmp(cnamer,name);

        if(res==0){

            printf("\nDeparture date: %s",departdater);

  

            printf("\nReturn date: %s",returndater);

  

            printf("\nDeparture location: %s",startdesr);

  

            printf("\nReturn location: %s",enddesr);

  

            printf("\nCustomer name:%s",cnamer);

  

            printf("\nMobile number: %s",mnr);

  

            printf("\nCost of trip per seat: %d",costr);

  

            printf("\nNo. of seats: %d",seatsr);

  

            printf("\nTotal cost: %d\n\n",totalcostr);

  

            printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

  

        }

    }

  

    fclose(fp);

  

}

 

//Display all function

 

  

  

void displayall(){

  

    FILE *fp;

    int res;

  

  

    fp=fopen("Record.txt","r");

  

    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

    while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,&costr,&seatsr,&totalcostr)!=EOF){

  

            printf("\nDeparture date: %s",departdater);

  

            printf("\nReturn date: %s",returndater);

  

            printf("\nDeparture location: %s",startdesr);

  

            printf("\nReturn location: %s",enddesr);

  

            printf("\nCustomer name:%s",cnamer);

  

            printf("\nMobile number: %s",mnr);

  

            printf("\nCost of trip per seat: %d",costr);

  

            printf("\nNo. of seats: %d",seatsr);

  

            printf("\nTotal cost: %d\n",totalcostr);

  

            printf("\n");

  

            printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

  

    }

  

    fclose(fp);

  

  

}

 

//Delete record function
    
// I used lizard to find complexity of the display function

 

    void delrec(char date[],char name[]){

        FILE *fp;

        FILE *fp2;

        int res1,res2;

        int ch;

      

        fp=fopen("Record.txt","r");

        fp2=fopen("Replica.txt","w");

      

        printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

      

        while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,&costr,&seatsr,&totalcostr)!=EOF){

            res1=strcmp(departdater,date);

            res2=strcmp(cnamer,name);

            if(res1==0){

                printf("\nDeparture date: %s",departdater);

      

                printf("\nReturn date: %s",returndater);

      

                printf("\nDeparture location: %s",startdesr);

      

                printf("\nReturn location: %s",enddesr);

      

                printf("\nCustomer name:%s",cnamer);

      

                printf("\nMobile number: %s",mnr);

      

                printf("\nCost of trip per seat: %d",costr);

      

                printf("\nNo. of seats: %d",seatsr);

      

                printf("\nTotal cost: %d\n\n",totalcostr);

      

                printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

      

                printf("Are you sure you want to delete the above trip?(input '0 for no' or '1 for yes')\n");

      

                scanf("%d",&ch);

      

            }

      

      

        }

      

      

      

        if(ch==1){

      

            rewind(fp);



      

            while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,&costr,&seatsr,&totalcostr)!=EOF)
            {

                char comb[20];

                char comb2[20];

      

      

                strcpy(comb,departdater);

                strcat(comb,cnamer);

      

                strcpy(comb2,date);

                strcat(comb2,name);

      

      

      

                res1=strcmp(comb2,comb);

      

                if(res1!=0){

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,costr,seatsr,totalcostr);

      

                }

      

            }

      

            printf("\nDeleted successfully\n\n");

      

            fclose(fp);

            fclose(fp2);

      

            remove("Record.txt");

            rename("Replica.txt","Record.txt");
                



        }



    }
 

 

//Edit record function

 

void editrec(char date[],char name[]){

    FILE *fp;

    FILE *fp2;

    int res1,res2;

    int ch;

  

  

    char departdateori[20];

    char returndateori[20];

    char startdesori[20];

    char enddesori[20];

    char cnameori[20];

    char mnori[15];

    int costori;

    int seatsori;

    int totalcostori;

  

  

  

    char departdatee[20];

                char returndatee[20];

                char startdese[20];

                char enddese[20];

                char cnamee[20];

                char mne[15];

                int coste;

                int seatse;

                int totalcoste;

  

                int choice;

  

    fp=fopen("Record.txt","r");

    fp2=fopen("Replica.txt","w");

  

    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

    while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdesori,enddesori,cnameori,mnori,&costori,&seatsori,&totalcostori)!=EOF){

        res1=strcmp(departdateori,date);

        res2=strcmp(cnameori,name);

        if(res1==0 && res2==0){

            printf("\nDeparture date: %s",departdateori);

  

            printf("\nReturn date: %s",returndateori);

  

            printf("\nDeparture location: %s",startdesori);

  

            printf("\nReturn location: %s",enddesori);

  

            printf("\nCustomer name:%s",cnameori);

  

            printf("\nMobile number: %s",mnori);

  

            printf("\nCost of trip per seat: %d",costori);

  

            printf("\nNo. of seats: %d",seatsori);

  

            printf("\nTotal cost: %d\n\n",totalcostori);

  

            printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

  

  

  

            printf("Are you sure you want to edit the above trip?(input '0 for no' or '1 for yes')\n");

  

            scanf("%d",&ch);

  

        }

  

  

    }

  

  

  

  

  

    if(ch==1){

  

  

                rewind(fp);

  

  

  

  

                while(fscanf(fp,"%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,&costr,&seatsr,&totalcostr)!=EOF){

                    char comb[20];

                    char comb2[20];

  

  

                    strcpy(comb,departdater);

                    strcat(comb,cnamer);

  

                    strcpy(comb2,date);

                    strcat(comb2,name);

  

  

  

                    res1=strcmp(comb2,comb);

  

                    if(res1!=0){

                        fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdater,returndater,startdesr,enddesr,cnamer,mnr,costr,seatsr,totalcostr);

  

                    }

  

  

                }

  

  

  

  

  

                printf("\nEnter 1 to edit departure date");

  

                printf("\nEnter 2 to edit return date");

  

                printf("\nEnter 3 to edit departure location");

  

                printf("\nEnter 4 to edit return location");

  

                printf("\nEnter 5 to edit customer name");

  

                printf("\nEnter 6 to edit mobile number");

  

                printf("\nEnter 7 to edit cost");

  

                printf("\nEnter 8 to edit no. of seats\n");

  

                scanf("%d",&choice);

  

  

  

                switch(choice){

  

                    case 1: printf("\nEnter new departure date:");

                        scanf("%s",&departdatee);break;

  

                    case 2: printf("\nEnter new return date:");

                        scanf("%s",&returndatee);break;

  

                    case 3: printf("\nEnter new departure location:");

                        scanf("%s",&startdese);break;

  

                    case 4: printf("\nEnter new return location:");

                        scanf("%s",&enddese);break;

  

                    case 5: printf("\nEnter new customer name:");

                        scanf("%s",&cnamee);break;

  

                    case 6: printf("\nEnter new mobile number:");

                        scanf("%s",&mne);break;

  

                    case 7: printf("\nEnter cost:");

                        scanf("%d",&coste);break;

  

                    case 8: printf("\nEnter no. of seats:");

                        scanf("%d",&seatse);break;

  

  

  

                }

  

                if(choice==1){

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdatee,returndateori,startdesori,enddesori,cnameori,mnori,costori,seatsori,totalcostori);

  

                }else if(choice ==2){

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndatee,startdesori,enddesori,cnameori,mnori,costori,seatsori,totalcostori);

  

                }else if(choice ==3){

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdese,enddesori,cnameori,mnori,costori,seatsori,totalcostori);

  

                }else if(choice ==4){

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdesori,enddese,cnameori,mnori,costori,seatsori,totalcostori);

  

                }else if(choice ==5){

 

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdesori,enddesori,cnamee,mnori,costori,seatsori,totalcostori);

  

                }else if(choice ==6){

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdesori,enddesori,cnameori,mne,costori,seatsori,totalcostori);

  

                }else if(choice ==7){

                    totalcoste=seatsori*coste;

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdesori,enddesori,cnameori,mnori,coste,seatsori,totalcoste);

  

                }else if(choice ==8){

                    totalcoste=seatse*costori;

                    fprintf(fp2,"\n%s %s %s %s %s %s %d %d %d\n",departdateori,returndateori,startdesori,enddesori,cnameori,mnori,costori,seatse,totalcoste);

  

                }

  

  

                else{

                    printf("\ninvalid choice\n");

  

                }

  

  

 

 

                printf("\nEdited successfully\n\n");

  

  

                fclose(fp);

                fclose(fp2);

  

                remove("Record.txt");

                rename("Replica.txt","Record.txt");

  

  

    }

  

  

  

}

 

