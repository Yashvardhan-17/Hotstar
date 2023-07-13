#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
//n is number of movies
int n=0;
//password for developer
char pas[3]="BVB";
//main structure which contains all details of all contents

struct hotstar
{
   struct date
   {
    int date;
    char month[100];
    int year;
   }dt;
   char name[100];
   char type[100];
   char genere[100];
   char language[100];
   char previlage[100];
   float rating;
   char status[100];
};
typedef struct hotstar hot;
hot a[100];
hot del[100];

void user()
{
    int j=0;
    FILE *fp;
    fp=fopen("hotstarlist.txt","r");
    while(!feof(fp))
    {
           fscanf(fp,"%s %s %s %s %s %d %s %d %f %s",a[j].name,a[j].type,a[j].genere,a[j].language,a[j].previlage,&a[j].dt.date,a[j].dt.month,&a[j].dt.year,&a[j].rating,a[j].status);
           j++;
           n++;
    }

    fclose(fp);
    return;
}

//structure used for operation on watch-later
struct watch_later
{
    char name[100];
    char type[100];
    int no;
    struct watch_later *next;
};
typedef struct watch_later *NODE;
hot w[100],s[100];
int r;


//structure used for operation on regarding to downloading free content
struct free_download_mode
{
    char name[100];
    char type[100];
};
typedef struct free_download_mode Q;
Q que[100];
hot t[100];
Q d[100];
int d1=0;
int front=-1;
int rear=-1;
int l=0;

//Functions to print all different patterns to let know that content has started to play
void triangular()
{

    printf("\n");

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return;
}

void inverted_triangular()
{

    printf("\n");

    // loop for line number of lines
    for(int i = n; i >= 1; i--)
    {
        // loop to print *
        for(int j = i; j >= 1; j--)
        {
            printf("* ");
        }

        printf("\n");
    }

    return;
}

void pyramid()
{

    printf("\n");

    // loop for line number of lines
    for(int i = 1; i <= n; i++)
    {
        // loop to print leading spaces in each line
        for(int space = 0; space <= n - i; space++)
        {
            printf("   ");
        }

        // loop to print *
        for(int j = 1; j <= i * 2 - 1; j++)
        {
            printf(" * ");
        }

        printf("\n");
    }

    return;
}

void inverted_pyramid()
{

    printf("\n");

    // loop for line number of lines
    for(int i = n; i >= 1; i--)
    {
        // loop to print leading spaces in each line
        for(int space = n-i; space >= 1; space--)
        {
            printf("   ");
        }

        // loop to print *
        for(int j = i * 2 - 1; j >= 1; j--)
        {
            printf(" * ");
        }

        printf("\n");
    }

    return;
}

void hollow_pyramid()
{


    printf("\n");

    // loop for line number of lines
    for(int i = 1; i <= n; i++)
    {
        // loop to print leading spaces in each line
        for(int space = 0; space <= n - i; space++)
        {
            printf("   ");
        }

        // loop to print *
        for(int j = 1; j <= i * 2 - 1; j++)
        {

            if (j == 1 || (j == i * 2 - 1) || i == n )
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }

        printf("\n");
    }

    return ;
}

void hollow_inverted_pyamid()
{
    printf("\n");

    // loop for line number of lines
    for (int i = 10; i >= 1; i--) {
        // loop to print leading spaces in each line
        for (int space = n - i; space >= 1; space--) {
            printf("   ");
        }

        // loop to print *
        for (int j = i * 2 - 1; j >= 1; j--)
        {
            if (j == 1 || (j == i * 2 - 1) || i == n)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }

        printf("\n");
    }

    return;
}

void diamond()
{
    printf("\n");

    // loop to print upper pyramid
    for(int i = 1; i <= 10; i++)
    {
        // loop to print leading spaces in each line
        for(int space = 0; space <= n - i; space++)
        {
            printf("   ");
        }

        // loop to print *
        for(int j = 1; j <= i * 2 - 1; j++)
        {
            printf(" * ");
        }

        printf("\n");
    }

    // loop to print lower pyramid
    for(int i = n+1; i >= 1; i--)
    {
        // loop to print leading spaces in each line
        for(int space = n-i; space >= 0; space--)
        {
            printf("   ");
        }

        // loop to print *
        for(int j = i * 2 - 1; j >= 1; j--)
        {
            printf(" * ");
        }

        printf("\n");
    }

    return;
}

//Function for developer for deleting the content from hot start i.e from main file
void delete_content()
{
    int j=0;
    FILE *ptr,*ptr1;
    ptr=fopen("hotstarlist.txt","r");
    if(ptr==NULL)
    {
        printf("Error Occured\n");
    }
    else
    {
        while(!feof(ptr))
            {
                fscanf(ptr,"%s %s %s %s %s %d %s %d %f %s",del[j].name,del[j].type,del[j].genere,del[j].language,del[j].previlage,&del[j].dt.date,del[j].dt.month,&del[j].dt.year,&del[j].rating,del[j].status);
                j++;
            }
            printf("value of j is %d\n",j);
            for(int x=0;x<j;x++)
            {
                printf("%d.%s %s %s %s %s %d %s %d %.2f %s\n",x+1,del[x].name,del[x].type,del[x].genere,del[x].language,del[x].previlage,del[x].dt.date,del[x].dt.month,del[x].dt.year,del[x].rating,del[x].status);
            }
            printf("Enter the correct number to delete : ");
            int ch,n=0;
            scanf("%d",&ch);
            if(ch==j)
            {
                strcpy(del[ch-1].name,"NULL");
                strcpy(del[ch-1].type,"NULL");
                strcpy(del[ch-1].genere,"NULL");
                strcpy(del[ch-1].language,"NULL");
                strcpy(del[ch-1].previlage,"NULL");
                del[ch-1].dt.date=0;
                strcpy(del[ch-1].dt.month,"NULL");
                del[ch-1].dt.year=0;
                del[ch-1].rating=0;
                strcpy(del[ch-1].status,"NULL");
                n=j-1;
            }
            else
            {
                for(ch;ch<j;ch++)
                {
                strcpy(del[ch-1].name,del[ch].name);
                strcpy(del[ch-1].type,del[ch].type);
                strcpy(del[ch-1].genere,del[ch].genere);
                strcpy(del[ch-1].language,del[ch].language);
                strcpy(del[ch-1].previlage,del[ch].previlage);
                del[ch-1].dt.date=del[ch].dt.date;
                strcpy(del[ch-1].dt.month,del[ch].dt.month);
                del[ch-1].dt.year=del[ch].dt.year;
                del[ch-1].rating=del[ch].rating;
                strcpy(del[ch-1].status,del[ch].status);
                }
                n=j-1;
            }

            printf("value of n is %d\n",n);
            for(int x=0;x<n;x++)
            {
                printf("%d.%s %s %s %s %s %d %s %d %.2f %s\n",x+1,del[x].name,del[x].type,del[x].genere,del[x].language,del[x].previlage,del[x].dt.date,del[x].dt.month,del[x].dt.year,del[x].rating,del[x].status);
            }
            fclose(ptr);

            ptr1=fopen("hotstarlist.txt","w");
            if(ptr1==NULL)
            {
                printf("Error occured while opening file\n");
            }
            else
            {
                    for(int x=0;x<n;x++)
                    {
                        fprintf(ptr,"%s %s %s %s %s %d %s %d %.2f %s",del[x].name,del[x].type,del[x].genere,del[x].language,del[x].previlage,del[x].dt.date,del[x].dt.month,del[x].dt.year,del[x].rating,del[x].status);
                        if(x==n-1)
                        {
                            x++;
                            break;
                        }
                        else
                        {
                        fprintf(ptr1,"\n");
                        }
                    }
                        printf("Process completed");
                        fclose(ptr);
            }
    }
}

//Function to indicate that content has started to play i.e by printing various patterns
void play_movie()
{
    triangular();
    inverted_triangular();
    pyramid();
    inverted_pyramid();
    hollow_pyramid();
    hollow_inverted_pyamid();
    diamond();
    return;
}

//Function to play content
void play()
{
    char str[100],name[100];
    int flag=0,m,i,j=0,rat;
    printf("enter content name you wanted to play\n");
    scanf("%s",str);
    FILE *fp;
    fp=fopen("hotstarlist.txt","r+");
    if(fp==NULL)
    {
        printf("file not existed\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",name);

        if(strcmp(str,name)==0)
        {
            flag=1;
            play_movie();
            PlaySound(TEXT("music.wav"),NULL,SND_SYNC);
            printf("Directed by ROBERT B.WEIDE \n");
            printf("Executive producer LARRY DAVID\n");
            printf("THANK YOU\n");
        }
    }
    if(flag==0)
    {
       printf("movie not present in the hotstar\nThank you\n");
    }
    for(int j=0;j<n;j++)
    {
       if(strcmp(str,a[j].name)==0)
       {
          strcpy(a[j].status,"viewed");
          printf("\nPlease give rating");
          scanf("%d",&rat);
          if(rat>=0 && rat<=5)
          {
              a[j].rating=rat;
          }
       }
    }
   fclose(fp);
 }

//Function to search the content
void search_movie()
{
    char str[100],name[100];
    int flag=0,m,n,i=0,p,q;
    hot can[200];
    printf("enter content name you are searching for\n");
    scanf("%s",str);
    printf("\nAre you searching for the any of the content given below\n");
    FILE *fp;
    fp=fopen("hotstarlist.txt","r+");
    if(fp==NULL)
    {
        printf("file not existed\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %d %s %d %f %s",can[i].name,can[i].type,can[i].genere,can[i].language,can[i].previlage,&can[i].dt.date,can[i].dt.month,&can[i].dt.year,&can[i].rating,can[i].status);
        n=strlen(can[i].name);
        m=strlen(str);
        for(int j=0;j<=(n-m);j++)
        {
            p=0;
            while(p<m && str[p]==can[i].name[j+p])
            {
                p=p+1;
                if(p==m)
                {
                    flag=1;
                    printf("%s\n",can[i].name);
                }
            }
        }
        i++;
   }
    if(flag==0)
    {
       printf("Content not found in the hotstar\nThank you\n");
    }
    printf("To play content press 1\n");
    printf("To continue press any key");
    scanf("%d",&q);
    if(q==1)
    {
        play();
    }

}

//Function to know which content have watched and not watched
void viewed_nonviewed()
{
    int p,flag=0;

    printf("Enter 1 to know viewed movies, 2 to view non viewed movies\n");
    scanf("%d",&p);
    if(p==1)
    {
        for(int i=0;i<n;i++)
        {
            if(strcmp(a[i].status,"viewed")==0)
            {
                printf("%s\t%s\n",a[i].name,a[i].status);
                flag=1;
            }

        }
        if(flag==0)
        {
            printf("\nOOho!! you have not watched any content");
        }
    }
    else if(p==2)
    {
       for(int j=0;j<n;j++)
        {
            if(strcmp(a[j].status,"notviewed")==0)
            {
                printf("%s\t%s\n",a[j].name,a[j].status);
            }
        }
        printf("For what are you waiting,Enjoy watching contents,For more content stay tuned \n");
    }
    else
    {
        printf("Invalid input , Please try different option\n");
    }

}

//Function to display all subscripted content
void subscription()
{
     int i=0;
    printf("Available subscripted content list is :\n");
        for(int i=0;i<n;i++)
        {
            if(strcmp(a[i].previlage,"free")==0)
            {
                printf("%s\n",a[i].name);
            }
        }
}

//Function to display all unsubscripted content to make it subscripted if want
void unsubscripted()
{
    int p;
    printf("List of Un-subscripted content is as below:\n");
    for(int i=0;i<n;i++)
        {
            if(strcmp(a[i].previlage,"premium")==0)
            {
                printf("%s %s\n",a[i].name,a[i].type);
            }
        }
    printf("To unlock premium get the subscription for 1000/-\n");
    printf("To unlock press 1 and complete the transction\n");
    printf("To watch nonprime content press any other key\n");
    scanf("%d",&p);
    if(p==1)
    {
        for(int i=0;i<n;i++)
        {
            if(strcmp(a[i].previlage,"premium")==0)
            {
               strcpy(a[i].previlage,"free");
            }
        }
        printf("YAAYYY!!you have unlocked the subscription.Now you can enoy any content without INTERUPTION!!\n");
    }

}

//Function for developer to insert movie in hotstar i.e main file
void insert_movie()
{
    int ch;
    hot x[100];
    printf("enter 1 for user and 2 for developer\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("you are not allowed to insert \nthank you\n");
        insert_movie();
    }
    else
        {
           char str[100];
           int i=0;
            printf("enter the password\n");
            scanf("%s",str);
            if((strcmp(pas,str))==0)
               {
                  int i,n;
                   printf("enter number of movies u want to insert\n");
                   scanf("%d",&n);
                   FILE *FP;
                   FP=fopen("hotstarlist.txt","a");
                   printf("enter the movie details to insert it:\nname\ttype\tgenre\tlanguage\tprevilage\tdate\tmonth\tyear\trating\tstatus:\n");
                   for(i=0;i<n;i++)
                   {
                   scanf("%s%s%s%s%s%d%s%d%f%s",x[i].name,x[i].type,x[i].genere,x[i].language,x[i].previlage,&x[i].dt.date,x[i].dt.month,&x[i].dt.year,&x[i].rating,x[i].status);
                   fprintf(FP,"\n%s %s %s %s %s %d %s %d %0.2f %s",x[i].name,x[i].type,x[i].genere,x[i].language,x[i].previlage,x[i].dt.date,x[i].dt.month,x[i].dt.year,x[i].rating,x[i].status);
                   if(n>1 && i<n-1)
                    printf("enter next movie details\n");
                   }
                    fclose(FP);
                    printf("\nmovie inserted successfully\n");
                    return;
               }
                else
                  printf("incorrect password\n");
         }
}

//Function to sort all content based on language using selection sort algorithm
void sort_language()
{
    hot can[100];
    char t_name[100],t_lang[100];
    int i;
    FILE *ptr;
    ptr = fopen("hotstarlist.txt","r");
                if(ptr==NULL)
                {
                    printf("Error occured while opening file\n");
                    exit(0);
                }
    while(!feof(ptr))
        {
            fscanf(ptr,"%s %s %s %s %s %d %s %d %f %s",can[i].name,can[i].type,can[i].genere,can[i].language,can[i].previlage,&can[i].dt.date,can[i].dt.month,&can[i].dt.year,&can[i].rating,can[i].status);
            i++;
        }
        int y=i-1,min;
        for(i=0;i<=y-2;i++)
        {
            min=i;
            for(int j=i+1;j<=y-1;j++)
            {
                if(strcmp(can[j].language,can[min].language)>0)
                {
                    min=j;
                }
            }
            strcpy(t_name,can[i].name);
            strcpy(t_lang,can[i].language);
            strcpy(can[i].name,can[min].name);
            strcpy(can[i].language,can[min].language);
            strcpy(can[min].name,t_name);
            strcpy(can[min].language,t_lang);
        }
        printf("List of sorted content based on Language is/are:\n");
        for(int k=0;k<=y;k++)
        {
            printf("%s---->%s\n",can[k].name,can[k].language);
        }
        fclose(ptr);
}

//Function to recommend cartoons based on genere by using bubble sort algorithm
void recommend_cartoon_by_genere(hot can[100],char gen[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"cartoon")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].genere,can[k].genere);
            ++l;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        int flag=0;
        printf("Cartoons based on %s genere is/are\n",gen);
        for(int i=0;i<l;i++)
    {
        if(strcmp(tem[i].genere,gen)==0)
        {
            printf("%s\n",tem[i].name);
            flag++;
        }
    }
        if(flag==0)
        {
            printf("Opps!!You have entered something wrong..Try Again\n");
        }
    }
}

//Function to recommend cartoons based on language by using bubble sort algorithm
void recommend_cartoon_by_language(hot can[100],char lan[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"cartoon")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].language,can[k].language);
            ++l;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        int flag=0;
        printf("Cartoons based on %s language is/are\n",lan);
        for(int i=0;i<l;i++)
            {
                if(strcmp(tem[i].language,lan)==0)
                    {
                        printf("%s\n",tem[i].name);
                        flag++;
                    }
            }
            if(flag==0)
                {
                    printf("Opps!!You have entered something wrong..Try Again\n");
                }
    }
}

//Function to recommend cartoons based on ratings by using bubble sort algorithm
void bubble_sort_rating_cartoon(hot can[100],int n)
{
    int l=0,i=0;
    char t_name[100];
    hot tem[100];
    float rat;
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"cartoon")==0)
        {
            strcpy(tem[l].name,can[k].name);
            tem[l].rating = can[k].rating;
            l++;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        for(int i=0;i<=l-2;i++)
    {
        for(int j=0;j<=l-2-i;j++)
        {
            if(tem[j+1].rating>=tem[j].rating)
            {
                rat=tem[j+1].rating;
                strcpy(t_name,tem[j+1].name);
                tem[j+1].rating=tem[j].rating;
                strcpy(tem[j+1].name,tem[j].name);
                strcpy(tem[j].name,t_name);
                tem[j].rating=rat;
            }
        }
    }
     printf("Cartoons based on ratings are :\n");

                      for(int t=0;t<l;t++)
                      {
                          printf("%s %.2f\n",tem[t].name,tem[t].rating);
                      }
    }
}

//Function to recommend sports based on ratings by using bubble sort algorithm
void bubble_sort_rating_sports(hot can[100],int n)
{
    int l=0,i=0;
    char t_name[100];
    hot tem[100];
    float rat;
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"sports")==0)
        {
            strcpy(tem[l].name,can[k].name);
            tem[l].rating = can[k].rating;
            l++;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        for(int i=0;i<=l-2;i++)
    {
        for(int j=0;j<=l-2-i;j++)
        {
            if(tem[j+1].rating>=tem[j].rating)
            {
                rat=tem[j+1].rating;
                strcpy(t_name,tem[j+1].name);
                tem[j+1].rating=tem[j].rating;
                strcpy(tem[j+1].name,tem[j].name);
                strcpy(tem[j].name,t_name);
                tem[j].rating=rat;
            }
        }
    }
     printf("Sports based on ratings are :\n");

                      for(int t=0;t<l;t++)
                      {
                          printf("%s %.2f\n",tem[t].name,tem[t].rating);
                      }
    }
}

//Function to recommend TV-Shows based on genere by using bubble sort algorithm
void recommend_show_by_genere(hot can[100],char gen[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"show")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].genere,can[k].genere);
            ++l;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        int flag=0;
    printf("TV-Shows based on %s genere is/are\n",gen);

    for(int i=0;i<l;i++)
    {
        if(strcmp(tem[i].genere,gen)==0)
        {
            printf("%s\n",tem[i].name);
            flag++;
        }
    }
    if(flag==0)
    {
        printf("Opps!!You have entered something wrong..Try Again\n");
    }
    }
}

//Function to recommend TV-Shows based on language by using bubble sort algorithm
void recommend_show_by_language(hot can[100],char lan[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"show")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].language,can[k].language);
            ++l;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        int flag=0;
    printf("TV-Shows based on %s language is/are\n",lan);
    for(int i=0;i<l;i++)
    {
        if(strcmp(tem[i].language,lan)==0)
        {
            printf("%s\n",tem[i].name);
            flag++;
        }
    }
    if(flag==0)
    {
        printf("Opps!!You have entered something wrong..Try Again\n");
    }
    }
}

//Function to recommend TV-Shows based on ratings by using bubble sort algorithm
void bubble_sort_rating_show(hot can[100] , int n)
{
    int l=0,i=0;
    char t_name[100];
    hot tem[100];
    float rat;
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"show")==0)
        {
            strcpy(tem[l].name,can[k].name);
            tem[l].rating = can[k].rating;
            l++;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        for(int i=0;i<=l-2;i++)
    {
        for(int j=0;j<=l-2-i;j++)
        {
            if(tem[j+1].rating>=tem[j].rating)
            {
                rat=tem[j+1].rating;
                strcpy(t_name,tem[j+1].name);
                tem[j+1].rating=tem[j].rating;
                strcpy(tem[j+1].name,tem[j].name);
                strcpy(tem[j].name,t_name);
                tem[j].rating=rat;
            }
        }
    }
     printf("TV-Shows based on ratings are :\n");

                      for(int t=0;t<l;t++)
                      {
                          printf("%s %.2f\n",tem[t].name,tem[t].rating);
                      }
    }
}

//Function to recommend Web Series based on genere by using bubble sort algorithm
void recommend_web_by_genere(hot can[100],char gen[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"series")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].genere,can[k].genere);
            ++l;
        }
    }
    int flag=0;
    printf("Web-Series based on %s genere is/are\n",gen);
    for(int i=0;i<l;i++)
    {
        if(strcmp(tem[i].genere,gen)==0)
        {
            printf("%s\n",tem[i].name);
            flag++;
        }
    }
    if(flag==0)
    {
        printf("Opps!!You have entered something wrong..Try Again\n");
    }
}

//Function to recommend Web Series based on language by using bubble sort algorithm
void recommend_web_by_language(hot can[100],char lan[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"series")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].language,can[k].language);
            ++l;
        }
    }
    if(l==0)
    {
        printf("No Series to show\n");
    }
    else
    {
        int flag=0;
        printf("Web-Series based on %s language is/are\n",lan);
        for(int i=0;i<l;i++)
            {
                if(strcmp(tem[i].language,lan)==0)
                    {
                        printf("%s\n",tem[i].name);
                        flag++;
                    }
            }
        if(flag==0)
    {
        printf("Opps!!You have entered something wrong..Try Again\n");
    }
    }

}

//Function to recommend Web Series based on ratings by using bubble sort algorithm
void bubble_sort_rating_web(hot can[100] , int n)
{
    int l=0,i=0;
    char t_name[100];
    hot tem[100];
    float rat;
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"series")==0)
        {
            strcpy(tem[l].name,can[k].name);
            tem[l].rating = can[k].rating;
            l++;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        for(int i=0;i<=l-2;i++)
    {
        for(int j=0;j<=l-2-i;j++)
        {
            if(tem[j+1].rating>=tem[j].rating)
            {
                rat=tem[j+1].rating;
                strcpy(t_name,tem[j+1].name);
                tem[j+1].rating=tem[j].rating;
                strcpy(tem[j+1].name,tem[j].name);
                strcpy(tem[j].name,t_name);
                tem[j].rating=rat;
            }
        }
    }
     printf("Web-Series based on ratings are :\n");

                      for(int t=0;t<l;t++)
                      {
                          printf("%s %.2f\n",tem[t].name,tem[t].rating);
                      }
    }
}

//Function to recommend Movies based on ratings by using bubble sort algorithm
void bubble_sort_rating_movie(hot can[100],int n)
{
    int l=0,i=0;
    char t_name[100];
    hot tem[100];
    float rat;
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"movie")==0)
        {
            strcpy(tem[l].name,can[k].name);
            tem[l].rating = can[k].rating;
            l++;
        }
    }
    for(int i=0;i<=l-2;i++)
    {
        for(int j=0;j<=l-2-i;j++)
        {
            if(tem[j+1].rating>=tem[j].rating)
            {
                rat=tem[j+1].rating;
                strcpy(t_name,tem[j+1].name);
                tem[j+1].rating=tem[j].rating;
                strcpy(tem[j+1].name,tem[j].name);
                strcpy(tem[j].name,t_name);
                tem[j].rating=rat;
            }
        }
    }
     printf("Movies based on ratings are :\n");

                      for(int t=0;t<l;t++)
                      {
                          printf("%s %.2f\n",tem[t].name,tem[t].rating);
                      }
}

//Function to recommend Movies based on language by using bubble sort algorithm
void recommend_movie_by_language(hot can[100],char lan[100],int n)
{
    int l=0;
    hot tem[100];

    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"movie")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].language,can[k].language);
            ++l;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        int flag=0;
    printf("Movies based on %s language is/are\n",lan);
    for(int i=0;i<l;i++)
    {
        if(strcmp(tem[i].language,lan)==0)
        {
            printf("%s\n",tem[i].name);
            flag++;
        }
    }
        if(flag==0)
    {
        printf("Opps!!You have entered something wrong..Try Again\n");
    }
    }

}

//Function to recommend Movies based on genere by using bubble sort algorithm
void recommend_movie_by_genere(hot can[100],char gen[100],int n)
{
    int l=0;
    hot tem[100];
    for(int k=0;k<=n;k++)
    {
        if(strcmp(can[k].type,"movie")==0)
        {
            strcpy(tem[l].name,can[k].name);
            strcpy(tem[l].genere,can[k].genere);
            ++l;
        }
    }
    if(l==0)
    {
        printf("Sorry but nothing to show, please try other options");
    }
    else
    {
        int flag=0;
    printf("Movies based on %s genere is/are\n",gen);
    for(int i=0;i<l;i++)
    {
        if(strcmp(tem[i].genere,gen)==0)
        {
            printf("%s\n",tem[i].name);
            flag++;
        }
    }
    if(flag==0)
    {
        printf("Opps!!You have entered something wrong..Try Again\n");
    }
    }
}

//Function to recommend contents based on users selection
void recomended_video()
{
    int i=0,n;
    hot can[100];
    int choice1,cm,cs,cc;
    FILE *ptr;
    ptr = fopen("hotstarlist.txt","r");
                if(ptr==NULL)
                {
                    printf("Error occured while opening file\n");
                    exit(0);
                }
    while(!feof(ptr))
        {
            fscanf(ptr,"%s %s %s %s %s %d %s %d %f %s",can[i].name,can[i].type,can[i].genere,can[i].language,can[i].previlage,&can[i].dt.date,can[i].dt.month,&can[i].dt.year,&can[i].rating,can[i].status);
            i++;
        }

    printf("Enter the category\n1: Movie\n2: Web-Series\n3: TV Shows\n4: Sports\n5:Cartoons(For Kids)\n");
    scanf("%d",&choice1);

    switch(choice1)
    {
    case 1 :

             printf("Enter\n1: To recommend based on ratings\n2: To recommend based on language\n3: To recommend based on genere\n");
             scanf("%d",&cm);
             switch(cm)
                   {
                      case 1 :bubble_sort_rating_movie(can,i-1);
                      break;

                      case 2 : printf("Enter the language\n");
                               char lan[100];
                               scanf("%s",lan);
                               recommend_movie_by_language(can,lan,i-1);
                      break;

                      case 3 :  printf("Enter the genere\n");
                                char gen[100];
                                scanf("%s",gen);
                                recommend_movie_by_genere(can,gen,i-1);
                      break;
                    }
    break;

    case 2 :
             printf("Enter\n1: To recommend based on ratings\n2: To recommend based on language\n3: To recommend based on genere\n");
             int cw;
             printf("Please Enter your choice: ");
             scanf("%d",&cw);
             switch(cw)
             {
                 case 1 :bubble_sort_rating_web(can,i-1);
                 break;

                 case 2 : printf("Enter the language\n");
                               char lan[100];
                               scanf("%s",lan);
                               recommend_web_by_language(can,lan,i-1);
                 break;

                 case 3 : printf("Enter the genere\n");
                            char gen[100];
                            scanf("%s",gen);
                            recommend_web_by_genere(can,gen,i-1);
                 break;
             }
      break;

     case 3 :
            printf("Enter\n1: To recommend based on ratings\n2: To recommend based on language\n3: To recommend based on genere\n");
            scanf("%d",&cs);
            switch(cs)
            {
                case 1 :bubble_sort_rating_show(can,i-1);
                break;

                case 2 : printf("Enter the language\n");
                           char lan[100];
                           scanf("%s",lan);
                           recommend_show_by_language(can,lan,i-1);
                break;

                case 3 : printf("Enter the genere\n");
                            char gen[100];
                            scanf("%s",gen);
                            recommend_show_by_genere(can,gen,i-1);
                break;
            }
     break;

     case 4: bubble_sort_rating_sports(can,i-1);
     break;

     case 5:
            printf("Enter\n1: To recommend based on ratings\n2: To recommend based on language\n3: To recommend based on genere\n");
            scanf("%d",&cc);
            switch(cc)
            {
                case 1 :bubble_sort_rating_cartoon(can,i-1);
                break;

                case 2 :printf("Enter the language\n");
                           char lan[100];
                           scanf("%s",lan);
                           recommend_cartoon_by_language(can,lan,i-1);
                break;

                case 3 : printf("Enter the genere\n");
                            char gen[100];
                            scanf("%s",gen);
                            recommend_cartoon_by_genere(can,gen,i-1);
                break;
            }
     break;
        }
        fclose(ptr);
}

//Function to create NODE
NODE create_node(NODE head, hot can[100], int choice)
{
    NODE ptr;
    ptr=(NODE)malloc (sizeof(struct watch_later));
    if(ptr==NULL)
    {
        printf("Error while allocating memory\n");
        return 0;
    }
    if(head==NULL)
    {
        for(int k=0;k<=choice;k++)
        {
            if(k==choice-1)
            {
                strcpy(ptr->name,can[k].name);
                strcpy(ptr->type,can[k].type);
                ptr->no= choice;
                printf("%d. %s added to 'WATCH-LATER' list",ptr->no,ptr->name);
            }
        }
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        NODE tem=head;
        while(tem->next !=NULL)
        {
            tem=tem->next;
        }
        for(int k=0;k<=choice;k++)
        {
            if(k==choice-1)
            {
                strcpy(ptr->name,can[k].name);
                strcpy(ptr->type,can[k].type);
                ptr->no= choice;
                printf("%d. %s added to 'WATCH-LATER' list",ptr->no,ptr->name);
            }
        }
        ptr->next = NULL;
        tem->next = ptr;
    }
    return head;
}

//Function to display contents present in watch Later list
void display(NODE head)
{
    if(head==NULL)
    {
        printf("Nothing to show in 'WATCH-LATER' list\n");
    }
    else
    {
        NODE tem = head;
    printf("The content in 'WATCH-LATER' list is/are :\n");
    while(tem!=NULL)
    {
        printf("%s\n",tem->name);
        tem = tem->next;
    }
    }
}

//To remove content from structure because that particular content is added to watch later list
int remove_content(int choice,hot w[100],int i)

{
    for(int k=choice-1;k<i;k++)
    {
        strcpy(w[k].name , w[k+1].name);
    }
    return i-1;
}

//Function to create watch later list
NODE watch_later(NODE head)
{
    int i=0,choice,n=1;

    FILE *ptr;
    ptr = fopen("hotstarlist.txt","r");
                if(ptr==NULL)
                {
                    printf("Error occured while opening file\n");
                    exit(0);
                }
                if(head==NULL)
                {
                    while(!feof(ptr))
                        {
                            fscanf(ptr,"%s %s %s %s %s %d %s %d %f %s",w[i].name,w[i].type,w[i].genere,w[i].language,w[i].previlage,&w[i].dt.date,w[i].dt.month,&w[i].dt.year,&w[i].rating,w[i].status);
                            i++;
                            r=i;
                        }
                        printf("List of all Entertainment show is as below :\n");
                        for(int k=0;k<i;k++)
                        {
                            printf("%d.%s----> %s\n",k+1,w[k].name,w[k].type);
                        }
                }

        if(head==NULL)
        {
            printf("Press the respective number to save for 'WATCH-LATER'\n");
            scanf("%d",&choice);
            if(choice>r)
            {
                printf("Invalid Number , try again\n");
            }
            else
            {
                head=create_node(head,w,choice);
                r=remove_content(choice,w,r);
            }
        }
        {
            while(n==1)
            {
                printf("\nEnter 1: to add content into 'WATCH-LATER' list\nEnter 2: to display the WATCH LIST\nENTER 3: to exit WATCH LIST\n");
                int ch1,ch2;
                scanf("%d",&ch1);
                switch(ch1)
                {
                case 1 :printf("List of all content is as below\n");
                    for(int t=0;t<r;t++)
                    {
                        printf("%d.%s--->%s\n",t+1,w[t].name,w[t].type);
                    }
                    printf("Enter respective number\n");
                    scanf("%d",&ch2);
                    if(ch2>r)
                    {
                        printf("Invalid Number , try again\n");
                        continue;
                    }
                    NODE ptr = head;
                    head = create_node(head,w,ch2);
                    r=remove_content(ch2,w,r);
                break;

                case 2 :display(head);
                break;

                case 3 : n++;
                break;
                }
            }
        }
        return head;
}

//Function to add content again back to structure after deleting from watch later list
void re_add(NODE tem)
{
    strcpy(w[r].name,tem->name);
    strcpy(w[r].type,tem->type);
    r++;
}

//Function to remove content from watch later list
NODE remove_from_watch_list(NODE head)
{
    if(head==NULL)
    {
        printf("Nothing is there in 'Watch-LATER List'\n");
    }
    else
    {
        int i=1,k,choice;
        printf("Select respective number to remove from 'WATCH-LATER List'\n");
        NODE tem =head,pre;
        while(tem!=NULL)
        {
            printf("%d.%s\n",i,tem->name);
            tem=tem->next;
            i++;
        }
        tem = head;
        scanf("%d",&choice);
        for(k=1;k<choice;++k)
        {
            pre = tem;
            tem=tem->next;
        }
        if(k==1)
        {
            re_add(tem);
            head=head->next;
            printf("%s is removed from WATCH-LATER List\n",tem->name);
            free(tem);
        }
        else
        {
            re_add(tem);
            pre->next=tem->next;
            printf("%s is removed from WATCH-LATER List\n",tem->name);
            free(tem);
        }
    }
    return head;
}

//Function to display contents in Watch Later list
void display_watchlist(NODE head)
{
    if(head==NULL)
    {
        printf("Nothing to display in WATCH-LATER List. Please Add some content\n");
    }
    else
    {
        NODE tem=head;
        while(tem!=NULL)
        {
            printf("%s\n",tem->name);
            tem=tem->next;
        }
    }
}

//Function to remove content from download list
void remove_from_download_list(int c)
{
    for(c;c<l;c++)
    {
        strcpy(t[c].name,t[c+1].name);
    }
    l--;
}

//Function to select content which want to store in download list
void free_download_mode()
{
    int tem;
    hot can[100];
    FILE *fp;
    fp=fopen("hotstarlist.txt","r");
    if(fp==NULL)
    {
        printf("Error occured while opening App\n");
    }
    else
    {
        int j=0,k=0,p;
        while(!feof(fp))
    {
           fscanf(fp,"%s %s %s %s %s %d %s %d %f %s",can[j].name,can[j].type,can[j].genere,can[j].language,can[j].previlage,&can[j].dt.date,can[j].dt.month,&can[j].dt.year,&can[j].rating,can[j].status);
           j++;
    }
    printf("Free-Downlaod-Mode: It lets you to download any content FREELY only on Wi-Fi having previlage 'Free'.So Enjoy the Mode\n");

    for(int i=0;i<j;i++)
    {
        if(strcmp(can[i].previlage,"free"))
        {
            strcpy(t[l].name,can[i].name);
            strcpy(t[l].type,can[i].type);
            l++;
        }
    }
    while(tem==0)
    {
        printf("Enter\n1.To add the content for downloading\n2.To, go back\n");
        printf("Enter your choice:");
        int ch;
        scanf("%d",&ch);
        switch(ch)
            {
                case 1: if(l==0)
                        {
                            printf("Sorry,No Free content Available\n");
                            tem++;
                        }
                        else
                        {
                            printf("Select your choice for movie :\n");
                        p=0;
                        for(int k=0;k<l;k++)
                        {
                            p++;
                            printf("%d.%s---->%s\n",p,t[k].name,t[k].type);
                        }
                        int c;
                        scanf("%d",&c);
                        if(c>p)
                        {
                            printf("Wrong option ,Please Try Again\n");
                        }
                        else
                        {
                            if(front==-1)
                            {
                                front++;
                                rear++;
                                strcpy(que[rear].name,t[c-1].name);
                                printf("%s added for Downloading\n",que[rear].name,rear);
                                remove_from_download_list(c-1);
                            }
                            else
                            {
                                rear++;
                                strcpy(que[rear].name,t[c-1].name);
                                printf("%s added for Downloading\n",que[rear].name,rear);
                                remove_from_download_list(c-1);
                            }
                        }
                        break;

                        case 2:tem++;
                        break;
                        }
            }
    }
    }
    fclose(fp);
}

//Function to display contents which have already downloaded
void display_download_list()
{
    if(rear==-1)
    {
        printf("Yet NO content is added to Download List\n");
    }
    else
    {
        printf("Content in Download list is/are\n");
        for(int g=0;g<=rear;g++)
            {
        printf("%s\n",que[g].name);
            }
    }
}

//Function to download content present in download list
void download()
{
    int tem=1;
    if(front==-1)
    {
        printf("Nothing to Download\n");
    }
    else
    {
        while(tem==1)
        {
            printf("Enter\n1:For Downloading Content\n2:To view download content list\n3:To, go back\n");
            int ch;
            scanf("%d",&ch);

            switch(ch)
                {
                    case 1:
                            if(front==-1 || front>rear)
                            {
                                printf("No content to Download\n");
                                tem++;
                            }
                            else
                            {
                                printf("%s Downloaded!!Now You can enjoy it in offline mode!!\n",que[front].name);
                                strcpy(d[d1].name,que[front].name);
                                ++d1;
                                front++;
                            }

                    break;

                    case 2:
                            if(d1==0)
                            {
                                printf("Nothing is downloaded yet\n");
                            }
                            else
                            {
                                for(int u=0;u<d1;u++)
                                    {
                                        printf("%s is already downloaded\n",d[u].name);
                                    }
                            }
                    break;

                    case 3 : tem++;
                    break;
        }
        }

    }
}

//Function to display all contents details from hotstar i.e from list
void display_content()
{
    hot tem[100];
    printf("List of all contents is as below\n");
    FILE *ptr;
    ptr=fopen("hotstarlist.txt","r");

    if(ptr==NULL)
    {
        printf("Error occured while opening App\n");
    }
    else
    {
        int j=0,k=0,p;
        while(!feof(ptr))
    {
           fscanf(ptr,"%s %s %s %s %s %d %s %d %f %s",tem[j].name,tem[j].type,tem[j].genere,tem[j].language,tem[j].previlage,&tem[j].dt.date,tem[j].dt.month,&tem[j].dt.year,&tem[j].rating,tem[j].status);
           j++;
    }
        for(int h=0;h<j;h++)
        {
            printf("%s %s %s %s %s %d %s %d %.2f\n",tem[h].name,tem[h].type,tem[h].genere,tem[h].language,tem[h].previlage,tem[h].dt.date,tem[h].dt.month,tem[h].dt.year,tem[h].rating);
        }

    }
        fclose(ptr);
}

int main()
{
    NODE head = NULL;
    int choice;
    user();

    printf("**WELCOME TO HOT-STAR**\n");

    while(1)
    {
        printf("Enter:");
        printf("\n 1-To search the movie\n 4-To Recommend videos\n 5-To Sort based on languages\n 6-Viewed and non-viewed movies\n");
        printf(" 7-For subscripted contents\n 8-For unsubscripted content \n 9-To add content in Watch-Later list \n 10-To remove content from WATCH-LIST\n 11-To display WATCH-LIST\n 12-To choose 'Free' content for downloading\n 13-Display Download List\n 14-To Download Content\n");
        printf(" 15-To see all content information\n 16-To exit\n");
        printf("Please Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
           case 1:search_movie();
                   break;
           case 2:insert_movie();
                   break;
           case 3:delete_content();
                   break;
           case 4:recomended_video();
                   break;
           case 5:sort_language();
                    break;
           case 6:viewed_nonviewed();
                    break;
            case 7:subscription();
                    break;
            case 8:unsubscripted();
                    break;
            case 9: head=watch_later(head);
                    break;
            case 10: head=remove_from_watch_list(head);
                    break;
            case 11: display_watchlist(head);
                    break;
            case 12: free_download_mode();
                    break;
            case 13:display_download_list();
                    break;
            case 14:download();
                    break;
            case 15: display_content();
                    break;
            case 16:exit(0);
                     break;
            default : printf("Wrong option,Try again!!\n");
            continue;
        }
    }
}
