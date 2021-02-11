// By Vishwam Shriram Mundada
// It is given under DP. 
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// decent 
// https://www.youtube.com/watch?v=qW1O1a40-No

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int a[])
{
    vector<int> v;
    v.push_back(a[0]);
    for(int i = 1; i < n; ++i)
    {
        if(a[i] < v.back())
        {
            int index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[index] = a[i];
        }
        if(a[i] > v.back())
        {
            v.push_back(a[i]);
        }
    }
    return v.size();
}
