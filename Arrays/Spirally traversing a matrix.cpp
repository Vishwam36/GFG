// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> spiral;
        int up = 0, down = r - 1, left = 0, right = c - 1;
        while(up <= down && left <= right)
        {
            // left -> right
            for(int i = left; i <= right; ++i)
            {
                spiral.push_back(matrix[up][i]);
            }
            ++up;
            
            // up -> down
            for(int i = up; i <= down; ++i)
            {
                spiral.push_back(matrix[i][right]);
            }
            --right;
            
            // right -> left
            if(left <= right && up <= down)
            {
                for(int i = right; i >= left; --i)
                {
                    spiral.push_back(matrix[down][i]);
                }
                --down;
            }
            
            // down -> up
            if(up <= down && left <= right)
            {
                for(int i = down; i >= up; --i)
                {
                    spiral.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return spiral;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
