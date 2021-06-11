// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/alien-dictionary/1#
// Decent

/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by 
the function is correct else 0 denoting incorrect string returned.

Example 1:
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Example 2:
Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], 
its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.

Expected Time Complexity: O(N + K)
Expected Space Compelxity: O(K)

Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
*/

class Solution{
    public:
    string findOrder(string dict[], int n, int k) 
    {
        vector<int> adj[26];
        vector<int> in(26, 0);
        
        for(int i = 0; i < n-1; ++i)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int idx = 0;
            while(idx < s1.size() && idx < s2.size() && s1[idx] == s2[idx])
                ++idx;
            
            if(idx < s1.size() && idx < s2.size())
            {
                // means s1[idx] comes before s2[idx]
                adj[s1[idx]-'a'].push_back(s2[idx]-'a');
                in[s2[idx]-'a']++;
            }
        }
        
        string ans;
        queue<int> q;
        for(int i = 0; i < 26; ++i)
            if(in[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            ans.push_back(curr+'a');
            
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                int next = adj[curr][i];
                in[next]--;
                if(in[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
