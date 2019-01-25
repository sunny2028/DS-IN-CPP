#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
 
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}
 
string infixtopostfix(string infix)
{
    int l = infix.size();
    stack<char> char_stack;
    string output;
 
    for (int i = 0; i < l; i++) {
        // If the scanned character is an 
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');
 
        // If the scanned character is an
        // ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
 
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
 
            // Remove '(' from the stack
            char_stack.pop(); 
        }
 
        // Operator found 
        else {
             
            if (isOperator(infix[i])){
                while (!char_stack.empty()&&getPriority(infix[i])
                   <= getPriority(char_stack.top())) {
                    output += char_stack.top();
                    char_stack.pop();
                }
 
                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
        
    while(!char_stack.empty())
    {
	output=output+char_stack.top();
    char_stack.pop();
    
	}
    return output;
}
 

void infixtoprefix(string s)
{
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
		{
			s[i]=')';
		}
		else if(s[i]==')')
		  s[i]='(';
	}
    reverse(s.begin(),s.end());
    s=infixtopostfix(s);
	reverse(s.begin(),s.end());
	cout<<s;
}
int main()
{
	string s="(a-b/c)*(a/k-l)";
      infixtoprefix(s);	
}
