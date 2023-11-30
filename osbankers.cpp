#include<stdio.h>
int main()
{
	int np,nr,i,j,k,alloc[10][10],max[10][10],need[10][10],avail[5];
	int comp=0,iscomp[10],seq[10],idx=0,flag;
	printf("enter no of processes ");
	scanf("%d",&np);
	printf("enter no of resourses  ");
	scanf("%d",&nr);
	printf("enter allocation of processes\n");
	for(i=0;i<np;i++)
	{
		iscomp[i]=0;
		for(j=0;j<nr;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter max requirement of processes\n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("enter avail resourses\n");
	for(i=0;i<nr;i++)
	scanf("%d",&avail[i]);
	
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	
	while(comp<np)
	{
		for(i=0;i<np;i++)
		{
			if(iscomp[i]==0)
			{
				flag=0;
				for(j=0;j<nr;j++)
				{
					if(need[i][j]>avail[j])  // avail[j]  !  [][]
					{
						flag=1;
						break;
					}
		    	}
				if(flag==0)
				{
				seq[idx]=i;
				idx++;
				for(k=0;k<nr;k++)
				avail[k]=avail[k]+alloc[i][k];
				iscomp[i]=1;
				comp++;
				}
			}
	    }
	}
	
	flag=1;
	for(i=0;i<np;i++)
	{
		if(iscomp[i]==0)
		{
			flag=0;
			printf("system is not in safe state");
			break;
		}
	}
	if(flag==1)
	{
		printf("system is in safe state \n");
		for(i=0;i<np;i++)
		printf(" P%d  --> ",seq[i]);
		
	}
}


