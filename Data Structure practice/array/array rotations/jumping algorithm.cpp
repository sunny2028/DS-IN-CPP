#include<iostream>                 //Time complexity: O(n)
using namespace std;                //Auxilary space:O(1)
int gcd(int a,int b)                //https://www.geeksforgeeks.org/array-rotation/
{if(b==0)
return a;
else
return gcd(b,a%b);
}
void reverse(int a[],int d,int n)
{int i,j,k,temp;
for(i=0;i<gcd(n,d);i++)
  { temp=a[i];
     j=i;
     while(1)
     {  k=j+d;
        if(k>=n)
        k=k-n;
        if(k==i)
        break;
        a[j]=a[k];
        j=k;
     }
     a[j]=temp;
  }

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
