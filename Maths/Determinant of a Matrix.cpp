// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1#
// Good question

/*
Given a square matrix of size N x N. The task is to find the determinant of this matrix.

Example 1:
Input:
N = 4
matrix[][] = {{1, 0, 2, -1},
              {3, 0, 0, 5},
              {2, 1, 4, -3},
              {1, 0, 5, 0}}
Output: 30
Explanation:
Determinant of the given matrix is 30.

Example 2:
Input:
N = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6},
              {7, 10, 9}}
Output: 12
Explanation:
Determinant of the given matrix is 12.

Your Task:
You don't need to read input or print anything. Complete the function determinantOfMatrix() that takes matrix and its size n as input parameters and 
returns the determinant of the matrix.

Expected Time Complexity: O(N^4)
Expected Auxiliary Space: O(N^2)

Constraints:
1 <= N <= 8
-10 <= mat[i][j] <= 10
*/

class Solution
{   
    public:
    // get cofactor matrix i.e matrix except row r and row c
    void cofactor(vector<vector<int> > &temp, int r, int c, vector<vector<int> > &m)
    {
        int y = 0;
        for(int i = 1; i < m.size(); ++i)
        {
            y = 0;
            for(int j = 0; j < m.size(); ++j)
            {
                if(i != r && j != c)
                {
                    temp[i-1][y++] = m[i][j];
                }
            }
        }
    }

    int determinantOfMatrix(vector<vector<int> > m, int n)
    {
        if(n == 1)
            return m[0][0];
    
        int sign = 1;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            vector<vector<int> > temp(n-1, vector<int> (n-1));
            cofactor(temp, 0, i, m);
            ans += sign * m[0][i] * determinantOfMatrix(temp, n-1);
            sign = -sign;
        }
        return ans;
    }
};
