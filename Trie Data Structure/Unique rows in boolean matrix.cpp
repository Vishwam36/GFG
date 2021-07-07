// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1#
// Easy

/*
Given a binary matrix your task is to find all unique rows of the given matrix.

Example 1:
Input:
row = 3, col = 4 
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: 1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are 1 1 0 1 and
1 0 0 1 .

Your Task:
You only need to implement the given function uniqueRow(). The function takes three arguments the first argument is a matrix M and the next two arguments 
are row and col denoting the rows and columns of the matrix. The function should return the list of the unique row of the martrix. Do not read input, 
instead use the arguments given in the function.

Note: The drivers code print the rows "$" separated.

Expected Time Complexity: O(row * col)
Expected Auxiliary Space: O(row * col)

Constraints:
1<=row,col<=40
0<=M[][]<=1
*/

// App 1 : using set
// TC : O(M*N*log N)

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    set<vector<int> > s;
    vector<vector<int> > ans;
    for(int i = 0; i < row; ++i)
    {
        vector<int> v;
        for(int j = 0; j < col; ++j)
            v.push_back(M[i][j]);
        
        if(s.find(v) == s.end())
        {
            ans.push_back(v);
            s.insert(v);
        }
    }
    return ans;
}

// App 2 : Trie based
// TC : O(N*M)

struct TrieNode
{
    TrieNode* children[2];
};

bool insert(TrieNode* root, int a[], int n)
{
    bool flag = false;
    for(int i = 0; i < n; ++i)
    {
        if(!root->children[a[i]])
        {
            root->children[a[i]] = new TrieNode();
            flag = true; // its new row
        }
        
        root = root->children[a[i]];
    }
    return flag;
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int> > ans;
    vector<int> v(col);
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < row; ++i)
        if(insert(root, M[i], col))
        {
            for(int j = 0; j < col; ++j)
                v[j] = M[i][j];
            
            ans.push_back(v);
        }
    
    return ans;
}
