// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1/#
// IMP, Rabin-Karp or Rolling Hash
// REF : https://www.youtube.com/watch?v=BQ9E-2umSWc

/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the 
text string. For printing, Starting Index of a string should be taken as 1.

Example 1:
Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 

Example 2:
Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string S and the string pat as inputs 
and returns an array denoting the start indices (1-based) of substring pat in the string S. 

Expected Time Complexity: O(|S|*|pat|).
Expected Auxiliary Space: O(1).

Constraints:
1<=|S|<=10^5
1<=|pat|<|S|
*/

// Rabin-Karp / Rolling Hash algorithm

class Solution
{
    public:
    long long p = 1000000007; // prime number
    
    long long myPow(int base, int power)
    {
        if(power == 0)
            return 1;
        
        if(power % 2 == 0)
        {
            long long ans = myPow(base, power/2);
            return (ans * ans) % p;
        }
        else
        {
            long long ans = myPow(base, power/2);
            return (((ans * ans) % p) * base) % p;
        }
    }
    
    bool check(string &pat, string &txt, int i, int j)
    {
        int k = 0;
        while(k < pat.size())
            if(pat[k++] != txt[i++])
                return false;
        
        return true;
    }
    
    vector <int> search(string pat, string txt)
    {
        int np = pat.size(), nt = txt.size();
        vector<int> ans;
        
        long long pat_hash = 0, hash = 0;
        for(int i = np-1; i >= 0; --i)
        {
            long long ch = pat[i]-'a'+1;
            pat_hash += (myPow(26, np-i) * ch) % p;
            pat_hash %= p;
        }
        
        for(int i = np-1; i >= 0; --i)
        {
            long long ch = txt[i]-'a'+1;
            hash += (myPow(26, np-i) * ch) % p;
        }
        
        if(pat_hash == hash)
            if(check(pat, txt, 0, np-1))
                ans.push_back(0);
        
        for(int i = np; i < nt; ++i)
        {
            long long next = txt[i]-'a'+1; // next char to be added
            long long pre = txt[i-np]-'a'+1; // previous char to be removed
            
            hash -= (myPow(26, np) * pre); // remove pre;
            hash = (hash + p) % p;
            
            hash = (hash * 26) % p; // left-shift
            
            hash += next * 26; // add new char
            hash = (hash + p) % p;
            
            if(pat_hash == hash)
                if(check(pat, txt, i-np+1, i))
                    ans.push_back(i-np+1);
        }
        
        for(int i = 0; i < ans.size(); ++i)
            ans[i] += 1; // make 1-indexed
        
        if(ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};


// Boyer Moore algorithm

class Solution
{
    public:
    unordered_map<char, int> bad_match;
    
    void init(string pat)
    {
        for(int i = 0; i < pat.size(); ++i)
            bad_match[pat[i]] = pat.size() - i -1;
        
        bad_match[pat.back()] = 1; // we cant keep 0 here
    }
    
    vector <int> search(string pat, string txt)
    {
        init(pat);
        int np = pat.size(), nt = txt.size();
        vector<int> ans;
        for(int i = 0; i < nt;)
        {
            int j = np-1;
            
            if(j+i >= nt)
                break;
            
            while(j >= 0 && pat[j] == txt[j+i])
                --j;
            
            if(j < 0)
            {
                ans.push_back(i+1);
                ++i;
                continue;
            }
            
            if(bad_match.find(txt[i+np-1]) != bad_match.end())
                i += bad_match[txt[i+np-1]];
            else
                i += pat.size();
        }
        
        if(ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};
