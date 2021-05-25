// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#
// Easy

/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 
Example 1:
Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

Example 2:
Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter 
and returns the total number of islands.
 
Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 
Constraints:
1 ≤ n, m ≤ 500
*/

class Solution
{
    public:
    int n, m;
    int ans = 0;
    
    int dx[8] = {0, 0, -1, 1, -1, 1, 1, -1};
    int dy[8] = {-1, 1, 0, 0, 1, -1, 1,-1};
    
    bool isValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    void bfs(int srcX, int srcY, vector<vector<char>>& grid, vector<vector<bool> > &vis)
    {
        vis[srcX][srcY] = 1;
        
        queue<pair<int, int> > q;
        q.push({srcX, srcY});
        
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            
            for(int i = 0; i < 8; ++i)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if(isValid(xx, yy) && grid[xx][yy] == '1' && !vis[xx][yy])
                {
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
                }
            }
        }
        ans++;
    }
    
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == '1' && !vis[i][j])
                    bfs(i, j, grid, vis);
        
        return ans;
    }
};
