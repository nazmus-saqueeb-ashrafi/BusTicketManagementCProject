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
