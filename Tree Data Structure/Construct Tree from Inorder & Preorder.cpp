// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1#
// Decent

/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:
Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1

Example 2:
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5

Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node 
to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
*/

class Solution{
    public:
    int in_index(int x, int l, int r, int in[])
    {
        for(int i = l; l <= r; ++i)
            if(in[i] == x)
                return i;
    }
    
    Node* rec(int in[], int pre[], int l_in, int r_in, int l_pre, int r_pre)
    {
        if(l_pre > r_pre)
            return NULL;
        
        Node* root = new Node(pre[l_pre]);
        
        int idx = in_index(pre[l_pre], l_in, r_in, in);
        int leftSize = idx-l_in;
        
        root->left = rec(in, pre, l_in, idx-1, l_pre+1, l_pre+leftSize);
        root->right = rec(in, pre, idx+1, r_in, l_pre+leftSize+1, r_pre);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        return rec(in, pre, 0, n-1, 0, n-1);
    }
};
