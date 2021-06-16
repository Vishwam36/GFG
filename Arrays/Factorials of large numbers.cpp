// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#
// Decent

/*
Given an integer N, find its factorial.

Example 1:
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120


Example 2:
Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 ≤ N ≤ 1000
*/

// TC : O(N*M) where M is length of ans vector

class Solution {
public:
    void multiply(int x, vector<int> &v)
    {
        int carry = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            int num = v[i] * x + carry;
            v[i] = num % 10;
            carry = num/10;
        }
        
        string c = to_string(carry);
        reverse(c.begin(), c.end());
        for(char ch : c)
            v.push_back(ch-'0');
    }
    
    vector<int> factorial(int n)
    {
        vector<int> ans = {1};
        for(int i = 1; i <= n; ++i)
        {
            multiply(i, ans);
            while(ans.back() == 0)
                ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
