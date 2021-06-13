// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#
// Easy, unbounded knapsack variation

/*
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the
minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example 1:
Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 

Example 2:
Input: N = 5, arr[] = {-1, -1, 4, 3, -1}
W = 5
Output: -1
Explanation: It is not possible to buy 5 
kgs of oranges

Your Task:  
You don't need to read input or print anything. Complete the function minimumCost() which takes N, W, and array cost as input parameters and 
returns the minimum value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N, W ≤ 103
-1 ≤ cost[i] ≤ 105
cost[i] ≠ 0
*/

class Solution{
	public:
	const int MAX = 1e9;
	int minimumCost(int cost[], int n, int w) 
	{
	    vector<vector<int> > dp(n+1, vector<int> (w+1, 0));
	    for(int j = 1; j <= w; ++j)
	        dp[0][j] = MAX;
	    for(int i = 0; i <= n; ++i)
	        dp[i][0] = 0;
	       
	    for(int i = 1; i <= n; ++i)
	        for(int j = 1; j <= w; ++j)
	        {
	            int take = MAX, not_take = MAX;
	            if(j-i >= 0 && cost[i-1] != -1)
	                take = dp[i][j-i] + cost[i-1];
	            
	            not_take = dp[i-1][j];
	            dp[i][j] = min(take, not_take);
	        }
	    
	    return dp[n][w] >= MAX ? -1 : dp[n][w];
	} 
};
