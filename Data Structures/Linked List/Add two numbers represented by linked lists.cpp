// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
// Good

/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation 
of the addition of two input numbers from the last.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).

Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000
*/

/* node for linked list:
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* pre = NULL, *curr = head, *post;
        while(curr)
        {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        return pre;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* rev_first = reverse(first);
        Node* rev_second = reverse(second);
        
        Node* t1 = rev_first, *t2 = rev_second;
        Node* res = new Node(-1);
        Node* t = res;
        int carry = 0;
        while(t1 && t2)
        {
            int sum = t1->data + t2->data + carry;
            carry = sum/10;
            Node* temp = new Node(sum%10);
            t->next = temp;
            t = t->next;
            sum %= 10;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        while(t1)
        {
            int sum = t1->data + carry;
            carry = sum/10;
            Node* temp = new Node(sum%10);
            t->next = temp;
            t = t->next;
            sum %= 10;
            t1 = t1->next;
        }
        
        while(t2)
        {
            int sum = t2->data + carry;
            carry = sum/10;
            Node* temp = new Node(sum%10%10);
            t->next = temp;
            t = t->next;
            sum %= 10;
            t2 = t2->next;
        }
        
        while(carry)
        {
            Node* temp = new Node(carry%10);
            carry /= 10;
            t->next = temp;
            t = t->next;
        }
        
        res = reverse(res->next);
        return res;
    }
};
