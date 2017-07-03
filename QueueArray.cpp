//Array Implementation of Queue

#include<iostream>
#include<String.h>
#include<stdlib.h>

//int n=100;
int a[5];
int front=-1;
int rear=-1;

bool IsEmpty()
{
	if (front==-1 && rear==-1)
		return true;
	else 
		return false;
}
void Enqueue(int x)
{
	if((rear+1)%5==front)
	{
		printf("Queue Is Full");
		return;
	}
	else if(IsEmpty())
		front=rear=0;
	else
		rear=(rear+1)%5;
	a[rear]=x;
}
void dequeue()
{
	if(IsEmpty())
	{
		printf("Queue Is Empty");
		return;
	}
	else if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%5;
}
void display()
{
	if(front==-1 && rear==-1)
		printf("Queue Is Empty");
	else
	{
		for(int i=front;i<=rear;i++)
	{
		printf("%d ",a[i]);
	}
	}
	printf("\n");
}
int main()
{
	Enqueue(4);
	display();
	dequeue();
	display();
	Enqueue(5);
	Enqueue(6);
	Enqueue(7);
	Enqueue(8);
	Enqueue(9);
	display();
	Enqueue(10);
}
