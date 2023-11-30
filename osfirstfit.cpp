#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,nb,np,bsize[10],psize[10],alloc[10];
	printf("enter no of blocks  ");
	scanf("%d",&nb);
	printf("enter the size of each block ");
	for(i=0;i<nb;i++)
	scanf("%d",&bsize[i]);
	
	
	printf("enter no of processes  ");
	scanf("%d",&np);
	printf("enter the size of each process ");
	for(i=0;i<np;i++)
	scanf("%d",&psize[i]);
	
	
	for(i=0;i<np;i++)
	alloc[i]=-1;
	
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(bsize[j]>=psize[i])   
			{
				alloc[i]=j;  //allocating ith process to jth block
				bsize[j]-=psize[i];
				break;
			}
		}
	}
	printf("P.NO \t PSIZE \t BLOCK.NO \n");
	for(i=0;i<np;i++)
	{
		printf("%d\t",i);
		printf("%d \t",psize[i]);
		if(alloc[i]!=-1)
		printf("%d",alloc[i]+1);
		else
		printf("NA");
		printf("\n");
	}
}
