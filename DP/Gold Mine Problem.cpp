// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#
// Easy

/*
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. 
Initially the miner can start from any row in the first column. From a given cell, the miner can move
    to the cell diagonally up towards the right 
    to the right
    to the cell diagonally down towards the right

Find out maximum amount of gold which he can collect.

Example 1:
Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination: 
The path is {(1,0) -> (2,1) -> (2,2)}.


Example 2:
Input: n = 4, m = 4
M = {{1, 3, 1, 5},
     {2, 2, 4, 1},
     {5, 0, 2, 3},
     {0, 6, 1, 2}};
Output: 16
Explaination: 
The path is {(2,0) -> (3,1) -> (2,2) 
-> (2,3)} or {(2,0) -> (1,1) -> (1,2) 
-> (0,3)}.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maxGold() which takes the values n, m and the mine M 
as input parameters and returns the maximum amount of gold that can be collected.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 50
1 ≤ M[i][j] ≤ 100
*/

class Solution{
public:
    int dp[60][60];
    
    int rec(int row, int col, vector<vector<int>>& mat)
    {
        if(col == mat[0].size() || row == mat.size() || row < 0 || col < 0)
            return 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int tr = 0, br = 0, r = 0;
        if(row > 0)
            tr = dp[row-1][col+1] == -1 ? rec(row-1, col+1, mat) : dp[row-1][col+1];
        
        if(row < mat.size()-1)
            br = dp[row+1][col+1] == -1 ? rec(row+1, col+1, mat) : dp[row+1][col+1];
        
        if(col < mat[0].size()-1)
            r = dp[row][col+1] == -1 ? rec(row, col+1, mat) : dp[row][col+1];
        
        return dp[row][col] = max(tr, max(r, br)) + mat[row][col];
    }
    
    int maxGold(int n, int m, vector<vector<int>> mat)
    {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, rec(i, 0, mat));
        
        return ans;
    }
};
