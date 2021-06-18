// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#
// Easy

class Solution
{
    public:
    int copy, ans;
    
    void rec(Node* root)
    {
        if(!root || copy == 0)
            return;
        
        rec(root->right);
        
        --copy;
        if(copy == 0)
            ans = root->data;
        
        rec(root->left);
    }
    
    int kthLargest(Node *root, int k)
    {
        copy = k;
        rec(root);
        return copy <= 0 ? ans : -1;
    }
};
