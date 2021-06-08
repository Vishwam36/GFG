// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#
// Easy BFS

/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at 
indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

Example 1:
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.

Example 2:
Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and 
returns the minimum time to rot all the fresh oranges. If not possible returns -1.

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n, m ≤ 500
*/

class Solution 
{
    public:
    int n, m;
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        
        int vis = 0;
        queue<pair<int, int> > q;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 0)
                    vis++;
        
        int t = -1;
        while(!q.empty())
        {
            int len = q.size();
            while(len--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                vis++;
            
                for(int k = 0; k < 4; ++k)
                {
                    int new_i = i + di[k];
                    int new_j = j + dj[k];
                
                    if(isValid(new_i, new_j) && grid[new_i][new_j] == 1)
                    {
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                    }
                }
            }
            ++t;
        }
        return vis == n*m ? t : -1;
    }
};
