// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#
// Good question

/*
Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

Example 1:
Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail

Example 2:
Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the 
optimal choice.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maximumSumRectangle() which takes the number R, C, and the 2D matrix M 
as input parameters and returns the maximum sum subarray.

Expected Time Complexity:O(R*R*C)
Expected Auxillary Space:O(R*C)

Constraints:
1<=R,C<=500
-1000<=M[i][j]<=1000
*/

// Using vector int kadane is giving TLE but passing array will give success :( 
// Why GFG Why ???
// Anyway learn the lesson, use arrays as much as possible

class Solution {
  public:
    int kadane(int v[], int n)
    {
        int maxSum = *max_element(v, v+n), tempSum = 0;
        
        for(int i = 0; i < n; ++i)
        {
            tempSum += v[i];
            maxSum = max(tempSum, maxSum);
            
            if(tempSum < 0)
                tempSum = 0;
        }
        return maxSum;
    }
    
    int maximumSumRectangle(int r, int c, vector<vector<int>> m) 
    {
        int ans = INT_MIN;
        for(int i = 0; i < r; ++i)
        {
            int sum[c];
            memset(sum, 0, sizeof(sum));
            
            for(int j = i; j < r; ++j)
            {
                for(int col = 0; col < c; ++col)
                {
                    sum[col] += m[j][col];
                }
                ans = max(ans, kadane(sum, c));
            }
        }
        
        return ans;
    }
};
