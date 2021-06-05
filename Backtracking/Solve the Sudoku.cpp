// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1#
// Good question

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

class Solution 
{
    public:
    bool can(int num, int r, int c, int grid[N][N])
    {
        for(int i = 0; i < N; ++i)
            if(grid[r][i] == num)
                return false;
        
        for(int i = 0; i < N; ++i)
            if(grid[i][c] == num)
                return false;
        
        for(int i = (r/3)*3; i < (r/3)*3 + 3; ++i)
            for(int j = (c/3)*3; j < (c/3)*3 + 3; ++j)
                if(grid[i][j] == num)
                    return false;
        
        return true;
    }
    
    bool rec(int row, int col, int grid[N][N])
    {
        if(row == N)
            return true;
        
        if(col == N)
            return rec(row+1, 0, grid);
        
        if(grid[row][col] != 0)
            return rec(row, col+1, grid);
        
        for(int num = 1; num <= 9; ++num)
        {
            if(can(num, row, col, grid))
            {
                grid[row][col] = num;
                if(rec(row, col+1, grid))
                    return true;
                
                grid[row][col] = 0;
            }
        }
            
        return false;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        return rec(0, 0, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cout << grid[i][j] << " ";
    }
};
