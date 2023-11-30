#include<stdio.h>
#include<conio.h>
struct process{
	int pid;
	int at;
	int bt;
	int st;
	int ct;
	int tat;
	int wt;
	int rt;
}p[100];
int main()
{
	int i,n,ttat=0, twt=0,trt=0;
	float atat,awt,art;
	
	int iscomp[100]={0};

	
	printf("enter no of proceses");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter arrival time of process %d  ",i+1);
		scanf("%d",&p[i].at);
		printf("enter brust time of process %d  ",i+1);
		scanf("%d",&p[i].bt);
		printf("\n");
		p[i].pid=i+1;
			
	}
	 
	 int comp=0;
	 int currtime=0;
	 while(comp!=n)
	 {	 
	 int idx=-1;
	 int min=1000000;
	 for(i=0;i<n;i++)
	 {
	 	if(p[i].at <= currtime && iscomp[i]==0)
	 	{
	 		if(p[i].bt<min)
	 		{
	 		min=p[i].bt;
			 idx=i;	
			}
			if(p[i].bt==min)
			{
				if(p[i].at<p[idx].at)
				{
					min=p[i].bt;
					idx=i;
				}
			}
		}
	 }
	 
	 if(idx!=-1)
	 {
	 	p[idx].st=currtime;
	 	p[idx].ct=p[idx].st+p[idx].bt;
	 	p[idx].tat=p[idx].ct-p[idx].at;
	 	p[idx].wt=p[idx].tat-p[idx].bt;
	 	p[idx].rt=p[idx].st-p[idx].at;
	 	
	 	ttat+=p[idx].tat;
	 	twt+=p[idx].wt;
	 	trt+=p[idx].rt;
	 	
	 	
	 	iscomp[idx]=1;
	 	comp++;
	 	currtime=p[idx].ct;
	 	
	 }
	 else
	 {
	 	currtime++;
	 }
	} 
	
	atat=(float)ttat/n;
	awt=(float)twt/n;
	art=(float)trt/n;
	
	
	printf("P \t AT \t BT \t ST \t CT \t TAT \t WT \t RT \t \n");
	for(i=0;i<n;i++)
	{
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t \n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	}
	
}

