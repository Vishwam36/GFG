// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
// Decent

/*
Given a square chessboard, the initial position of Knight and position of a target. 
Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:
Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight 
(KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters 
and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2). 

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/

class Solution 
{
    public:
    int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
    int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
    
    bool isValid(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int steps = 0, xi = KnightPos[0]-1, yi = KnightPos[1]-1, xf = TargetPos[0]-1, yf = TargetPos[1]-1;
	    vector<vector<bool> > vis(n, vector<bool>(n, false));
	    queue<pair<int, int> > q;
	    q.push({xi, yi});
	    vis[xi][yi] = 1;
	    
	    while(!q.empty())
	    {
	        int len = q.size();
	        
	        for(int i = 0; i < len; ++i)
	        {
	            pair<int, int> p = q.front();
	            int xc = p.first;
	            int yc = p.second;
	            q.pop();
	            
	            if(xc == xf && yc == yf)
	                return steps;
	            
	            for(int j = 0; j < 8; ++j)
	            {
	                int nx = xc + dx[j];
	                int ny = yc + dy[j];
	                
	                if(isValid(nx, ny, n) && !vis[nx][ny])
	                {
	                    q.push({nx, ny});
	                    vis[nx][ny] = 1;
	                }
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};
