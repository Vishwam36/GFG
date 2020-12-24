// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0#

#include <bits/stdc++.h>
using namespace std;

void rec(string s, int l, int r, vector<string>& v)
{
    if(l==r)
    {
        v.push_back(s);
    }
    else
    {
        for(int i=l;i<=r;++i)
        {
            swap(s[l],s[i]);
            rec(s,l+1,r,v);
            swap(s[l],s[i]);
        }
    }
}

int main() 
{
    int t;
    string s;
    vector<string> v;
    cin>>t;
    while(t--)
    {
        cin>>s;
        rec(s,0,s.size()-1,v);
        
        // to print in lexicographic order
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v.clear();
    }
	return 0;
}
