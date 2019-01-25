#include<bits/stdc++.h>//https://www.geeksforgeeks.org/lru-cache-implementation/
using namespace std;
class lru
{int csize;
int hit,pagefault=0;
list<int>dq;
map<int,list<int>::iterator>ma;
public:lru(int x)
       {csize=x;
       hit=x;
       }
    void refer(int x)
    {if(ma.find(x)==ma.end())
      {if(dq.size()==csize)
      {int last=dq.back();
      dq.pop_back();
      ma.erase(last);
      hit++;
      }
      }
      else
      {dq.erase(ma[x]);
      pagefault++;
      }
    dq.push_front(x);
    ma[x]=dq.begin();
    }
    void display()
    {list<int>::iterator it;
    for( it=dq.begin();it!=dq.end();it++)
    cout<<*it<<"    ";
    cout<<"\nhits "<<hit<<"\n";
    cout<<"page faults "<<pagefault;
    }

};
int main()
{lru ca(3);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}
