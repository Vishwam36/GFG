// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1#
// Good question

/*
Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

Input:
In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set *headRef to head of resultant linked list.

User Task:
The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

Constraints:
1<=T<=100
1<=N<=200

Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
2
3
1 6 2
4
1 9 3 8

Output:
1 2 6
1 3 8 9

Explanation:
Testcase 1: After sorting the nodes, we have 1, 2 and 6.
Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.
*/

/*
In partition(), we consider last element as pivot. We traverse through the current list and if a node has value greater than pivot, we move it after tail. 
If the node has smaller value, we keep it at its current position. 

In quicksort(), we first call partition() which places pivot at correct position and returns pivot. After pivot is placed at correct position, we find 
tail node of left side (list before pivot) and recur for left list. Finally, we recur for right list.
*/

// get just previous node of end
node* getTail(node* head, node* end)
{
    while(head && head->next && head->next != end)
        head = head->next;
    
    return head;
}

node* partition(node* head, node* tail, node **newHead, node **newTail)
{
    node* pre = new node(-1);
    pre->next = head;
    node* end = tail, *tempPre = pre;
    
    while(head != tail)
    {
        if(head->data > tail->data)
        {
            pre->next = head->next;
            head->next = NULL;
            end->next = head;
            head = pre;
            end = end->next;
        }
        pre = head;
        head = head->next;
    }
    
    *newHead = tempPre->next;
    *newTail = end;
    return tail;
}

node* quicksort(node* head, node* tail)
{
    if(!head || head == tail)
        return head;
    
    node* newHead = NULL, *newTail = NULL;
    node* pivot = partition(head, tail, &newHead, &newTail);
    
    if(newHead != pivot)
    {
        node* temp = getTail(newHead, pivot);
        temp->next = NULL;
        newHead = quicksort(newHead, temp);
		
        temp = getTail(newHead, NULL);
        temp->next = pivot;
    }
    
    pivot->next = quicksort(pivot->next, newTail);
    
    return newHead;
}

void quickSort(struct node **headRef) 
{
    node* head = *headRef;
    node* tail = getTail(head, NULL);
    head = quicksort(head, tail);
    *headRef = head;
}
