// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#
// Decent
// Greedy wont work :)

/*
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

Example 1:
Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5

Example 2:
Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3 
with 5, 4 with 5 and finally 3 with 4 

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns 
a string containing the largest number formed by perfoming the swap operation at most k times.

Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10
*/

class Solution
{
    public:
    string max_so_far;
    
    vector<int> find_largest(int i, string &s) // find indices with largest digit
    {
        vector<int> ans;
        char ch = '0';
        for(int j = i; j < s.size(); ++j)
            if(s[j] >= ch)
                ch = s[j];
        
        for(; i < s.size(); ++i)
            if(s[i] == ch)
                ans.push_back(i);
        
        return ans;
    }
    
    void rec(int idx, string &s, int k)
    {
        if(k == 0 || idx >= s.size())
        {
            max_so_far = max(max_so_far, s);
            return;
        }
        
        vector<int> v = find_largest(idx, s); // we start from idx because idx itself can be maximum from [idx, ..]
        
        for(int i = 0; i < v.size(); ++i)
        {
            if(s[idx] == s[v[i]]) // no swap needed
                rec(idx+1, s, k);
            else
            {
                swap(s[idx], s[v[i]]);
                rec(idx+1, s, k-1);
                swap(s[idx], s[v[i]]);
            }
        }
    }
    
    string findMaximumNum(string s, int k)
    {
        max_so_far = s;
        rec(0, s, k);
        return max_so_far;
    }
};
