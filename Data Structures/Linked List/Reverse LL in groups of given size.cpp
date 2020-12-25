// By Vishwam Mundada
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include<bits/stdc++.h>
using namespace std;

struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        head = reverse(head, k);
        printList(head);
    }
     
    return(0);
}

struct node *reverse (struct node *head, int k)
{
    node* pre = NULL;
    node* post = NULL;
    node* current = head;
    int cnt = k;
    
    // reversing first k nodes from current head
    while(cnt > 0 && current != NULL)
    {
        --cnt;
        post = current -> next;
        current -> next = pre;
        pre = current;
        current = post;
    }
    
    // joining previous reversed mini LL to head->next
    if(post != NULL)
    {
        head -> next = reverse(post, k);
    }
    return pre;
}
