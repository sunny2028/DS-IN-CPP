#include<bits/stdc++.h>//time complexity:O(r*c)
using namespace std;//https://www.geeksforgeeks.org/rotate-matrix-180-degree/
#define r 4
#define c 4
void transpose(int a[4][4])
{for(int i=0;i<r;i++)
   for(int j=i;j<c;j++)// agar clockwise ghumani hai to pahle transpose karo aur fir har row ke element ko reverse kardo aur agr anticlockwise ghumnai ha 90degree to transpose kar har column ke elements ko reverse kardo
    swap(a[i][j],a[j][i]);

}
void printarray(int a[4][4])
{for(int i=0;i<r;i++)
   {for(int j=0;j<c;j++)
         cout<<a[i][j]<<" ";

   cout<<"\n";
   }
}
void rotati(int a[4][4])
{ transpose(a);
int i,j,k;
/*
for(i=0;i<r;i++)
{ for(j=0,k=c-1;j<k;j++,k--)
   swap(a[j][i],a[k][i]);

}*/
for(i=0;i<r;i++)
{ for(j=0,k=c-1;j<k;j++,k--)
   swap(a[i][j],a[i][k]);
}


transpose(a);
/*for(i=0;i<c;i++)
{ for(j=0,k=c-1;j<k;j++,k--)
   swap(a[j][i],a[k][i]);

}*/
for(i=0;i<r;i++)
{ for(j=0,k=c-1;j<k;j++,k--)
   swap(a[i][j],a[i][k]);
}

printarray(a);
}
int main()
{
int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
rotati(a);
}

