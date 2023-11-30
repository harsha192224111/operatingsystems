#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp=NULL;
	char str[100];
	fp=fopen("randaccesfile.txt","r");
	 if (fp == NULL) {
        printf("Unable to open \n");
        exit(1);
    }
        printf("initial position of pointer  %d \n ",ftell(fp));
	fgets(str,5,fp);
    	printf("pos after reading 5 characters  %d \n ",ftell(fp));
	
	rewind(fp);
		printf("pos after using rewind %d \n ",ftell(fp));
	
	fseek(fp,10,SEEK_CUR);
		printf("pos after USING SEEK curr %d \n ",ftell(fp));
	
	fgets(str,7,fp);
	printf("%s\n",str);	
			printf("pos after reading 7 characters  %d \n ",ftell(fp));
			
	fseek(fp,10,SEEK_SET);
		printf("pos after USING SEEK SET  %d \n ",ftell(fp));
		
	fseek(fp,10,SEEK_END);
		printf("pos after USING SEEK end %d \n ",ftell(fp));			
			
			
			
}
