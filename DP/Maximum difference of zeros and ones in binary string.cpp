// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1#
// Easy

/*
Given a binary string of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) 
in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.

Example 1:
Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, 
there are 7 0s and 1 1s, so number 
of 0s - number of 1s is 6. 

Example 2:
Input: S = "111111"
Output: -1
Explanation: S contains 1s only 

Your task:
You do not need to read any input or print anything. The task is to complete the function maxSubstring(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 ≤ |S| ≤ 10^5
S contains 0s and 1s only
*/

class Solution{
public:	
	int maxSubstring(string s)
	{
	    int dp[s.size()+1];
	    dp[0] = 0;
	    
	    // dp[i] = (no. of 0s - no. of 1s) till index i-1 in s
	    int max_i = 0, m = 0;
	    for(int i = 0; i < s.size(); ++i)
	    {
	        if(s[i] == '0')
	            dp[i+1] = dp[i]+1;
	        else
	            dp[i+1] = dp[i]-1;
	        
	        if(dp[i+1] < 0)
	            dp[i+1] = 0;
	        
	        if(m <= dp[i+1])
	        {
	            m = dp[i+1];
	            max_i = i+1;
	        }
	    }
	    
	    int ans = dp[max_i];
	    for(int i = 0; i < max_i; ++i)
	        ans = max(ans, dp[max_i]-dp[i]);
	    
	    return ans == 0 ? -1 : ans;
	}
};
