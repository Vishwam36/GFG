// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
// Decent

/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:
Input:
LinkedList: 4->5->6
Output: 457 

Example 2:
Input:
LinkedList: 1->2->3
Output: 124 

Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument 
and returns the head of the modified linked list.The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10000
*/

/* 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Hint : 
// 1. Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
// 2. Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. 
//    Keep moving to the next node while there is a carry.
// 3. Reverse modified linked list and return head.

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node* pre = NULL, *curr = head, *post, *temp;
        while(curr != NULL) // reverse LL
        {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        
        curr = pre;
        int carry = 0, sum = 1;
        
        while(curr != NULL) // update the values 
        {
            temp = curr;
            sum += carry + curr->data;
            curr->data = sum % 10;
            carry = sum / 10;
            curr = curr->next;
            sum = 0;
        }
        
        if(carry) // if extra carry is there then add extra node
        {
            Node* extra = new Node(carry);
            temp->next = extra; // add extra next to last node
        }
        
        curr = pre;
        pre = NULL;
        while(curr) // again reverse
        {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        
        return pre;
    }
};
