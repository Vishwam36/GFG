// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
// Good question

/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the 
	left subtree over the right subtree. 
    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
    Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always 
	travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:
Input:
        1
      /   \
     2     3    
   
Output: 1 2 3

Example 2:
Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5
*/

// App 1 : Recursive

class Solution {
public:
    vector<int> ans;
    
    void getLeft(Node* root)
    {
        if(!root)
            return;
        
        if(root->left)
        {
            ans.push_back(root->data);
            getLeft(root->left);
        }
        else if(root->right)
        {
            ans.push_back(root->data);
            getLeft(root->right);
        }
    }
    
    void getRight(Node* root)
    {
        if(!root)
            return;
        
        if(root->right)
        {
            getRight(root->right);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            getRight(root->left);
            ans.push_back(root->data);
        }
    }
    
    void getLeaves(Node* root)
    {
        if(!root)
            return;
        
        getLeaves(root->left);
        
        if(root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
        
        getLeaves(root->right);
    }
    
    vector <int> printBoundary(Node *root)
    {
        if(!root)
            return ans;
        else
            ans.push_back(root->data);
        
        getLeft(root->left);
        getLeaves(root);
        getRight(root->right);
        
        return ans;
    }
};


// App 2 : Queue approach

class Solution {
public:
    vector<Node*> leaf, left, right;
    
    void getLeaves(Node* root)
    {
        if(!root)
            return;
        
        getLeaves(root->left);
        
        if(!root->left && !root->right)
            leaf.push_back(root);
        
        getLeaves(root->right);
    }
    
    void leftView(Node* root)
    {
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        int level = 0;
        
        if(root->left == NULL)
        {
            left.push_back(root);
            return;
        }
        
        while(!q.empty())
        {
            int len = q.size();
            
            while(len--)
            {
                Node* curr = q.front().first;
                int currLevel = q.front().second; 
                q.pop();
                
                if(level == currLevel)
                {
                    left.push_back(curr);
                    level++;
                }
                
                if(curr->left)
                    q.push({curr->left, currLevel+1});
                if(curr->right)
                    q.push({curr->right, currLevel+1});
            }
        }
    }
    
    void rightView(Node* root)
    {
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        int level = 0;
        
        if(root->right == NULL)
        {
            right.push_back(root);
            return;
        }
        
        while(!q.empty())
        {
            int len = q.size();
            
            while(len--)
            {
                Node* curr = q.front().first;
                int currLevel = q.front().second; 
                q.pop();
                
                if(level == currLevel)
                {
                    right.push_back(curr);
                    level++;
                }
                
                if(curr->right)
                    q.push({curr->right, currLevel+1});
                if(curr->left)
                    q.push({curr->left, currLevel+1});
            }
        }
    }
    
    vector <int> printBoundary(Node *root)
    {
        getLeaves(root);
        leftView(root);
        rightView(root);
        
        vector<int> ans;
        int i = 0;
        
        for(i = 0; i < left.size(); ++i)
            ans.push_back(left[i]->data);
        
        if(leaf[0] == left.back())
            i = 1;
        else
            i = 0;
        
        for(; i < leaf.size(); ++i)
            ans.push_back(leaf[i]->data);
        
        for(i = right.size()-1; i >= 0; --i)
            if(right[i] == leaf.back())
                break;
        
        if(right[i] == leaf.back())
            i--;
        else
            i = right.size()-1;
        
        for(; i >= 0; --i)
            if(right[i] != leaf.back() && right[i] != root)
                ans.push_back(right[i]->data);
        
        return ans;
    }
};
