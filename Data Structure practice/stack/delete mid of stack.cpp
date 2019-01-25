#include<bits/stdc++.h>
using namespace std;
void deleteMid(stack<char>&s)
{ static int count;
if(s.size()%2==0)
   count=s.size()/2;
   else
   count=s.size()/2+1;
	if(s.size()==count+1)
	{
	s.pop();
	return;
    }
	char a=s.top();
	s.pop();
	deleteMid(s);
	//if(count!=size/2)
	s.push(a);
}
int main()
{
	 stack<char> st;
 
    //push elements into the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
  //  st.push('7');
    deleteMid(st);
 
    // Printing stack after deletion
    // of middle.
    while (!st.empty())
    {
        char p=st.top();
        st.pop();
        cout << p << " ";
    }
    return 0; 
}
