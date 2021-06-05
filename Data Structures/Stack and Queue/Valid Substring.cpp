// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/valid-substring0624/1#
// Decent

/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of smallest the valid substring ( ) is 2.

Example 1:
Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.

Example 2:
Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.

Your Task:  
You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.

Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1)   

Constraints:
1 <= |S| <= 10^5
*/

class Solution {
  public:
    int findMaxLen(string s) 
    {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(!st.empty())
                    st.pop();
                if(!st.empty())
                    ans = max(ans, i-st.top());
                else
                    st.push(i);
            }
        }
        return ans;
    }
};
