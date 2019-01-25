#include<bits/stdc++.h>
using namespace std;
int findpivot(int a[],int low,int high)
{int pivot=a[high];
int j=low-1;
for(int i=low;i<high;i++)
{if(a[i]<pivot)
{j++;
swap(a[j],a[i]);
}
}
swap(a[j+1],a[high]);
return(j+1);
}

void quicksort(int a[],int low,int high)
{int p;
if(low<high)
{p=findpivot(a,low,high);
quicksort(a,low,p-1);
quicksort(a,p+1,high);
}
}
void printarray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
      cout<<arr[i]<<" ";

}

int main()
{int arr[]={10, 7, 8, 9, 1, 5};
quicksort(arr,0,6);
printarray(arr,6);
}
