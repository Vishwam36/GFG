// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/power-set4302/1#
// Easy

/*
Given a string S find all possible substrings of the string in lexicographically-sorted order.

Example 1:
Input : str = "abc"
Output: a ab abc ac b bc câ€‹
Explanation : There are 7 substrings that 
can be formed from abc.

Example 2:
Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.

Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list
of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.

Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)

Constraints: 
1 <= Length of string <= 16
*/

// App 1 : Recursion

class Solution{
	public:
	vector<string> ans;
	
	void rec(int idx, string &s, string temp)
	{
	    if(idx == s.size())
	    {
	        if(temp != "")
	            ans.push_back(temp);
	        return;
	    }
	    
	    rec(idx+1, s, temp);
	    temp.push_back(s[idx]);
	    rec(idx+1, s, temp);
	}
	
	vector<string> AllPossibleStrings(string s)
	{
	    string temp;
	    rec(0, s, temp);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

// App 2 : Bit manipulation

class Solution{
	public:
	string getString(int bit, string &s)
	{
	    string ans;
	    for(int i = 0; i < s.size(); ++i)
	        if(((1 << i) & (bit)) != 0)
	            ans.push_back(s[i]);
	    
	    return ans;
	}
	
	vector<string> AllPossibleStrings(string s)
	{
	    vector<string> ans;
	    int last = pow(2, s.size())-1;
	    for(int i = 1; i <= last; ++i)
	        ans.push_back(getString(i, s));
	    
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};
