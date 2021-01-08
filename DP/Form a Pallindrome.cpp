// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/form-a-palindrome/0#

#include <bits/stdc++.h>
using namespace std;

int dp[41][41];

int rec(string s, int l , int r)
{
    if(l > r)
        return INT_MAX;
    if(l == r)
        return 0;
    if(r - l == 1)
    {
        if(s[l] == s[r])
            return 0;
        return 1;
    }
    
    if(dp[l][r] != 0)
        return dp[l][r];
        
    if(s[l] == s[r])
    {
        dp[l][r] = rec(s, l+1, r-1);
    }
    else
        dp[l][r] = min(rec(s, l+1, r) , rec(s, l, r-1)) + 1;
        
    return dp[l][r];
}

int main()
{
    int t = 0;
    string s;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> s;
        cout << rec(s,0,s.size()-1) << endl;
    }
	return 0;
}
