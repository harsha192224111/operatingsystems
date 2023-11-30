#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,np,nb,bsize[10],psize[10],alloc[10];
	int diff=0,idx,min;
	
	printf("enter no of processes ");
	scanf("%d",&np);
	printf("enter size of each process ");
	for(i=0;i<np;i++)
	scanf("%d",&psize[i]);
	
	printf("enter no of blocks ");
	scanf("%d",&nb);
	printf("enter size  of each blocks ");
	for(i=0;i<nb;i++)
	scanf("%d",&bsize[i]);
	
	for(i=0;i<np;i++)
	alloc[i]=-1;
	
	for(i=0;i<np;i++)
	{ 
    	idx=-1;
    	min=9999999;
		for(j=0;j<nb;j++)
		{
			if(bsize[j]>=psize[i])
			{
				diff=bsize[j]-psize[i];
				if(diff<min)
				{
					min=diff;
					idx=j;
					
				}
			}
		}
		alloc[i]=idx;  //allocating ith process to jth block
		bsize[idx]-=psize[i];
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
