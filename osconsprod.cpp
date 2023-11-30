#include<stdio.h>
#include<stdlib.h>

int m=1,f=0,e=3,x=0,i=1;

int wait(int s){
	return (--s);
}

int signal(int s ){
	return (++s);
}

void producer()
{
	m=wait(m);
	f=signal(f);
	e=wait(e);
	x++;
	printf("\n producer produces item  %d ",x);
	m=signal(m);
	
}

void consumer()
{
	m=wait(m);
	f=wait(f);
	e=signal(e);
	printf("consumer consumes the item %d",x);
	x--;
	m=signal(m);
	
}

int main()
{
	int n,c;
	while(c==1)
	{
	
	printf("1-prod 2-cons 3-exit\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			if((m==1) && (e!=0))
			producer();
			else
			printf("buffer is full\n");
		    break;
		case 2:
			if((m==1) && (f!=0))
			consumer();
			else
			printf("buffer is empty\n");
			break;
		case 3:
		     exit(0);
			 break;	
	}
	printf("\n 1-continue 2-exit \n");
	scanf("%d",&c);
	}
	
}




