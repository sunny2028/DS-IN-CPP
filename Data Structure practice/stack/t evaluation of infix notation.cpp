#include<bits/stdc++.h>
using namespace std;
int value(char ch,int a,int b)
{switch(ch)
{case '+':return a+b;
case '-':return b-a;
case '*':return a*b;
case '/':return b/a;
}
return 0;
}
bool precendence(char a,char b)
{
if(a=='('||a==')')
return false;
else if((a=='+'||a=='-')&&(b=='*'||b=='/'))
return false;
else
return true;

}
int evaluateinfix(char *a)
{stack<int>s;
stack<char>st;
for(int i=0;i<strlen(a);i++)
{if(a[i]==' ')
continue;

else if(a[i]>='0'&&a[i]<='9')
{
    int num=0;
while(a[i]!=' '&&a[i]!='\0')
   {num=num*10+(a[i]-48);
   i++;
   }
   s.push(num);
}
else if(a[i]=='(')
st.push(a[i]);
else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
{
while(!st.empty()&&precendence(st.top(),a[i]))
{int x=s.top();
       s.pop();
       int y=s.top();
       s.pop();
        s.push(value(st.top(),x,y));
st.pop();

}
st.push(a[i]);
}
else if(a[i]==')')
{while(!st.empty()&&st.top()!='(')
    { int x=s.top();
       s.pop();
       int y=s.top();
       s.pop();
        s.push(value(st.top(),x,y));
st.pop();

}

    if(!st.empty())
    st.pop();

}
}

while(!st.empty())
{int x=s.top();
       s.pop();
       int y=s.top();
       s.pop();
        s.push(value(st.top(),x,y));
st.pop();

}
return s.top();
}
int main()
{char a[]="100 * ( 2 + 12 ) / 14";
cout<<evaluateinfix(a);

}
