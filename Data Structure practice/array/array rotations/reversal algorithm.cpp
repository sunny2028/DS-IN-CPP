#include<iostream>                 //Time complexity: O(n)
using namespace std;                //Auxilary space:O(1)
void rotate(int a[],int start,int end)//https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
{int temp;
while(start<end)
{temp=a[start];
a[start]=a[end];
a[end]=temp;
start++;
end--;
}
}

void reverse(int a[],int d,int n)
{rotate(a,0,d-1);
rotate(a,d,n-1);
rotate(a,0,n-1);
}


void print(int a[],int l)
{for(int i=0;i<l;i++)
cout<<a[i]<<" ";
}
int main()
{int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
reverse(a,2,12);
print(a,12);
return 0;
}
