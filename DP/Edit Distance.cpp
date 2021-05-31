// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/edit-distance3702/1#
// Decent

/*
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:
    Insert
    Remove
    Replace

Example 1:
Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.

Example 2:
Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and 
returns the minimum number of operation required to make both strings equal. 

Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)

Constraints:
1 ≤ Length of both strings ≤ 100
Both the strings are in lowercase.
*/

// Top-Down

class Solution {
  public:
    int editDistance(string s, string t) 
    {
        int sl = s.size(), tl = t.size();
        int dp[sl+1][tl+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i <= sl; ++i)
        {
            for(int j = 0; j <= tl; ++j)
            {
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else
                {
                    if(s[i-1] == t[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        
        return dp[sl][tl];
    }
};

// Recursion + memoization

class Solution {
  public:
    int dp[105][105];
    int l1, l2;
    
    int rec(int row, int col, string s, string t)
    {
        if(row == l1 && col == l2)
            return 0;
        
        if(row >= l1)
            return l2-col;
        if(col >= l2)
            return l1-row;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        if(s[row] == t[col])
            return dp[row][col] = rec(row+1, col+1, s, t);
        
        int insert = rec(row, col+1, s, t)+1;
        int replace = rec(row+1, col+1, s, t)+1;
        int rem = rec(row+1, col, s, t)+1;
        
        return dp[row][col] = min(min(insert, replace), rem);
    }
    
    int editDistance(string s, string t) 
    {
        memset(dp, -1, sizeof(dp));
        l1 = s.size(), l2 = t.size();
        return rec(0, 0, s, t);
    }
};
