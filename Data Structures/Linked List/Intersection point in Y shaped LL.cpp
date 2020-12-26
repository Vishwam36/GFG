// By Vishwam Shriram Mundada
//

#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int intersectPoint(Node* head1, Node* head2)
{
    // n1 will store number of elements in LL1 and same with LL2
    int n1=0, n2=0;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 -> next != NULL)
    {
        temp1 = temp1 -> next;
        n1++;
    }
    while(temp2 -> next != NULL)
    {
        temp2 = temp2 -> next;
        n2++;
    }
    temp1= head1;
    temp2 = head2;
    int larger = max(n1, n2);
    int diff = abs(n1-n2);
    int diff1 = diff;
    
    // traverse larger LL till extra nodes in that LL are passes
    if(n1 > n2)
    {
        while(diff--)
        {
            temp1 = temp1 -> next;
        }
    }
    else if(n1 < n2)
    {
        while(diff1--)
        {
            temp2 = temp2 -> next;
        }
    }
    
    // traverse further and if common node comes i.e address of node in LL1 = address of node in LL2 then return node's data
    while((temp1 != temp2) && temp1 != NULL)
    {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    if(temp1 == NULL)
    {
        return -1;
    }
    return temp1 -> data;
}


