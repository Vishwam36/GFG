// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#
// Easy

/*
Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes.
Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
ISomorphicTrees

Example 1:
Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No

Example 2:
Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: Yes

Your Task:
You don't need to read input or print anything. Your task is to complete the function isomorphic() that takes the root nodes of both the Binary Trees 
as its input and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if the returned values are true, 
otherwise false.)

Expected Time Complexity: O(min(M, N)) where M and N are the sizes of the two trees.
Expected Auxiliary Space: O(min(H1, H2)) where H1 and H2 are the heights of the two trees.

Constraints:
1<=Number of nodes<=10^5
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *r1, Node *r2)
    {
        if(!r1 && !r2)
            return true;
        if(r1 && !r2)
            return false;
        if(r2 && !r1)
            return false;
        if(r1->data != r2->data)
            return false;
        
        bool b1 = isIsomorphic(r1->left, r2->left) 
                && isIsomorphic(r1->right, r2->right);
        bool b2 = isIsomorphic(r1->left, r2->right) 
                && isIsomorphic(r1->left, r2->right);
    
        return b1 || b2;
    }
};
