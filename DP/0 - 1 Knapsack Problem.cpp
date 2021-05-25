// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
// Standard

// App 1 : Recursion + memoization

class Solution
{
    public:
    int dp[1005][1005];
    
    int rec(int i, int w_id, int w, int wt[], int val[], int n)
    {
        if(i >= n || w_id > w)
            return 0;
        
        if(dp[i][w_id] != -1)
            return dp[i][w_id];
        
        int include = w_id + wt[i] <= w ? rec(i+1, w_id+wt[i], w, wt, val, n)+val[i] : 0; // include current item
        int not_include = rec(i+1, w_id, w, wt, val, n); // leave current item
        
        return dp[i][w_id] = max(include, not_include);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, w, wt, val, n);
    }
};


// App 2 : Top-Down DP

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    {
        int dp[n+1][w+1];
        memset(dp, 0, sizeof(dp)); // for base condition, if n == 0 || w == 0 return 0
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= w; ++j)
            {
                int include = 0;
                int not_include = 0;
                
                if(j - wt[i-1] >= 0)
                    include = dp[i-1][j-wt[i-1]] + val[i-1];
                
                not_include = dp[i-1][j];
                
                dp[i][j] = max(include, not_include);
            }
        }
        return dp[n][w];
    }
};
