// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#
// Decent

/*
You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of 
the first character with the second character and replace all the occurences of the second character with the first character. 
Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose ‘a’ and ‘c’ and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible. 

Example 2:
Input:
A = "abba"
Output: "abba"
Explanation:
In abba, we can get baab after doing the 
replacement operation once for ‘a’ and ‘b’ 
but that is not lexicographically smaller 
than abba. So, the answer is abba. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function chooseandswap() which takes the string A as input parameters 
and returns the lexicographically smallest string that is possible after doing the operation at most once.

Expected Time Complexity: O(|A|) length of the string A
Expected Auxiliary Space: O(1)

Constraints:
1<= |A| <=105
*/

class Solution{
public:
    string chooseandswap(string s)
    {
        // To store the first occurence of every character of s
        int f[26];
        memset(f, -1, sizeof(f));
        
        for(int i = 0; i < s.size(); ++i)
            if(f[s[i] - 'a'] == -1)
                f[s[i] - 'a'] = i;
        
        char c1 = '0', c2 = '0';
        
        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = 0; j < s[i]-'a'; ++j)
            {
                if(f[j] > i)
                {
                    c1 = s[i];
                    c2 = j+'a';
                    break;
                }
            }
            if(c1 != '0')
                break;
        }
        
        for(int i = 0; i < s.size() && c1 != '0'; ++i)
            if(s[i] == c1)
                s[i] = c2;
            else if(s[i] == c2)
                s[i] = c1;
        
        return s;
    }
    
};
