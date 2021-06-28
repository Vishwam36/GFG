// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/transform-string5648/1#
// Decent
// TC : O(N)
// SC : O(1)

/*
Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation 
is selecting a character from string A and inserting it in the beginning of string A.

Example 1:
Input:
A = "abd"
B = "bad"
Output: 1
Explanation: The conversion can take place in
1 operation: Pick 'b' and place it at the front.

Example 2:
Input:
A = "GeeksForGeeks"
B = "ForGeeksGeeks"
Output: 3
Explanation: The conversion can take
place in 3 operations:
Pick 'r' and place it at the front.
A = "rGeeksFoGeeks"
Pick 'o' and place it at the front.
A = "orGeeksFGeeks"
Pick 'F' and place it at the front.
A = "ForGeeksGeeks"

Your Task: 
You dont need to read input or print anything. Complete the function transform() which takes two strings A and B as input parameters and returns the minimum 
number of steps required to transform A into B. If transformation is not possible return -1.

Expected Time Complexity: O(N) where N is max(length of A, length of B) 
Expected Auxiliary Space: O(1)  

Constraints:
1<= A.length(), B.length() <= 10^4
*/

class Solution
{
    public:
    int transform (string A, string B)
    {
        if(A.size() != B.size())
            return -1;
        
        vector<int> f(256, 0);
        for(int i = 0; i < A.size(); ++i)
        {
            f[A[i]]++;
            f[B[i]]--;
        }
        for(int i = 0; i < 256; ++i)
            if(f[i])
                return -1;
        
        int ans = 0;
        for(int i = A.size()-1, j = B.size()-1; i >= 0; )
        {
            if(A[i] == B[j])
            {
                --i;
                --j;
            }
            else
            {
                --i;
                ++ans;
            }
        }
        return ans;
    }
};
