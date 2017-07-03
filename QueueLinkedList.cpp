//LinkedList implementation of Queue

#include<iostream>
#include<String.h>
#include<stdlib.h>

struct Node
{
	int data;
	Node* link;
};
Node* front=NULL;
Node* rear=NULL;
void Enqueue(int x)
{
	Node* temp=new Node();
	temp->data=x;
	temp->link=NULL;
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->link=temp;
	rear=temp;
}
void Dequeue()
{
	Node* temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("Queue Is Empty\n");
		return;
	}
	else if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->link;
	}
	free(temp);
}
void display()
{
	if(front==NULL && rear==NULL)
		printf("Queue Is Empty\n");
	else
	{
		Node* temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
int main()
{
	Enqueue(4);
	display();
	Dequeue();
	display();
	Enqueue(5);
	Enqueue(6);
	Enqueue(7);
	Enqueue(8);
	display();
}
