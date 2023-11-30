#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int i=0,j=0,nf=0,ch;
	char dname[10],files[10][10],fname[10];
	printf("enter dictonary name  ");
	scanf("%s",&dname);
	do
	{
		printf("enter file name  ");
		scanf("%s",&fname);
		nf++;
		
		for(i=0;i<nf;i++)
		{
			if(strcmp(fname,files[i])==0)
			{
				printf("file already exist \n");
				nf--;
				break;
				
			}
		}
		
		if(nf==i)
		{
			strcpy(files[j],fname);
			j++;
		}
		printf("enter 1-cointunue 2-exit  ");
		scanf("%d",&ch);
	}while(ch==1);
	
	printf("dictonary name is %s",dname);
	printf("\n files present are \n");
	for(i=0;i<j;i++)
	printf("\n %s",files[i]);
}
