// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#
// Easy

/*
Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out ofthe 
resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

Example 1:
Input:
Circular LinkedList: 1->5->7
Output:
1 5
7

Example 2:
Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

Your Task:
Your task is to complete the given function splitList(), which takes 3 input parameters: The address of the head of the linked list, addresses of the head of 
the first and second halved resultant lists and Set the head1_ref and head2_ref to the first resultant list and second resultant list respectively.

Expected Time Complexity: O(N)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 100
*/

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head->next, *fast = head->next->next, *pre = NULL;
    while(slow != fast)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    
    slow = head, fast = head->next, pre = NULL;
    while(fast && fast->next)
    {
        slow = slow->next;
        pre = fast;
        fast = fast->next->next;
    }
    
    if(fast)
        fast->next = slow->next;
    else
        pre->next->next = slow->next;
    
    *head2_ref = slow->next;
    
    slow->next = head;
    *head1_ref = head;   
}
