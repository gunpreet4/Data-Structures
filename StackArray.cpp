#include<iostream>
#include<conio.h>
# define MAX_SIZE 5
using namespace std;
int a[5];
int top=-1;
void push(int x)
{
	if(top==MAX_SIZE-1)
	{
		printf("Error : Stack Overflow");
		return;
	}
	a[++top]=x;
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is Empty");
		return;
	}
	top--;
}
int Top()
{
	if(top==-1)
	{
		printf("Stack is Empty");
		return 0;
	}
	return a[top];
}
int IsEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void display()
{
	for(int i=0;i<=top;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	push(3);
	push(4);
	push(9);
	printf("Original Stack\n");
	display();
	push(6);
	push(8);
	printf("\nFull Stack\n");
	display();
	printf("\nOverflow Condition\n");
	push(10);
	pop();
	pop();
	printf("\nAfter Poping Elements\n");
	display();
	printf("\nTop Element = %d\n",Top());
	int temp=IsEmpty();
	if(temp==0)
	printf("Not Empty\n");
	else
	printf("Empty Stack\n");
}
