// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1#
// Easy

/*
Given a Circular Linked List of size N. The task is to delete the given node (excluding the first and last node) in circular linked list and then print the 
reverse of the circular linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the 
size of the circular linked list. The next line contains n space separated integers forming the circular linked list. The last line contains the node to be 
deleted in between the circular linked list.

Output:
Print the reverse of the circular linked list with the deleted node.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= data <= 100

Example:
Input:
2
5
2 5 7 8 10
8
4
1 7 8 10
8

Output:
10 7 5 2 
10 7 1

Explanation:
Testcase 1: After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2.
*/

void deleteNode(struct Node **head, int key)
{
    Node* temp = *head, *pre = NULL;
    while(temp->data != key)
    {
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    temp->next = NULL;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    Node* head = *head_ref;
    Node* temp = head->next, *pre = head, *post;
    
    while(temp != head)
    {
        post = temp->next;
        temp->next = pre;
        pre = temp;
        temp = post;
    }
    temp->next = pre;
    *head_ref = head->next;
}
