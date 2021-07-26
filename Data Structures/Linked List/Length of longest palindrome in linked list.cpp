// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1#
// Good question

/*
Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the 
given linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting 
the size of the linked list . Then in the next line are N space separated values of the given linked list.

Output:
For each test case output will be the required max length of the palindrome present in the given linked list.

User Task:
The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2

Explanation:
Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.
*/

// TC : O(n^2)
// SC : O(1)

int countCommon(Node* head1, Node* head2)
{
    int ans = 0;
    while(head1 && head2 && head1->data == head2->data)
    {
        ans++;
        head1 = head1->next;
        head2 = head2->next;
    }
    return ans;
}

int maxPalindrome(Node *head)
{
    if(!head)
        return 0;
    if(!head->next)
        return 1;
    
    int ans = 1;
    Node* curr = head, *pre = NULL, *post;
    while(curr)
    {
        post = curr->next;
        curr->next = pre;
        
        ans = max(ans, 1 + 2 * countCommon(pre, post));
        ans = max(ans, 2 * countCommon(curr, post));
        
        pre = curr;
        curr = post;
    }
    return ans;
}
