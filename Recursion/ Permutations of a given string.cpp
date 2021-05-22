// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0#
// Easy, 2 approaches

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> v;
	    // method 1
	    void rec(string s, int index)
	    {
	        if(index >= s.size())
	        {
	            v.push_back(s);
	            return;
	        }
	            
	        for(int i = index; i < s.size(); ++i)
	        {
	            swap(s[index], s[i]);
	            rec(s, index+1);
	            swap(s[index], s[i]);
	        }
	    }
	    
	    // method 2
	    void fun(string s)
	    {
	        v.push_back(s);
			while(next_permutation(s.begin(), s.end()))
	            v.push_back(s);
	    }
	
	    vector<string>find_permutation(string s)
	    {
	        sort(s.begin(), s.end());
	      //  rec(s, 0);
	        fun(s);
	        sort(v.begin(), v.end());
	        return v;
	    }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
