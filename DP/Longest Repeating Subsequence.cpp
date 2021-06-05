// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
// Easy

/*
Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character 
at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Exampel 1:
Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".

Example 2:
Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestRepeatingSubsequence() 
which takes str as input parameter and returns the length of the longest repeating subsequnece.

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= |str| <= 500
*/

class Solution {
	public:
	int LongestRepeatingSubsequence(string s)
	{
		int n = s.size();
		int dp[n+1][n+1];
		memset(dp, 0, sizeof(dp));
		    
		for(int i = 1; i <= n; ++i)
		{
		    for(int j = 1; j <= n; ++j)
		    {
		        if(i != j && s[i-1] == s[j-1]) // we cant include same char to both subsequences. So i != j
                    dp[i][j] = dp[i-1][j-1] + 1;
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    return dp[n][n];
	}
};
