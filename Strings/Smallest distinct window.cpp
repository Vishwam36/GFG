// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
// Easy, Sliding window

/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Example 1:
Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"

Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as inputs and 
returns the length of the smallest such string.

Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)

Constraints:
1 ≤ |S| ≤ 10^5
String may contain both type of English Alphabets.
*/

class Solution{
    public:
    string findSubString(string str)
    {
        unordered_map<char, int> m;
        
        for(auto ch : str)
            m[ch]++;
        
        int total = m.size(), ansSize = str.size(), ansL = 0, ansR = str.size()-1;
        
        m.clear();
        
        int l = 0;
        for(int r = 0; r < str.size(); ++r)
        {
            m[str[r]]++;
            if(m.size() < total)
                continue;
            
            while(l < r)
            {
                if(m[str[l]] > 1)
                {
                    m[str[l]]--;
                    ++l;
                }
                else
                {
                    break;
                }
            }
            if(ansSize > r-l+1)
            {
                ansSize = r-l+1;
                ansL = l;
                ansR = r;
            }
        }
        return str.substr(ansL, ansR-ansL+1);
    }
};
