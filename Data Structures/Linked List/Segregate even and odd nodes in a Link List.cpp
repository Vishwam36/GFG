// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
// Easy

/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers
within each segregation should be same as that in the original list.

Example 1:
Input: 
N = 7
Link List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 17,15,8,9 are odd so they appear 
first and 2,4,6 are the even numbers that appear later.

Example 2:
Input:
N = 4
Link List = 1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number. 
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and 
returns the head of modified link list.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 10000
*/

// TC : O(N)
// SC : O(N)

class Solution{
public:
    Node* divide(int N, Node *head)
    {
        Node* odd = new Node(-1), *even = new Node(-1);
        Node* evenStart = even, *oddStart = odd;
        Node* temp = head;
        while(temp)
        {
            if(temp->data % 2 != 0)
            {
                odd->next = new Node(temp->data);
                odd = odd->next;
            }
            else
            {
                even->next = new Node(temp->data);
                even = even->next;
            }
            temp = temp->next;
        }
        even->next = oddStart->next;
        return evenStart->next;
    }
};
