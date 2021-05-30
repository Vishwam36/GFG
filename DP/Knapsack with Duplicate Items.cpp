// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
// Unbounded Knapsack

/*
Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N items 
any number of times so that the total weight is less than or equal to W.

Example 1:
Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.

Example 2:
Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explaination: The optimal choice is to 
pick the 2nd and 4th element.

Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val[] and wt[] 
as input parameters and returns the maximum possible value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100
*/

// Top-Down

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        int dp[n+1][w+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= w; ++j)
            {
                int include = 0;
                int not_include = dp[i-1][j];
                
                if(j-wt[i-1] >= 0)
                    include = dp[i][j-wt[i-1]] + val[i-1]; // in include we can choose current ith item again also
                
                dp[i][j] = max(include, not_include);
            }
        }
        
        return dp[n][w];
    }
};

// Recursion + memoization

class Solution{
public:
    int dp[1001][1001];
    
    int rec(int index, int n, int totalW, int w, int val[], int wt[])
    {
        if(index >= n || w >= totalW)
            return 0;
        
        if(dp[index][w] != -1)
            return dp[index][w];
        
        int include = 0;
        if(w+wt[index] <= totalW)
            include = rec(index, n, totalW, w+wt[index], val, wt) + val[index];
        
        int not_include = rec(index+1, n, totalW, w, val, wt);
        
        return dp[index][w] = max(include, not_include);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, N, W, 0, val, wt);
    }
};
