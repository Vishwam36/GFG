// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
// Easy and basic just added for quick reference

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// root node is given
vector<int> levelOrder(Node* root)
{
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr = q.front();
        ans.push_back(curr -> data);
        q.pop();
        
        if(curr -> left != NULL)
            q.push(curr -> left);
            
        if(curr -> right != NULL)
            q.push(curr -> right);
    }
    
    return ans;
}
