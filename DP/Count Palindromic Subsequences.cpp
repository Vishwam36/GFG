// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
// Decent
// REF : https://www.youtube.com/watch?v=vlbA8oUxSV0

/*
Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;
 
Example 1:
Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"

Example 2:
Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPs() which takes a string str as input parameter and 
returns the number of palindromic subsequence.
 
Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
1<=length of string str <=1000
*/

class Solution{
    public:
    const long long MOD = 1000000007;
    
    long long dp[1001][1001];
    
    long long rec(int i, int j, string s)
    {
        if(i == j) // single character palindrome
            return 1;
        
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long match = 0, misMatch = 0;
        
        misMatch = (dp[i+1][j] == -1 ? rec(i+1, j, s) : dp[i+1][j]) 
                 + (dp[i][j-1] == -1 ? rec(i, j-1, s) : dp[i][j-1]) 
                 - (dp[i+1][j-1] == -1 ? rec(i+1, j-1, s) : dp[i+1][j-1]); // repeatition
        
        if(s[i] == s[j]) // looks simple but tricky
            match = (dp[i+1][j-1] == -1 ? rec(i+1, j-1, s) : dp[i+1][j-1]) + 1;
        
        return dp[i][j] = (((misMatch + MOD) % MOD) + match) % MOD;
    }
    
    long long int  countPS(string str)
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, str.size()-1, str);
    }
};
