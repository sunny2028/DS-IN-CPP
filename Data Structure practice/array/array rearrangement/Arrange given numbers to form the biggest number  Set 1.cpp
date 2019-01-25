#include<iostream>//https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
#include<string>//TIME COMPLEXITY:O(n) AUXILIARY SPACE:O(1)
#include<vector>
#include<algorithm>
using namespace std;
int comparison (string x, string y)
{string xy=x.append(y);
string yx=y.append(x);
return(xy.compare(yx)>0)?1:0;

}
void printlargest(vector<string>v)
{sort(v.begin(),v.end(),comparison);
for(int i=0;i<v.size();i++)
cout<<v[i];


}
using namespace std;
int main()
{vector<string>v;
v.push_back("54");
v.push_back("546");
v.push_back("548");
v.push_back("60");
printlargest(v);



}
