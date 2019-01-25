#include<iostream>//time complexity:O(m*n)
using namespace std;//https://www.geeksforgeeks.org/rotate-matrix-elements/?qa-rewrite=917/rotate-the-matrix-elements/
#define r 3
#define c 5
void spiral(int a[r][c],int m,int n)
{int k=0,l=0,i,j,prev,curr;
while(k<m && l<n)
{ if((k+1==m)&&(l+1==n))
break;

prev=a[k+1][l];

for(i=l;i<n;i++)
 {curr=a[k][i];
 a[k][i]=prev;
 prev=curr;
 }
 k++;

 for(i=k;i<m;i++)
 {curr=a[i][n-1];
 a[i][n-1]=prev;
 prev=curr;
 }
 n--;

 if(k<m)
 {for(i=n-1;i>=l;i--)
 { curr=a[m-1][i];
 a[m-1][i]=prev;
 prev=curr;
 }
 m--;
 }

 if(l<n)
 {for(i=m-1;i>=k;i--)
 {curr=a[i][l];
 a[i][l]=prev;
 prev=curr;
 }
 l++;
 }
}
for(i=0;i<r;i++)
{for(j=0;j<c;j++)
cout<<a[i][j]<<"  ";
cout<<"\n";
}


}
int main()
{int a[r][c]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
spiral(a,r,c);
}
