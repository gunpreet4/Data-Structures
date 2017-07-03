#include<iostream>
#include<stack>
#include<String.h>
using namespace std;

bool ArePair(char opening,char closing)
{
	if(opening=='('&&closing==')')
		return true;
	else if(opening=='['&&closing==']')
		return true;
	if(opening=='{'&&closing=='}')
		return true;
	else 
		return false;
}
bool AreBalanced(string s)
{
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		st.push(s[i]);
		else if(s[i]==')'||s[i]==']'||s[i]=='}')
		{
			if(st.empty()||!ArePair(st.top(),s[i]))
				return false;
			else
				st.pop();
		}
	}
	return st.empty()?true:false;
}
int main()
{
	char exp[50];
	printf("Enter the expression\n");
	gets(exp);
	if(AreBalanced(exp))
		printf("Balanced Paranthesis");
	else
		printf("Unbalanced Paranthesis");
}
