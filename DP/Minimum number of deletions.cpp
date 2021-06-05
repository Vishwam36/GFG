// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1#
// Easy

/*
Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 
Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.

Example 1:
Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".

Example 2:
Input: n = 3, str = "aba"
Output: 0
Explanation: We don't remove any
character.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minDeletions() which takes the string s and length of s as inputs and 
returns the answer.

Expected Time Complexity: O(|str|2)
Expected Auxiliary Space: O(|str|2)

Constraints:
1 ≤ |str| ≤ 10^3
*/

int minDeletions(string s, int n) 
{
    string t = s;
    reverse(t.begin(), t.end());
    vector<vector<int> > dp(n+1, vector<int>(n+1));
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
    return n-dp[n][n];
} 
