// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/max-rectangle/1#
// Good question

/*
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the 
first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1
*/

class Solution{
    public:
    // In this function we are calculating largest histogram area
    int largestRect(int a[], int n)
    {
        stack<int> s;
        int rs[n]; // right smaller
        int ls[n]; // left smaller
        ls[0] = -1;
        rs[n-1] = n;
        
        s.push(n-1);
        for(int i = n-2; i >= 0; --i)
        {
            while(!s.empty() && a[s.top()] >= a[i])
                s.pop();
            
            if(!s.empty())
                rs[i] = s.top();
            else
                rs[i] = n;
            
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
            
        s.push(0);
        for(int i = 1; i < n; ++i)
        {
            while(!s.empty() && a[s.top()] >= a[i])
                s.pop();
            
            if(!s.empty())
                ls[i] = s.top();
            else
                ls[i] = -1;
            
            s.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int area = (rs[i]-ls[i]-1)*a[i];
            ans = max(ans, area);
        }
        
        return ans;
    }
    
    int maxArea(int mat[MAX][MAX], int n, int m) 
    {
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(mat[i][j] == 1)
                    mat[i][j] += mat[i-1][j];
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, largestRect(mat[i], m));
        
        return ans;
    }
};
