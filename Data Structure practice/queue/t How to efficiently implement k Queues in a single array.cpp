#include<iostream>//https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/
using namespace std;
class Queue
{int *arr;
int *front;
int *rear;
int *next;
int k,n;
int free;
public:
Queue(int,int);
void enqueue(int,int);
int dequeue(int);
bool isfull();
bool isempty(int);
};
Queue::Queue(int n1,int k1)
{n=n1;
k=k1;
free=0;
arr=new int[n];
front=new int[k];
rear=new int[k];
next=new int[n];
for(int i=0;i<k;i++)
{front[i]=-1;
}
for(int i=0;i<n-1;i++)
{next[i]=i+1;
}
next[n-1]=-1;
}
void Queue::enqueue(int x,int sno)
{if(isfull())
{cout<<"overflow";
return;
}
int i=free;
free=next[i];
if(front[sno]==-1)
{front[sno]=i;
}
else
  next[rear[sno]]=i;
  rear[sno]=i;
  next[i]=-1;
arr[i]=x;
}
int Queue::dequeue(int sno)
{if(isempty(sno))
{cout<<"underflow";
return -1;
}
if(front[sno]==rear[sno])
{front[sno]=rear[sno]=-1;
}
int i=front[sno];
front[sno]=next[i];
next[i]=free;
free=i;
return arr[i];
}
bool Queue::isfull()
{
return free==-1;
}
bool Queue::isempty(int sno)
{
return front[sno]==-1;
}
int main()
{
int k = 3, n = 10;
    Queue ks(n, k);

    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;


}
