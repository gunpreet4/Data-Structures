#include<iostream>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	Node* link;
};
  Node* A= NULL;
  void print(struct Node* p)
	{
		if(p==NULL)
		return ;
		printf("%d ",p->data);
		print(p->link);
	}
	void insert(int data,int n)
	{
	Node* temp1=new Node();
	temp1->data=data;
	temp1->link=NULL;
		if(n==1)
		{
			temp1->link=A;
			A=temp1;
			return;
    	}
	Node* temp2=A;
    for(int i=0;i<n-2;i++)
    	{
    		temp2=temp2->link;
    	}
    temp1->link=temp2->link;
    temp2->link=temp1;
    }
    void del(int n)
    {
    	Node* temp1=A;
    	if(n==1)
    	{
    		A=temp1->link;
    		delete temp1;
    		return;
		}
		for(int i=0;i<n-2;i++)
		temp1=temp1->link;
		Node* temp2=temp1->link;
		temp1->link=temp2->link;
		delete temp2;
	}
	void reverse()
	{
		Node* current,*prev,*next;
		current=A;
		prev=NULL;
		while(current!=0)
		{
			next=current->link;
			current->link=prev;
			prev=current;
			current=next;
		}
		A=prev;
	}
	void RecurssivePrint(Node* head)
	{
		if(head==NULL)
		return;
		printf("%d ",head->data);
		RecurssivePrint(head->link);
	}
	void ReversePrint(Node* head)
	{
		if(head==NULL)
		return ;
		ReversePrint(head->link);
		printf("%d ",head->data);
	}
	void RecurssiveReverse(Node* head)
	{
		if(head->link==NULL)
		{
			A=head;
			return;
		}
		RecurssiveReverse(head->link);
		Node* q=head->link;
		q->link=head;
		head->link=NULL;
	}
	int main()
	{
		Node* temp=new Node();
		temp->data=2;
		temp->link=NULL;
		A=temp;
		temp=new Node();
		temp->data=4;
		temp->link=NULL;
		Node* temp1=A;
		while(temp1->link!=NULL)
		temp1=temp1->link;
		temp1->link=temp;
		temp=new Node();
		temp->data=6;
		temp->link=NULL;
		if(A!=NULL)
		temp->link=A;
		A=temp;
		insert(2,1);
		insert(3,3);
		insert(4,4);
		del(4);
		printf("Original Linked List \n");
		print(A);
		printf("\nReverse Linked List \n");
		reverse();
		RecurssivePrint(A);
		printf("\nReverse Printed Linked List \n");
		ReversePrint(A);
		printf("\nReverse Linked List Using Recurssion \n");
		RecurssiveReverse(A);
		print(A);
		return 0;
	}
	
