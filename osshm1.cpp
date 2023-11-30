#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
int main()
{
	int shmid;
	void *sharedmemory;
	char buff[100];
	shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
	printf("key of shared memory is %d \n ",shmid);
	sharedmemory=shmat(shmid,NULL,0);
	printf("process attached at %p \n ",sharedmemory);
	printf("enter some data to write to shared memory\n");
	read(0,buff,100);
	strcpy(sharedmemory,buff);
	printf("you wrote : %s \n",(char *)sharedmemory);
}
