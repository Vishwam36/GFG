// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#
// Good LL implementation

/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.

Example 2:
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.

Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
*/

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

// TC : O(N logN)
// SC : O(1)

class Solution{
  public:
    int length(Node* head)
    {
        int n = 0;
        while(head)
        {
            head = head->next;
            ++n;
        }
        return n;
    }
    
    Node* merge(Node* t1, Node* t2)
    {
        Node* newHead = new Node(-1);
        Node* temp = newHead;
        
        while(t1 && t2)
        {
            if(t1->data <= t2->data)
            {
                temp->next = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        
        if(t1)
            temp->next = t1;
        else
            temp->next = t2;
        
        return newHead->next;
    }
    
    Node* mergeSort(Node* head) 
    {
        if(head->next == NULL)
            return head;
    
        Node* head2 = head, *pre;
        
        int n = length(head);
        for(int i = 0; i < n/2; ++i)
        {
            pre = head2;
            head2 = head2->next;
        }
        
        pre->next = NULL;
        
        head = mergeSort(head);
        head2 = mergeSort(head2);
        
        return merge(head, head2);
    }
};
