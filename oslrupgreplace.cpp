#include<stdio.h>
#include<conio.h>

int checkhit(int rfstr, int fr[], int occupied)
{
	for(int i=0;i<occupied;i++)
	{	
	if(rfstr==fr[i])
	return 1;
    }
	return 0;
}

void print(int fr[], int occupied)
{
	for(int i=0;i<occupied;i++)
	printf("%d  \t",fr[i]);
}

int main()
{
	int i,j,k,rfstr[20],npg,nf,fr[10],occupied=0,pgfault=0;
	
	printf("enter no of pages \n");
	scanf("%d",&npg);
	printf("enter %d  page no ",npg);
	for(i=0;i<npg;i++)
	scanf("%d",&rfstr[i]);
	printf("enter no of frames");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	fr[i]=-1;
	
	
	printf("page  \t    frames ");
	for(i=0;i<npg;i++)
	{
		printf("\n %d \t",rfstr[i]);
		if(checkhit(rfstr[i],fr,occupied))   //if hit occures
		{
		print(fr,occupied);
	    }
    	else if (occupied < nf)        //if frames are  empty i.e, pgswere not fully occupied by pages 
    	{                              // occupied pgs less than no of frames
    		fr[occupied]=rfstr[i];
    		pgfault++;
    		occupied++;
    		print(fr,occupied);
		}
		else                         
		{
			int max=-1;
			int idx;
			int dist[npg];
			for(j=0;j<nf;j++)     // 0 to  no  of farmes
			{
				dist[j]=0;
				for(k=i-1;k>=0;k--)  // traversing to front part of refstr , particular pos to satrting
				{
					++dist[j];
					
					if(fr[j]==rfstr[k])  // element in frame  compared with refstr and check the max distance
					break;
					
				}
				if(dist[j]>max)
				{
					max=dist[j];
					idx=j;
				}
			}
			
			fr[idx]=rfstr[i];   // at that particular position refstring element is replaced 
			print(fr, occupied);
			pgfault++;
			
		}
 	
		printf("\n");
	}
	
	printf("pagefault =  %d",pgfault);
}
