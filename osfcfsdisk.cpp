#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10],n,h,curr,seektime=0,diff,i;
	printf("enter no of disks requests ");
	scanf("%d",&n);
	printf("enter disck sequence ");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("enter head ");
	scanf("%d",&h);
	
	
	for(i=0;i<n;i++)
	{
		
		seektime+=abs(h-arr[i]);
		h=arr[i];
	}
	printf("total seek time = %d",seektime);
	printf("\n sequence is \n");
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
}
