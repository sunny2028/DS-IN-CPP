#include<iostream>//https://www.geeksforgeeks.org/create-mergable-stack/
using namespace std;//time complexity:O(1)
class stack
{int data;
stack *next;
stack *head=NULL;
stack *lastnode;
public:
void push(int x)
{stack *newnode=new stack;
newnode->data=x;
if(head==NULL)
{lastnode=newnode;
}
newnode->next=head;
head=newnode;
}
int pop()
{if(head==NULL)
{cout<<"stack underflow";
  return INT_MIN;
}
stack *temp=head;
head=head->next;
int x=temp->data;
delete temp;
return x;
}
stack merge(stack s)
{lastnode->next=s.head;
return *this;
}
void show()
{stack *temp=head;
while(temp)
{cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";


}

};
int main()
{stack s,s1;
s.push(8);
s.push(1);
s1.push(2);
s.push(7);
s1.push(3);
s1.push(4);
s1.push(5);
s.show();
s1.show();
cout<<s.pop()<<"\n";
cout<<s1.pop()<<"\n";
stack obj=s.merge(s1);
obj.show();
}
