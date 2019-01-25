// CPP program to find smallest multiple of a 
// given number made of digits 0 and 9 only
#include <bits/stdc++.h>
using namespace std;

// Maximum number of numbers made of 0 and 9
#define MAX_COUNT 10000

// vector to store all numbers that can be formed
// using digits 0 and 9 and are less than 10^5
vector<string> vec;

/* Preprocessing function to generate all possible 
numbers formed by 0 and 9 */
void generateNumbersUtil()
{ 
	// Create an empty queue of strings
	queue<string> q;
		
	// enque the first number
	q.push("9");
	
	// This loops is like BFS of a tree with 9 as root
	// 0 as left child and 9 as right child and so on
	for (int count = MAX_COUNT; count > 0; count--)
	{
		string s1 = q.front();
		q.pop();
		
		// storing the front of queue in the vector
		vec.push_back(s1);
		
		string s2 = s1;
		
		// Append "0" to s1 and enqueue it
		q.push(s1.append("0"));
		
		// Append "9" to s2 and enqueue it. Note that
		// s2 contains the previous front
		q.push(s2.append("9"));
	}
}

// function to find smallest number made up of only 
// digits 9’s and 0’s, which is a multiple of n.
string findSmallestMultiple(int n)
{ 
	// traverse the vector to find the smallest
	// multiple of n
	for (int i = 0; i < vec.size(); i++)

		// stoi() is used for string to int conversion
		if (stoi(vec[i])%n == 0) 
			return vec[i];	 
}

// Driver Code
int main()
{
	generateNumbersUtil(); 
	int n = 7; 
	cout << findSmallestMultiple(n); 
	return 0;
}

