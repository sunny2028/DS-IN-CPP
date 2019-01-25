#include<iostream>
using namespace std;
class kQueues
{int *arr;
int *front;
int *rear;
int *next;
int n,k,free;
public :kQueues(int k1,int n1)
{
	n=n1;
	k=k1;
	arr=new int[n];
	front=new int[k];
	rear=new int[k];
	next=new int[n];
	for(int i=0;i<k;i++)
	{
		front[i]=-1;
	}
	for(int j=0;j<n-1;j++)
	next[j]=j+1;
	next[n-1]=-1;
	free=0;
}
bool isfull()
{
	return (free == -1);
}
bool isempty(int sn)
{
	return (front[sn] == -1);
}
void enqueue(int x,int sn)
{
	if(isfull())
        return;
           
        int i=free;
        free=next[i];
        
        if(isempty(sn))
        {
		front[sn]=i;
		
	}
        else
        next[rear[sn]]=i;
          
        next[i]=-1;
        rear[sn]=i;
        arr[i]=x;
      
}
int dequeue(int sn)
{
	if(isempty(sn))
	return -1;
	int i=front[sn];
	front[sn]=next[i];
	next[i]=free;
	free=i;
	return arr[i];
	
}
	
};
int main()
{
	int k = 3, n = 10;
    kQueues ks(k, n);
 
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
