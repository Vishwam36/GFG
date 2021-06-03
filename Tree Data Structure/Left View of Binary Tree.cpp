// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
// Easy

/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is 
to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
   \
     8   

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3

Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

// App 1 : Queue approach

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(!root)
        return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        
        int len = q.size();
        for(int i = 0; i < len; ++i)
        {
            Node* curr = q.front(); q.pop();
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    
    return ans;
}


// App 2 : Recursive approach
// TC : O(N)
// SC : O(N) (for call stack of recursion)

int levels_visited = 0;
vector<int> ans;

void rec(Node* root, int level)
{
    if(!root)
        return;
    
    if(level == levels_visited)
    {
        ans.push_back(root->data);
        levels_visited++;
    }
    
    rec(root->left, level+1);
    rec(root->right, level+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    ans.clear();
    levels_visited = 0;
    rec(root, 0);
    return ans;
}
