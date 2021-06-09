// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#
// Good question
// REF : https://www.youtube.com/watch?v=S49zeUjeUL0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=43

/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. 
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
There are few rules given below. 

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

For more description on this problem see wiki page

Example 1:
Input:
N = 2, K = 10
Output: 4

Example 2:
Input:
N = 3, K = 5
Output: 3

Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order 
to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200
*/

class Solution
{
    public:
    int dp[201][201];
    
    int rec(int e, int f)
    {
        if(f <= 1)
            return f;
        
        if(e == 1)
            return f;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        
        int ans = INT_MAX;
        for(int k = 1; k <= f; ++k)
        {
            int broken = dp[e-1][k-1] == -1 ? rec(e-1, k-1) : dp[e-1][k-1];
            int not_broken = dp[e][f-k] == -1 ? rec(e, f-k) : dp[e][f-k];
            
            ans = min(ans, max(broken, not_broken)+1);
        }
        return dp[e][f] = ans;
    }
    
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return rec(n, k);
    }
};
