// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
// Easy

/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.

Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome 
or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 10^5
*/

class Solution{
  public:
    int length(Node* head)
    {
        int n = 0;
        while(head)
        {
            ++n;
            head = head->next;
        }
        return n;
    }
    
    Node* reverse(Node* head)
    {
        Node* curr = head, *pre = NULL, *post = head;
        while(curr)
        {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        return pre;
    }
    
    bool isPalindrome(Node *head)
    {
        int n = length(head);
        int half = n/2;
        Node* temp = head;
        while(half--)
            temp = temp->next;
        
        // reverse second half
        Node* rev;
        if(n%2 == 0)
            rev = reverse(temp);
        else
            rev = reverse(temp->next);
        
        half = n/2;
        while(half--)
        {
            if(head->data != rev->data)
                return false;
            
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};
