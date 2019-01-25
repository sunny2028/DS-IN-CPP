#include<bits/stdc++.h>//https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/
using namespace std;
int countNumber(int n)
{int result=0;
for(int i=1;i<=9;i++)
{stack<int>s;
    if(i<=n)
{s.push(i);
result++;
}
int tp=s.top();
s.pop();
for(int j=tp%10;j<=9;j++)
{int x=tp*10 + j;
if(x<=n)
{s.push(x);
result++;
}
}
}
return result;
}
int main()
{int n = 123;
    cout << countNumber(n) << endl;
    return 0;


}
