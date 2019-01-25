#include <bits/stdc++.h> 
  
using namespace std; 
  
// to store details of a node like 
// node's data, 'min' and 'max' to obtain the 
// range of values where node's left and  
// right child's should lie 
struct NodeDetails 
{ 
    int data; 
    int min, max; 
}; 
  
// function to check if the given array  
// can represent Level Order Traversal  
// of Binary Search Tree 
bool levelOrderIsOfBST(int arr[], int n) 
{ 
   queue<NodeDetails>q;
   int i=0;
   NodeDetails newnode;
   newnode.data=arr[i++];
   newnode.min=INT_MIN;
   newnode.max=INT_MAX;
   q.push(newnode);
   while(i!=n&&!q.empty())
   {
   	NodeDetails nn=q.front();
   	q.pop();
   	if(i!=n&&arr[i]<nn.data&&arr[i]>nn.min)
   	{
   	newnode.data=arr[i++];
	newnode.min=nn.min;
	newnode.max=nn.data;
	q.push(newnode);	
	}
	if(i!=n&&arr[i]>nn.data&&arr[i]<nn.max)
	{
	newnode.data=arr[i++];
	newnode.min=nn.data;
	newnode.max=nn.max;
	q.push(newnode);
	}
   }
   if(i==n)
   return true;
   return false;
            
} 
  
// Driver program to test above 
int main() 
{ 
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};     
    int n = sizeof(arr) / sizeof(arr[0]);     
    if (levelOrderIsOfBST(arr, n)) 
        cout << "Yes"; 
    else
        cout << "No";         
    return 0;     
}  
