// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#
// Good question

/*
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once 
and are distinct. Find the other two numbers.

Example 1:
Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.

Example 2:
Input:
N = 1
arr[] = {2, 1, 3, 2}
Output:
1 3
Explanation:
1 3 occur exactly once.

Your Task:
You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter 
and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)

Constraints:
1 <= length of array <= 106 
1 <= Elements in array <= 5 * 10^6
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int x_xor_y = 0, x = 0, y = 0;
        for(auto val : nums)
            x_xor_y ^= val;
        
        int rsbm = x_xor_y & ~(x_xor_y-1); // rightmost set bit mask
        
        for(auto val : nums)
            if(((val) & (rsbm)) == 0)
                x ^= val;
            else
                y ^= val;
        
        return {min(x,y), max(x,y)};
    }
};
