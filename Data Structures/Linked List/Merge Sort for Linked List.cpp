// By Vishwam Shriram Mundada
// https://www.geeksforgeeks.org/merge-sort-for-linked-list/
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

class Solution{
  public:
    int length(Node* head)
    {
        int n = 0;
        while(head)
        {
            head = head->next;
            n++;
        }
        return n;
    }
    
    void merge(Node* head, Node* left, Node* right)
    {
        Node* t1 = left, *t2 = right, *t3 = head;
        
        while(t1 && t2)
        {
            if(t1->data <= t2->data)
            {
                t3->data = t1->data;
                t1 = t1->next;
            }
            else
            {
                t3->data = t2->data;
                t2 = t2->next;
            }
            t3 = t3->next;
        }
        
        while(t1)
        {
            t3->data = t1->data;
            t1 = t1->next;
            t3 = t3->next;
        }
        
        while(t2)
        {
            t3->data = t2->data;
            t2 = t2->next;
            t3 = t3->next;
        }
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        int n = length(head);
        int mid = n % 2 == 0 ? n/2 : (n/2)+1;
        
        int nl = mid, nr = n-mid;
        
        Node* left = new Node(head->data);
        Node* temp = head->next, *t1 = left;
        while(--nl)
        {
            Node* newNode = new Node(temp->data);
            t1->next = newNode;
            t1 = t1->next;
            temp = temp->next;
        }
        
        Node* right = new Node(temp->data);
        Node* t2 = right;
        temp = temp->next;
        while(--nr)
        {
            Node* newNode = new Node(temp->data);
            t2->next = newNode;
            t2 = t2->next;
            temp = temp->next;
        }
        
        mergeSort(left);
        mergeSort(right);
        
        merge(head, left, right);
        
        return head;
    }
};
