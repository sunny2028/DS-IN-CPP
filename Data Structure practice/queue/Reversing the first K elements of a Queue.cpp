#include<bits/stdc++.h>
using namespace std;
stack<int>s;
void Print(queue<int>q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}
void reverseQueueFirstKElements(int k,queue<int>&q)
{
 stack<int>s;
 for(int i=0;i<k;i++)
 {
 	s.push(q.front());
 	q.pop();
 }
 while(!s.empty())
 {
 	q.push(s.top());
 	s.pop();
 }
 for(int i=0;i<q.size()-k;i++)
 {
 	q.push(q.front());
 	q.pop();
 }
	
}
int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
 
    int k = 5;
    reverseQueueFirstKElements(k, Queue);
    Print(Queue);
}

