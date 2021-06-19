// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1#
// Easy

// Recursive

class Solution{
    public:
    void rec(int idx, char pre, string &s, string &ans)
    {
        if(idx == s.size())
            return;
        
        if(s[idx] == pre)
            rec(idx+1, pre, s, ans);
        else
        {
            ans.push_back(s[idx]);
            rec(idx+1, s[idx], s, ans);
        }
    }
    
    string removeConsecutiveCharacter(string s)
    {
        string ans;
        rec(0, '0', s, ans);
        return ans;
    }
};

// App 2 : Two-pointers

class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        int i = 1, j = 0;
        for(; i < s.size(); ++i)
        {
            if(s[i] != s[j])
            {
                ++j;
                s[j] = s[i];
            }
        }
        s = s.substr(0, j+1);
        return s;
    }
};
