// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
// Decent, standard

/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 
'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it 
while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters 
and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/

class Solution{
    public:
    vector<string> ans;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    string dir = "RLDU";
    
    bool isValid(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    void rec(vector<vector<int>> &m, int n, int row, int col, string temp, vector<vector<bool> > &vis)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < 4; ++j)
        {
            int x = row + dx[j];
            int y = col + dy[j];
            
            if(isValid(x, y, n) && !vis[x][y] && m[x][y] == 1)
            {
                vis[x][y] = 1;
                temp.push_back(dir[j]);
                rec(m, n, x, y, temp, vis);
                temp.pop_back();
                vis[x][y] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> no_ans;
        no_ans.push_back("-1");
        
        if(m[0][0] == 0)
            return no_ans;
        
        vector<vector<bool> > vis(n, vector<bool>(n, false));
        vis[0][0] = 1;
        rec(m, n, 0, 0, "", vis);
        
        if(ans.size() == 0)
            return no_ans;
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
