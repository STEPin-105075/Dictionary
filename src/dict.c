#include "dict.h"

FILE *data;
struct lib {char word[20], mean[50];};
struct lib a[500];
int n=0;

void date()
{
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T);
  printf("\n\nDate:%02d/%02d/%04d & Time: %02d:%02d:%02d\n\n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour,tm.tm_min,tm.tm_sec);
}


void lookup()
{
	system("cls"); // to clear the screen
	int w=0;
	char s[20];
	do
	{
		printf("\n\nEnter the word (please make sure that the first letter is capitalised):");
		scanf("%s",s);
		data=fopen(point,"r");    // to open the file in read mode
		if(data==NULL)
		printf("No Such File Exists");
		else
		{
		    printf("\n%-15s\t%-15s\n","WORD","MEANING");
			while(fscanf(data,"%d",a[w].word) != EOF) //used %d instead of %s coz of invalid conversion from char to int
			{
				fscanf(data,"%s\t%[^\n]s", a[w].word, a[w].mean);
				if(strcmp(a[w].word,s)==0)
				{
					printf("\n%s %15s\n ",a[w].word, a[w].mean);
					w++;
				}
			}
		}
		fclose(data);
	}
	while(getchar()=='y');
}

void selectionpage()
{
    int choice;
    while(1)
        {

            printf("\n\n\n1.Search for a Word\n2.Exit from the application\n");
            printf("\n\nEnter your choice: ");
            scanf("%d",&choice);
            if(choice==1)
                lookup(); //to search a word
            else if(choice==2)
                exita(); //to exit from console
            else
                {
                    printf("Please Enter a valid input");
                    delay(1000);
                }
        }
}
int exita()
      {
       fflush(stdin);
       system("cls");
       printf("\nDo you really wish to exit?(y/n): ");
       while(getchar()=='y')
           exit(0);
       return 0;
      }

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
