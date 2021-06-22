// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/word-break1352/1#
// Decent

/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 

Example 1:
Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".

Example 2:
Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as 
"i like samsung" or "i like sam sung".

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. 
You don't need to read any input or print any output, it is done by driver code.

Expected time complexity: O(s2)
Expected auxiliary space: O(s) , where s = length of string A

Constraints:
1 <= N <= 12
1 <= s <=1000 , where s = length of string A
 The length of each word is less than 15.
*/

int dp[1001]; // dp[i] stores if we can make substring s(i, n) from dictionary

int rec(int idx, string a, vector<string> &v)
{
    if(dp[idx] != -1)
        return dp[idx];
    
    for(int sz = 1; sz <= a.size(); ++sz)
    {
        bool flag = 0;
        string sub = a.substr(0, sz);
        for(int i = 0; i < v.size(); ++i)
        {
            if(sub == v[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1 && rec(idx+sz, a.substr(sz), v))
            return dp[idx] = 1;
    }
    return dp[idx] = 0;
}

int wordBreak(string a, vector<string> &v) 
{
    memset(dp, -1, sizeof(dp));
    dp[a.size()] = 1;
    return rec(0, a, v);
}
