#include <stdio.h>
#include <string.h>
#define MAX 256
  
  void split(){
   int i = 0, line = 0;
        FILE *fp1, *fp2, *fp3;
        char fl1[MAX], fl2[MAX], fl3[MAX], str[MAX];

              printf("Enter your input file name:");
        scanf("%s", fl1);

               sprintf(fl2, "%s_part_%d.txt", fl1, 1);
        sprintf(fl3, "%s_part_%d.txt", fl1, 2);
        strcat(fl1, ".txt");

              fp1 = fopen(fl1, "r");

        if (!fp1) {
                printf("Unable to open input file in read mode!!\n");
                return 0;
        }

           fp2 = fopen(fl2, "w");

              if (!fp2) {
                printf("Unable to open output file in write mode\n");
                fclose(fp1);
                return 0;
        }

              fp3 = fopen(fl3, "w");
        if (!fp3) {
                printf("Unable to open output file2 in write mode\n");
                fclose(fp1);
                fclose(fp2);
                return 0;
        }

            while (!feof(fp1)) {
                fgets(str, MAX, fp1);
                if (!feof(fp1))
                        line++;
        }

               rewind(fp1);

              while (i < line/2) {
                fgets(str, MAX, fp1);
                if (!feof(fp1)) {
                        fputs(str, fp2);
                }
                i++;
        }

              while (!feof(fp1)) {
                fgets(str, MAX, fp1);
                if (!feof(fp1)) {
                        fputs(str, fp3);
                }
        }

     
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);

   
        remove(fl1);
  }
  
  
  void merge(){
  
  FILE *fileold1, *fileold2, *filenew;
	char ch, fname1[20], fname2[20], fname3[30];

	printf("\n\n Merge two files and write it in a new file :\n");
	printf("-------------------------------------------------\n"); 	
	
	printf(" Input the 1st file name : ");
	scanf("%s",fname1);
	printf(" Input the 2nd file name : ");
	scanf("%s",fname2);
	printf(" Input the new file name where to merge the above two files : ");
	scanf("%s",fname3);
	fileold1=fopen(fname1, "r");
	fileold2=fopen(fname2, "r");
	if(fileold1==NULL || fileold2==NULL)
	{
		printf(" File does not exist or error in opening...!!\n");
		
	}
	filenew=fopen(fname3, "w");
	if(filenew==NULL)
	{
		printf(" File does not exist or error in opening...!!\n");
		
	}
	while((ch=fgetc(fileold1))!=EOF)
	{
		fputc(ch, filenew);
	}
	while((ch=fgetc(fileold2))!=EOF)
	{
		fputc(ch, filenew);
	}
	printf(" The two files merged into %s file successfully..!!\n\n", fname3);
	fclose(fileold1);
	fclose(fileold2);
	fclose(filenew);
  
  }
  
  
  
  int main()
  {
  
  
  int choice;
   printf("\n 1. Press 1 for split");
        printf("\n 2. Press 2 for merge");
        printf("\n Enter your choice");
     
        scanf("%d", &choice);
        
        
        switch(choice)
        {
            case 1:
                split();
                break;
            case 2:
                merge();
                break;
            default:
                printf("you have passed a wrong key");
                printf("\n press any key to continue");
        }      
        
    }   
