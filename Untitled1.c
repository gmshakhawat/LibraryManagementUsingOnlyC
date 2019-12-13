#include<stdio.h>
#include<time.h>
#include<string.h>
int main()
{

    char rw[99999],id[20],idr[20],bc[20],bcr[20],co[99999],dt[20],dmy[11],ic[99999],ar[9999][99],temp[99999],ch,dtt[3],dmy2[12],sp[2]=" ",fr[5]=".txt",fn[30],mn[3],yr[5],sd[12],bw[10]="Borrowed",rt[10]="Returned",ts[10]="ThisDate",all[5]="All";
    printf("Welcome to the Bigest Library of BAIUST (by Shakhawat)\n\n");
    int ag,ag2,ag3,ag4,ag5,ag6,ag7,ag9,ag10,ag11,ex,agd,c1,t,il,bcl,ck,f,ok,i,c,bk,j,tp,bbcl,a,b,d,dl,bkl=2,ac,n,sl,dd,m,y,ch2,ch3,ch4,ch5,sdl,nf,bwl,rtl,d1,t1,df,ty;
    FILE *lb,*up,*du;
    ag:
    a=-1;
    bk=0;
    ck=0;
    il=7;
    ok=0;
    ac=0;
    dl=10;
    tp=8;
    sl=0;
    n=0;
    d1=0;
    t1=0;
    nf=0;
    bcl=3;
    bwl=strlen(bw);
    rtl=strlen(rt);
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(dmy, 11, "%m/%d/%Y", timeinfo);
    strftime(dmy2, 11, "%m-%d-%Y", timeinfo);

    //
    strftime(dtt,3,"%d",timeinfo);
    strftime(mn,3,"%m",timeinfo);
    strftime(yr,5,"%Y",timeinfo);
    dd=atoi(dtt);
    m=atoi(mn);
    y=atoi(yr);

    //
    printf("\n\nPlease Selecte One\n  1.Borrow\n  2.Return\n  3.History\n  4.Archive\n  4.Exit\n");
    scanf("%d",&c1);                                                                                                                                                                                                                       // Shakhawat Hossain
    switch(c1)
    {
        case 1: lb=fopen("Archive.txt","a+");
                up=fopen("Update.txt","a+");
                printf("ID : ");
                scanf("%s",&id);
                il=strlen(id);
                fscanf(up ," %[^.,:!;]",&ic);
                t=strlen(ic);
                for(i=0;i<t;i++)
                {
                   if((ic[i]==' ')||(ic[i]=='\n'))
                   {
                       a=i-a-1;
                       if(a==il)
                       {

                           int re=i-il;

                           for(j=0;j<il;j++,re++)
                           {

                               if(id[j]==ic[re])
                               {
                                   ok++;

                               }
                           }
                       }
                       else
                       {
                           a=i;
                       }
                   }
                   if(ok==il)
                   {
                      // f=i-bcl-il-1;
                       bk++;

                   }

                   ok=0;


                }
                if(bk>=bkl)
                {
                    printf("Alert!!!\a\tAlert!!!\a\tAlert\a !!! \nID %s already Borrow %d Books and didn't return Yet \nSo This ID Holder can't Borrow any Book Yet Untill the return of Previous Book\n\n",id,bk);
                    goto ag;
                }

                printf("Book Code : ");
                agbc:
                scanf("%s",&bc);
                bbcl=strlen(bc);
                for(i=0;i<t;i++)
                {
                   if((ic[i]==' ')||(ic[i]=='\n'))
                   {
                       a=i-a-1;
                       if(a==bbcl)
                       {
                           int re=i-bbcl;

                           for(j=0;j<bbcl;j++,re++)
                           {

                               if(bc[j]==ic[re])
                               {
                                   ok++;
                               }
                           }
                       }
                       else
                       {
                           a=i;
                       }
                   }
                   if(ok==bbcl)
                   {
                       //f=i-bcl-il-1;
                       ck++;
                   }
                   ok=0;
                }
                if(ck>=1)
                {
                    printf("Sorry!!! \nThis Book already one person Borrowed\nPlease Enter Accual Book Code :  ");
                    ck=0;
                    goto agbc;
                }
                fprintf(lb,"%s ",id);
                fprintf(lb,"%s ",bc);
                fprintf(up,"%s ",id);
                fprintf(up,"%s ",bc);
                fprintf(lb, "%s ", dmy);
                fprintf(lb,"Borrowed\n");
                fprintf(up, "%s ", dmy);
                fprintf(up,"Borrowed\n");
                fclose(lb);
                fclose(up);

                //
    // n=0;
    lb=fopen("Archive.txt","r");
    ch=getc(lb);
   fclose(lb);
   lb=fopen("Archive.txt","r");
    while(ch!=EOF)
    {   ch=getc(lb);

        if(ch=='\n')
        {
            n++;

        }
    }
    //printf("n=%d\n",n);

    lb=fopen("Archive.txt","r");
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            fscanf(lb," %[^\n]",&ar[i]);
        }

    }

    fclose(lb);
    for(i=1;i<n+1;i++)
    {
          for(j=2;j<n;j++)
          {
            if(strcmp(ar[j-1],ar[j])>0)
            {
                strcpy(temp,ar[j-1]);
                strcpy(ar[j-1],ar[j]);
                strcpy(ar[j],temp);
            }
          }
    }
    fclose(lb);
    lb=fopen("Archive.txt","w");
    fprintf(lb," ID     BC     DATE     Type   \n");
    for(i=1;i<n+1;i++)
    {
        sl=strlen(ar[i]);
        if(sl>5)
        {
            fprintf(lb,"%s\n",ar[i]);
        }
    }

    fclose(lb);

    //
                printf("Successfully Book Borrowed\a\n");
                goto ag;
        case 2:
                printf("Book Code : ");
                scanf("%s",&bcr);
                bcl=strlen(bcr);
                up=fopen("Update.txt","a+");
                fscanf(up ," %[^.,:!;]",&rw);
                t=strlen(rw);
                for(i=0;i<t;i++)
                {
                   if((rw[i]==' ')||(rw[i]=='\n'))
                   {
                       a=i-a-1;
                       if(a==bcl)
                       {
                           int re=i-bcl;

                           for(j=0;j<bcl;j++,re++)
                           {
                               if(bcr[j]==rw[re])
                               {
                                   ok++;
                               }
                           }
                       }
                       else
                       {
                           a=i;
                       }
                   }
                   if(ok==bcl)
                   {
                       f=i-bcl-il-1;
                       break;
                   }
                   ok=0;
                }
                if(ok==bcl)
                {
                    up=fopen("Update.txt","w");
                    for(i=0;i<t;i++)
                    {
                        if(i==f)
                        {
                            i=i+bcl+il+1+dl+1+tp+1;
                            ac=i-dl-1-tp-1;
                           // printf("\nt= %d , i= %d, ac= %d, f= %d\n",t,i,ac,f);
                        }
                        else
                        {
                        fprintf(up,"%c",rw[i]);
                        }
                    }
                    fclose(up);
                    lb=fopen("Archive.txt","a+");
                    for(i=0;i<t;i++)
                    {
                        //ac=i+bcl+il+1+dl;
                        if(i>=f && i<ac)
                        {
                            fprintf(lb,"%c",rw[i]);
                        }
                        else
                        {
                        }
                    }

                    fprintf(lb, " %s ", dmy);
                    fprintf(lb,"Returned\n");
                    fclose(lb);

                    //
    //n=0;

    lb=fopen("Archive.txt","r");
    ch=getc(lb);
   fclose(lb);
   lb=fopen("Archive.txt","r");
    while(ch!=EOF)
    {   ch=getc(lb);

        if(ch=='\n')
        {
            n++;

        }
    }
    //printf("n=%d\n",n);

    lb=fopen("Archive.txt","r");
    for(i=0;i<n;i++)
    {
        for(j=0;j<1;j++)
        {
            fscanf(lb," %[^\n]",&ar[i]);
        }

    }

    fclose(lb);
    for(i=1;i<n+1;i++)
    {
          for(j=2;j<n;j++)
          {
            if(strcmp(ar[j-1],ar[j])>0)
            {
                strcpy(temp,ar[j-1]);
                strcpy(ar[j-1],ar[j]);
                strcpy(ar[j],temp);
            }
          }
    }
    fclose(lb);
    lb=fopen("Archive.txt","w");
    fprintf(lb," ID     BC     DATE     Type   \n");
    for(i=1;i<n+1;i++)
    {
        sl=strlen(ar[i]);
        if(sl>5)
        {
            fprintf(lb,"%s\n",ar[i]);
        }
    }

    fclose(lb);

    //
                    printf("Successfully Book Returned\a\n");
                }
                else
                {
                    printf("This Book is Not Found");
                }
                goto ag;

        case 3:

            ag2:
           printf("\nCheck\n  1.Student Library History(By ID)\n  2.Book History(By Book Code)\n  3.Go Back\n  4.Exit\n");
           scanf("%d",&ch2);
           switch(ch2)
           {
               case 1:

                    n=0;
                    int cc=0;
                    nf=0;
                    printf("Please Enter ID: ");
                    scanf("%s",&id);
                    il=strlen(id);
                    lb=fopen("Archive.txt","r");
                    ch=getc(lb);
                    fclose(lb);
                    lb=fopen("Archive.txt","r");
                    while(ch!=EOF)
                    {   ch=getc(lb);



                        if(ch=='\n')
                        {
                            n++;

                        }
                    }
                    fclose(lb);
                    lb=fopen("Archive.txt","r");
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<1;j++)
                        {
                            fscanf(lb," %[^\n]",&ar[i]);
                        }

                    }

                    fclose(lb);
                    for(i=2;i<n;i++)
                    {

                        for(j=0;j<il;j++)
                        {
                            //printf("%c",ar[i][j]);
                            if(id[j]==ar[i][j])
                            {
                                cc++;

                            }
                        }

                        if(cc==il)
                        {
                            nf++;
                            if(nf==1)
                            {

                                printf(" ID     BC     DATE     Type   \n-------------------------------\n");

                            }
                            printf("%s\n",ar[i]);

                        }

                        cc=0;
                    }
                    if(nf==0)
                    {
                        printf("\nThis ID Holder Didn't Borrow any Book From BAIUST Library\n");
                    }
                    goto ag2;
                    break;
               case 2:
                    n=0;
                    cc=0;
                    nf=0;
                    int p;
                    printf("Please Enter Book Code: ");
                    scanf("%s",&bc);
                    bcl=strlen(bc);
                    lb=fopen("Archive.txt","r");
                    ch=getc(lb);
                    fclose(lb);
                    lb=fopen("Archive.txt","r");
                    while(ch!=EOF)
                    {   ch=getc(lb);



                        if(ch=='\n')
                        {
                            n++;

                        }
                    }
                    fclose(lb);
                    lb=fopen("Archive.txt","r");
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<1;j++)
                        {
                            fscanf(lb," %[^\n]",&ar[i]);
                        }

                    }

                    fclose(lb);
                    for(i=2;i<n;i++)
                    {
                        p=il+1;
                        for(j=0,p;j<bcl;j++,p++)
                        {

                           // printf("%c",ar[i][p]);

                            if(bc[j]==ar[i][p])
                            {
                                cc++;

                            }

                        }
                        //printf("\n");

                        if(cc==bcl)
                        {
                            nf++;
                            if(nf==1)
                            {

                                printf(" ID     BC     DATE     Type   \n-------------------------------\n");

                            }
                            printf("%s\n",ar[i]);

                        }

                        cc=0;
                    }
                    if(nf==0)
                    {
                        printf("\nThis Book Did't Borrow Anyone\n");
                    }
                    goto ag2;
                    break;
               case 3:
                goto ag;
                break;
               case 4:
                goto ex;
                break;
               default :
                  printf("Wrong input!!! \n");
                  goto ag2;
                  break;

            }
        case 4:
            ag5:
            printf("1.Day\n2.Month\n3.Year\n4.Go Back\n5.Exit\n");
            scanf("%d",&ch4);
            switch(ch4)
            {
            case 1:
                ag6:
                printf("1.This Day\n2.Specific Day\n3.Go Back\n4.Exit\n");
                scanf("%d",&ch5);
                switch(ch5)
                {
                case 1:
                    strcpy(sd,dmy);
                    sdl=strlen(sd);
                    goto ag4;
                    break;
                case 2:
                    ag3:
                    printf("Enter Date(mm/dd/yyyy) : ");
                    scanf("%s",&sd);
                    sdl=strlen(sd);
                    ag4:
                    lb=fopen("Archive.txt","r");
                    ch=getc(lb);
                    fclose(lb);
                     lb=fopen("Archive.txt","r");
                    while(ch!=EOF)
                    {   ch=getc(lb);



                        if(ch=='\n')
                        {
                            n++;

                        }
                    }
                    fclose(lb);
                    lb=fopen("Archive.txt","r");
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<1;j++)
                        {
                            fscanf(lb," %[^\n]",&ar[i]);
                        }

                    }

                    fclose(lb);

                   printf("\n1.Borrowed History \n2.Returned History \n3.All History \n4.Check Another Date History \n5.Go Back \n6.Exit\n");
                   scanf("%d",&ch3);
                   switch(ch3)
                   {
                       case 1:
                           if(ch5==2)
                           {
                               strcpy(fn,dmy2);
                               strcat(fn,sp);
                               strcat(fn,bw);
                               strcat(fn,fr);
                           }
                           else
                           {
                               strcpy(fn,bw);
                               strcat(fn,ts);
                               strcat(fn,fr);
                           }

                           du=fopen(fn,"w");
                           fprintf(du," ID     BC     DATE     Type   \n------------------------------\n");
                           fclose(du);
                           du=fopen(fn,"a+");
                           for(i=0;i<n;i++)
                           {
                               df=il+1+bcl+1;
                               ty=df+dl+1;
                               for(j=0,df;j<sdl;j++,df++)
                               {
                                   if(sd[j]==ar[i][df])
                                   {
                                       d1++;
                                   }
                               }
                               for(j=0,ty;j<bwl;j++,ty++)
                                {
                                    if(bw[j]==ar[i][ty])
                                    {
                                        t1++;
                                    }
                                }
                               if((d1==sdl)&&(t1==bwl))
                               {
                                   fprintf(du,"%s\n",ar[i]);
                                   nf++;
                               }
                               d1=0;
                               t1=0;


                           }
                           if(nf==0)
                            {
                                fprintf(du,"\t  Data Not Found !!!");
                                printf("   Data Not Found !!!");
                            }
                            else
                            {
                                printf("Successfully History File Created\n ");
                                printf("Please Open %s File.",fn);
                            }
                            nf=0;
                           fclose(du);
                           goto ag4;
                           break;
                       case 2:
                           if(ch5==2)
                           {
                               strcpy(fn,dmy2);
                               strcat(fn,sp);
                               strcat(fn,rt);
                               strcat(fn,fr);
                           }
                           else
                           {
                               strcpy(fn,bw);
                               strcat(fn,ts);
                               strcat(fn,fr);
                           }
                           du=fopen(fn,"w");
                           nf=0;
                           fprintf(du," ID     BC     DATE     Type   \n------------------------------\n");
                           fclose(du);
                           du=fopen(fn,"a+");
                           for(i=0;i<n;i++)
                           {
                               df=il+1+bcl+1;
                               ty=df+dl+1;
                               for(j=0,df;j<sdl;j++,df++)
                               {
                                   if(sd[j]==ar[i][df])
                                   {
                                       d1++;
                                   }
                               }
                               for(j=0,ty;j<rtl;j++,ty++)
                                {
                                    if(rt[j]==ar[i][ty])
                                    {
                                        t1++;
                                    }
                                }
                               if((d1==sdl)&&(t1==rtl))
                               {
                                   fprintf(du,"%s\n",ar[i]);
                                   nf++;
                               }
                               d1=0;
                               t1=0;


                           }
                           if(nf==0)
                            {
                                fprintf(du,"    Data Not Found !!!");
                                printf("   Data Not Found !!!");
                            }
                            else
                            {
                                printf("Successfully History File Created\n ");
                                printf("Please Open %s File.",fn);
                            }
                            nf=0;
                           fclose(du);
                           goto ag4;
                           break;
                       case 3:
                           if(ch5==2)
                           {
                               strcpy(fn,dmy2);
                               strcat(fn,sp);
                               strcat(fn,all);
                               strcat(fn,fr);
                           }
                           else
                           {
                                strcpy(fn,all);
                                strcat(fn,ts);
                                strcat(fn,fr);
                           }

                           du=fopen(fn,"w");
                           nf=0;
                           fprintf(du," ID     BC     DATE     Type   \n------------------------------\n");
                           fclose(du);
                           du=fopen(fn,"a+");
                           for(i=0;i<n;i++)
                           {
                               df=il+1+bcl+1;

                               for(j=0,df;j<sdl;j++,df++)
                               {
                                   if(sd[j]==ar[i][df])
                                   {
                                       d1++;
                                   }
                               }

                               if(d1==sdl)
                               {
                                   fprintf(du,"%s\n",ar[i]);
                                   nf++;
                               }
                               d1=0;
                               t1=0;


                           }
                           if(nf==0)
                            {
                                fprintf(du,"    Data Not Found !!!");
                                printf("   Data Not Found !!!");
                            }
                            else
                            {
                                printf("Successfully History File Created\n ");
                                printf("Please Open %s File.",fn);
                            }
                            nf=0;
                           fclose(du);
                           goto ag4;
                           break;
                       case 4:
                            goto ag3;
                            break;
                       case 5:
                           goto ag2;
                           break;
                       case 6:
                          goto ex;
                          break;
                       default :
                        printf("Wrong input!!! \n");
                        goto ag4;
                   }
                    goto ag6;
                    break;
                case 3:
                    goto ag5;
                    break;
                case 4:
                    goto ex;
                    break;
                default :
                    printf("Wrong Input !!!\n");
                    goto ag6;
                }
                break;
            case 2:
                ag7:
                printf("1.This Month\n2.Specific Month\n3.Go Back\n4.Exit\n");
                scanf("%d",&ch5);
                switch(ch5)
                {
                case 1:
                    goto ag7;
                    break;
                case 2:
                    goto ag7;
                    break;
                case 3:
                    goto ag5;
                    break;
                case 4:
                    goto ex;
                    break;
                default :
                    printf("Wrong Input !!!\n");
                    goto ag7;
                }
                break;
            case 3:
                ag8:
                printf("1.This Year\n2.Specific Year\n3.Go Back\n4.Exit\n");
                scanf("%d",&ch5);
                switch(ch5)
                {
                case 1:
                    goto ag8;
                    break;
                case 2:
                    goto ag8;
                    break;
                case 3:
                    goto ag5;
                    break;
                case 4:
                    goto ex;
                    break;
                default :
                    printf("Wrong Input !!!\n");
                    goto ag8;
                }
                break;
            case 4:
                break;
            case 5:
                break;

            }
        case 5:
            ex :
            printf("Thank You\n");
            break;
        default :
            printf("Wrong input!!!");
            goto ag;
    }

return 0;
}
