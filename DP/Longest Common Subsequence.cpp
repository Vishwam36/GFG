// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#
// Simple DP

// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends

int dp[101][101];

int rec(int x, int y, string s1, string s2)
{
    if(x <= 0 || y <= 0)
    {
        dp[x][y] = 0;
    }
        
    else if(dp[x][y] != -1)
    {
        return dp[x][y];
    }
    
    else if(s1[x-1] == s2[y-1])
    {
        dp[x][y] = 1 + rec(x-1, y-1, s1, s2);
    }
    else
    {
        dp[x][y] = max(rec(x-1, y, s1, s2), rec(x, y-1, s1, s2));
    }
    return dp[x][y];
}

int lcs(int x, int y, string s1, string s2)
{
    memset(dp, -1, sizeof(dp));
    return rec(x, y, s1, s2);
}
