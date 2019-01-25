#include<bits/stdc++.h>//https://www.geeksforgeeks.org/shuffle-a-given-array/
using namespace std;//TIME COMPLEXITY:O(n)  AUXILIARY SPACE:O(1)
void randomise(int a[],int n)
{srand(time(NULL));
for(int i=0;i<n-1;i++)
{int ele=rand()%(n-i);
     swap(a[ele],a[i]);
}
}
void print(int a[],int n)
{for(int i=0;i<n;i++)
cout<<a[i]<<" ";

}
int main()
{int arr[]={1, 2, 3, 4, 5, 6, 7, 8};
randomise(arr,8);
print(arr,8);
}
