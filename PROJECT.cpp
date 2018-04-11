#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void read(void arg);
void writ(void arg1);
sem_t q,s;
int r=0,d=0;


void writ(void arg)
{
int f;
f=(int)arg;
sem_wait(&wt);
d++;
printf("\nWriter is %d",data);
sleep(1);
sem_post(&wt);
}

void read(void arg1)
{
sem_wait(&q);
r=r+1;
if(r==1)
sem_wait(&s);
sem_post(&q);
printf("\nReader is %d",data);
sleep(1);
sem_post(&q);
r=r-1;
if(r==0)
sem_wait(&s);
sem_post(&q);
}
int main()
{
int i,p;
pthread_t a[5],v[5];
sem_init(&q,0,1);
sem_init(&s,0,1);
for(i=0;i<5;i++)
{
pthread_create(&a[i],NULL,writ,i);
pthread_create(&v[i],NULL,read,i);
}
for(i=0;i<5;i++)
{
pthread_join(a[i],NULL);
pthread_join(v[i],NULL);
}
}
