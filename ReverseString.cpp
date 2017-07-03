#include<iostream>
#include<stack>
#include<String.h>
using namespace std;
void reverse(char* c,int n)
{
	stack<char> s;
	for(int i=0;i<n;i++)
	{
		s.push(c[i]);
	}
	for(int i=0;i<n;i++)
	{
		c[i]=s.top();
		s.pop();
	}
}
int main()
{
	char c[50];
	printf("Enter the String\n");
	gets(c);
	reverse(c,strlen(c));
	printf("Reverse = %s",c);
}
