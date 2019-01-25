#include<iostream>
using namespace std;
struct dll
{int data;
dll *prev;
dll *next;
};
struct stack
{int count;
dll *head;
dll *mid;
};
stack *createstack()
{stack *newnode=new stack;
newnode->count=0;
return newnode;
}
void push(stack *s,int x)
{dll *newnode=new dll;
newnode->data=x;
newnode->prev=NULL;
newnode->next=s->head;
s->count=s->count+1;
if(s->count==1)
{s->mid=newnode;
}
else
{s->head->prev=newnode;
    if(s->count&1)
{
    s->mid=s->mid->prev;
}
}
s->head=newnode;
}
void pop(stack *s)
{if(s->head==NULL)
 return ;
 if(s->head->next==NULL)
 {s->mid=NULL;
 delete s->head;
 return;
 }
 s->count=s->count-1;
 dll *temp=s->head;
 temp->next->prev=NULL;
 if((s->count&1)==0)
 s->mid=s->mid->next;
 delete temp;

}
int getmid(stack *s)
{return s->mid->data;
}
void deletemid(stack *s)
{if(s->mid->next==NULL)
{delete s->head;
s->mid=NULL;
}
if(s->count&1)
{s->count=s->count-1;
dll *temp=s->mid;
s->mid->prev->next=s->mid->next;
s->mid->next->prev=s->mid->prev;
s->mid=s->mid->next;
delete temp;
}
else
{s->count=s->count-1;
dll *temp=s->mid;
s->mid->prev->next=s->mid->next;
if(s->mid->next)
{
s->mid->next->prev=s->mid->prev;
}
s->mid=s->mid->prev;
delete temp;
}
}
int main()
{stack *s=createstack();
push(s,1);
push(s,2);
push(s,3);
push(s,4);
push(s,5);
push(s,6);
cout<<getmid(s)<<"\n";
pop(s);
cout<<getmid(s)<<"\n";
deletemid(s);
cout<<getmid(s);

}
