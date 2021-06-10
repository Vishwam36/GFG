// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1#
// Easy

/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. 
Word is said be found in a direction if all characters match in this direction (not in zig-zag form). 
The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 
Example 1:
Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Expalnation: From (0,0) one can find "abc"
in horizontally right direction.

Example 2:
Input: grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
,word = "abe"
Output: {{0,0},{0,2},{1,0}}
Explanation: From (0,0) one can find "abe" in 
right-down diagonal. From (0,2) one can
find "abe" in left-down diagonal. From
(1,0) one can find "abe" in Horizontally right 
direction.

Your Task:
You don't need to read or print anyhting, Your task is to complete the function searchWord() which takes grid and word as input parameters and 
returns a list containg the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions strating from the same coordinates, 
the list should contain the coordinates only once. 

Expected Time Complexity: O(n*m*k) where k is constant
Exected Space Complexity: O(1)

Constraints:
1 <= n <= m <= 100
1 <= |word| <= 10
*/

// This is just a possible approach otherwise there is no need of graph and DFS here.
// Ref : https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
// Its a matrix question

class Solution {
public:
    int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dj[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int n, m;
    
    vector<vector<int> > ans;

    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    bool dfs(int srcx, int srcy, vector<vector<char>> &grid, string &word, int idx, int dir)
    {
        if(idx == word.size())
            return true;
        
        if(dir != -1) // direction dicided
        {
            int newi = srcx + di[dir];
            int newj = srcy + dj[dir];
            
            if(isValid(newi, newj) && word[idx] == grid[newi][newj])
                if(dfs(newi, newj, grid, word, idx+1, dir))
                    return true;
            
            return false;
        }
        
        // direction not dicided
        for(int i = 0; i < 8; ++i)
        {
            int newi = srcx + di[i];
            int newj = srcy + dj[i];
            
            if(isValid(newi, newj) && word[idx] == grid[newi][newj])
                if(dfs(newi, newj, grid, word, idx+1, i))
                    return true;
        }
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	    n = grid.size(), m = grid[0].size();

	    for(int i = 0; i < n; ++i)
	        for(int j = 0; j < m; ++j)
	            if(grid[i][j] == word[0] && dfs(i, j, grid, word, 1, -1))
	                ans.push_back({i, j});
	    
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};
