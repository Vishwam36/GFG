// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#
// Easy

/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
Input:
        3
      /   \
     2     1
Output:
3 1 2

Example 2:
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as 
its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^4
*/

vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans, temp;
	
	queue<Node*> q;
	q.push(root);
	int level = 0;
	
	while(!q.empty())
	{
	    int len = q.size();
	    while(len--)
	    {
	        Node* curr = q.front(); q.pop();
	        temp.push_back(curr->data);
	        
	        if(curr->left)
	            q.push(curr->left);
	        if(curr->right)
	            q.push(curr->right);
	    }
	    if(level % 2 == 0)
	    {
	        for(auto val : temp)
	            ans.push_back(val);
	    }
	    else
	    {
	        reverse(temp.begin(), temp.end());
	        for(auto val : temp)
	            ans.push_back(val);
	    }
	    temp.clear();
	    ++level;
	}
	return ans;
}
