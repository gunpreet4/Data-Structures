#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;
struct Node
{
	int data;
	Node* link;
};
Node* head=NULL;
void insert(int x)
{
	Node* temp=new Node();
	temp->data=x;
	temp->link=NULL;
	Node* temp1=head;
	if(temp1==NULL)
	{
		head=temp;
		return;
	}
	while(temp1->link!=NULL)
	temp1=temp1->link;
	temp1->link=temp;
}
void display()
{
	Node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
}
void reverse()
{
	if(head==NULL)
	return;
	stack<Node*> s;
	Node* temp=head;
	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->link;
	}
	Node* temp1=s.top();
	head=temp1;
	s.pop();
	while(!s.empty())
	{
		temp1->link=s.top();
		s.pop();
		temp1=temp1->link;
	}
	temp1->link=NULL;
}
int main()
{
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	printf("Original Linked List\n");
	display();
	printf("\nReverse Linked List\n");
	reverse();
	display();
}
