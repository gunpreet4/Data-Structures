//NOT COMPLETED
#include<iostream>
#include<conio.h>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};
struct Node* head;
struct Node* GetnewNode(int x)
{
	Node* temp=new Node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void InsertAtHead(int x)
{
	Node* temp=GetnewNode(x);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}
void Print()
{
	Node* temp=head;
	if(head==NULL)
	return;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void ReversePrint()
{
	Node* temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	printf("\nReverse Print \n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
}
void InsertAtTail(int x)
{
	Node* temp=GetnewNode(x);
	Node*temp1=head;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	temp->prev=temp1;
}
void InsertAtN(int x,int y)
{
	Node* temp=GetnewNode(y);
	if(x==1)
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
		return;
	}
	Node* temp1=head;
	for(int i=1;i<x-1;i++)
	{
		temp1=temp1->next;
	}
	Node* temp2=temp1->next;
	temp2->prev=temp;
	temp->next=temp2;
	temp1->next=temp;
	temp->prev=temp1;
}
int main()
{
	InsertAtHead(5);
	InsertAtHead(6);
	InsertAtTail(4);
	InsertAtN(2,8);
	Print();
	ReversePrint();
}
