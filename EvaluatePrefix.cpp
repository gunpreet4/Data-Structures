//Evaluate Prefix

#include<iostream>
#include<stack>
#include<String.h>
#include<stdlib.h>

using namespace std;

int perform(char c,int x,int y)
{
	/*if(c=='+')
	return (x+y);
	else if(c=='-')
	return (x-y);
	else if(c=='*')
	return (x*y);
	else if(c=='/')
	return (x/y);
	else
	return (x%y);*/
	switch(c)
	{
		case '+':
		return (x+y);
		break;
		case '-':
		return (x-y);
		break;
		case '*':
		return (x*y);
		break;
		case '/':
		return (x/y);
		break;
		case '%':
		return (x%y);
		break;
	}
}
int prefix(string s)
{
	stack<int> st;
	for(int i=(s.length()-1);i>=0;i--)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
		//	printf("in");
			int t=s[i]-'0';
			//printf("%d",t);
			st.push(t);
		}
		else
		{
			if(st.empty())
			return 0;
			else
			{
			int temp1=st.top();
			st.pop();
			int temp2=st.top();
			st.pop();
			int res=perform(s[i],temp1,temp2);
			st.push(res);
			}
		}
		//printf("%d\n",st.top());
	}
	return st.top();
}
int main()
{
	char c[50];
	printf("Enter the expression\n");
	gets(c);
	printf("Result of expression = %d",prefix(c));
}
