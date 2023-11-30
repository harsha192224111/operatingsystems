#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<pthread.h>
void * fun(void *arg);
int i,j;
int main()
{
	pthread_t a_thread;
	pthread_create(&a_thread,NULL,fun,NULL);
//	pthread_join(a_thread,NULL);// waits for the thread to finish
	printf("inside main program\n");
	for(j=20;j<25;j++)
	{
		printf("%d \n",j);
		sleep(1);
	}
	return 0;
}
void *fun(void *arg)
{
	printf("inside thread fun");
	for(i=0;i<5;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}
