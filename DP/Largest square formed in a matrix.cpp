// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1#
// Decent
// 2 approaches, DP and non-DP

/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:
Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.

Example 2:
Input: n = 2, m = 2
mat = {{0, 0}, 
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maxSquare() which takes n, m and mat as input parameters and 
returns the size of the maximum square sub-matrix of given matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 50
0 ≤ mat[i][j] ≤ 1 
*/

// App 1 : DP
// REF : https://www.youtube.com/watch?v=UagRoA3C5VQ

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < m; ++j)
                if(mat[i][j] == 1)
                    mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1])) + 1;
        
        // mat[i][j] indicates largest possible square which can be made taking (i,j) as bottom right corner
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, *max_element(mat[i].begin(), mat[i].end()));
        
        return ans;
    }
};


// App 2 : Same approach as : https://practice.geeksforgeeks.org/viewSol.php?subId=7b862570b365873e76c77701127a94b9&pid=700288&user=mvishwam36
// Which is "Max rectangle" problem

class Solution{
public:
	// largest histogram method
    int maxArea(vector<int> &v, int m)
    {
        stack<int> s;
        vector<int> ls(m), rs(m);
        
        rs[m-1] = m;
        s.push(m-1);
        for(int i = m-2; i >= 0; --i)
        {
            while(!s.empty() && v[s.top()] >= v[i])
                s.pop();
            
            if(!s.empty())
                rs[i] = s.top();
            else
                rs[i] = m;
            
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        ls[0] = -1;
        s.push(0);
        for(int i = 1; i < m; ++i)
        {
            while(!s.empty() && v[s.top()] >= v[i])
                s.pop();
            
            if(!s.empty())
                ls[i] = s.top();
            else
                ls[i] = -1;
            
            s.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            int width = rs[i]-ls[i]-1;
            ans = max(ans, min(width, v[i])); // we need square, thats why we are taking min(width, height)
        }
        return ans;
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        for(int j = 0; j < m; ++j)
            for(int i = 1; i < n; ++i)
                if(mat[i][j] != 0)
                    mat[i][j] += mat[i-1][j];
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, maxArea(mat[i], m));
        
        return ans;
    }
};
