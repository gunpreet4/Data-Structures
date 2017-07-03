#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node* link;
};
Node* top=NULL;
void push(int x)
{
	Node* temp=new Node();
	temp->data=x;
	temp->link=top;
	top=temp;
}
void pop()
{
	if(top==NULL)
	{
		printf("Stack is Empty");
		return;
	}
	Node* temp=new Node();
	temp=top;
	top=top->link;
	delete(temp);
}
void display(Node* a)
{
	if(a==NULL)
	return;
	display(a->link);
	printf("%d ",a->data);
}
int main()
{
	push(5);
	push(6);
	push(3);
	push(4);
	printf("Original Stack\n");
	display(top);
	pop();
	pop();
	printf("\nStack After Pop\n");
	display(top);
}
