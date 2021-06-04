// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/check-for-bst/1#
// Easy

// Check if given Tree is BST or not (No duplicates).

bool rec(Node* root, int minLimit, int maxLimit)
{
    if(!root)
        return true;
        
    if(root->data <= minLimit || root->data >= maxLimit)
        return false;
    
    return rec(root->left, minLimit, root->data) 
        && rec(root->right, root->data, maxLimit);
}

class Solution
{
    public:
    bool isBST(Node* root) 
    {
        return rec(root, INT_MIN, INT_MAX);
    }
};
