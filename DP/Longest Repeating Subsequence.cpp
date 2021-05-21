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

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s)
		{
		    int n = s.size(), ans = 0;
		    int dp[n+1][n+1];
		    memset(dp, 0, sizeof(dp));
		    
		    for(int i = 0; i < n; ++i)
		    {
		        for(int j = i+1; j < n; ++j)
		        {
		            if(s[i] == s[j])
		            {
		                dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i+1][j], dp[i][j+1]));
		                ans = max(ans, dp[i+1][j+1]);
		            }
		            else
		            {
		                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		            }
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
