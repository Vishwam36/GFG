// By Vishwam Shriram mundada
// https://practice.geeksforgeeks.org/problems/implement-atoi/1#

#include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}

int atoi(string str)
{
    int ans = 0;
    bool negative = false;
    if(str[0] == '-') // for negative numbers
    {
        str.erase(str.begin() + 0);
        negative = true;
    }
    for(int i = 0; i < str.size(); ++i)
    {
        if((int)str[i] > 57 || (int)str[i] < 48) // characters other than digits
        {
            return -1;
        }
        ans += (((int)str[str.size() - i - 1] - 48) * pow(10,i));
    }
    if(negative == true)
    {
        return ans*(-1);
    }
    return ans;
}
