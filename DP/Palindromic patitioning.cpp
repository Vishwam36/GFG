// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#
// Good question

/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts 
needed for palindrome partitioning of given string.

Example 1:
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

Example 2:
Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and 
returns minimum number of partitions required.

Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)

Constraints:
1 ≤ length of str ≤ 500
*/

class Solution{
public:
    int dp[501][501];
    
    bool isPalindrome(string &s, int l, int r)
    {
        while(l < r)
            if(s[l++] != s[r--])
                return false;
        
        return true;
    }
    
    int rec(int i, int j, string &s)
    {
        if(i >= j)
            return dp[i][j] = 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(isPalindrome(s, i, j))
            return dp[i][j] = 0;
        
        int ans = INT_MAX;
        for(int k = i; k < j; ++k)
        {
            if(dp[i][k] == 0 || isPalindrome(s, i, k))
            {
                int tempAns = rec(k+1, j, s) + 1;
                ans = min(ans, tempAns);
            }
        }
        return dp[i][j] = ans;
    }
    
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, str.size()-1, str);
    }
};
