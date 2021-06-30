// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/travelling-salesman-problem2732/1#
// Good question, Graph, DP, Bit Masking
// REF : https://www.youtube.com/watch?v=JE0JE8ce1V0&ab_channel=CodingBlocks

/*
Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all 
other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.

Example 1:
Input: cost = {{0,111},{112,0}}
Output: 223
Explanation: We can visit 0->1->0 and 
cost = 111 + 112.

Example 2:
Input: cost = {{0,1000,5000},{5000,0,1000},
{1000,5000,0}}
Output: 3000
Explanation: We can visit 0->1->2->0 and cost 
= 1000+1000+1000 = 3000

Your Task:
You don't need to read or print anyhting. Your task is to complete the function total_cost() which takes cost as input parameter and 
returns the total cost to visit each city exactly once starting from city 0 and again comback to city 0. 

Expected Time Complexity: O(2n * n2)
Expected Space Compelxity: O(2n * n)

Constraints:
1 <= n <= 10
1 <= cost[i][j] <= 10^3
*/

class Solution {
public:
    int n;
    int ALL_VISITED;
    vector<vector<int> > dp;
    
    int rec(int mask, int parent, vector<vector<int>> &cost)
    {
        if(mask == ALL_VISITED)
            return cost[parent][0];
        
        if(dp[mask][parent] != -1)
            return dp[mask][parent];
        
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)
            if(((1 << i) & (mask)) == 0)
                ans = min(ans, cost[parent][i] + rec(((mask) | (1 << i)), i, cost));
        
        return dp[mask][parent] = ans;
    }
    
    int total_cost(vector<vector<int>>cost)
    {
        n = cost.size();
        ALL_VISITED = (1 << n) - 1;
        dp = vector<vector<int> >(ALL_VISITED+1, vector<int>(n+1, -1));
        return rec(1, 0, cost); // city 0 visited
    }
};
