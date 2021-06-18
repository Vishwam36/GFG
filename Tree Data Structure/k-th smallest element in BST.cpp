// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#
// Easy

class Solution{
  public:
    int ans, copy;
    
    void rec(Node* root)
    {
        if(!root || copy == 0)
            return;
        
        rec(root->left);
        
        copy--;
        if(copy == 0)
            ans = root->data;
        
        rec(root->right);
    }
    
    int KthSmallestElement(Node *root, int k)
    {
        copy = k;
        rec(root);
        return copy <= 0 ? ans : -1;
    }
};
