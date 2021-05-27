// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
// Decent

/*
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5
Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

Example 2:
Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C 
along with the 2D matrixas input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)

Constraints:
1<= R,C <=150
1<= matrix[i][j] <=2000
*/

/*
Algorithm:
    1. First, we find the minimum and maximum elements in the matrix. The minimum element can be found by comparing the first element of each row, 
       and by comparing the last element of each row.
    2. Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers 
       less than our mid. And accordingly change the min or max.
    3. For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than 
       that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected number, 
       else the median must be less than or equal to the selected number. 
*/
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int minEle = INT_MAX, maxEle = INT_MIN;
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; ++i)
        {
            minEle = min(minEle, matrix[i][0]);
            maxEle = max(maxEle, matrix[i][m-1]);
        }
        
        int low = minEle, high = maxEle, mid;
        
        while(high > low)
        {
            mid = (high+low)/2;
            int total = 0;
            
            for(int i = 0; i < n; ++i)
                total += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            
            if(total < (m*n + 1)/2)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};
