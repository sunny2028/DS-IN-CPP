#include<bits/stdc++.h>
using namespace std;
int maxi(int a[],int n)
{int min_index_here=0,max_index_here=0,max_so_far=0,temp;
for(int i=0;i<n;i++)
{if(a[i]>0)
{max_index_here=max_index_here*a[i];
min_index_here=min(min_index_here*a[i],1);
}
if(a[i]==0)
{max_index_here=1;
min_index_here=1;
}
if(a[i]<0)
{temp=max_index_here;
max_index_here=max(min_index_here*a[i],1);
min_index_here=temp*a[i];
}
if(max_so_far<max_index_here)
max_so_far=max_index_here;

}

return max_so_far;
}

int main()
{int arr[]={1, -2, -3, 0, 7, -8, -2};
cout<<maxi(arr,7);

}
