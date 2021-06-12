// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
// Decent
// REF : https://www.youtube.com/watch?v=e1HlptlipB0&t=1373s

/*
Given two strings S and P. Find the smallest window in the S consisting of all the characters of P.

Example 1:
Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

Example 2:
Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and 
returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, 
return the one with the least starting index. Return "-1" in case there is no such window present. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S|, |P| ≤ 10^5
*/

class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        int min_l = INT_MAX, ans_l = 0;
        int desiredCount = 0, count = 0;
        
        vector<int> fp(26, 0), fs(26, 0);
        for(char ch : p)
        {
            desiredCount++;
            fp[ch-'a']++;
        }
        
        for(int l = 0, r = 0; r < s.size(); )
        {
            while(r < s.size() && count != desiredCount)
            {
                fs[s[r]-'a']++;
                if(fs[s[r]-'a'] <= fp[s[r]-'a'])
                    count++;
                // else
                    // we have encountered extra character
                
                ++r;
            }
            
            if(r == s.size() && min_l == INT_MAX && count != desiredCount)
                return "-1";
            
            while(l < r && count == desiredCount)
            {
                fs[s[l]-'a']--;
                if(fp[s[l]-'a'] != 0 && fs[s[l]-'a'] < fp[s[l]-'a'])
                    count--;
                // else
                    // we have removed extra character
                
                ++l;
            }
            
            if(min_l > r-l+1)
            {
                min_l = r-l+1;
                ans_l = l-1;
            }
        }
        
        if(min_l == INT_MAX)
            return "-1";
        
        return s.substr(ans_l, min_l);
    }
};
