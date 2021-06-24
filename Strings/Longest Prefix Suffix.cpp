// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
// IMP

/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:
Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 

Example 2:
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 

Your task:
You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 10^5
s contains lower case English alphabets
*/

class Solution{
public:
	int lps(string s)
	{
	    vector<int> pi(s.size(), 0);
	    for(int i = 1; i < s.size(); ++i)
	    {
	        int j = pi[i-1];
	        
	        while(j > 0 && s[i] != s[j])
	            j = pi[j-1];
	        
	        if(s[i] == s[j])
	            ++j;
	        
	        pi[i] = j;
	    }
	    return pi[s.size()-1];
	}
};
