// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#
// Easy

/*
Implement a Stack using two queues q1 and q2.

Example 1:
Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  

Example 2:
Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1

Your Task:
Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() which takes an integer 'x' as
input denoting the element to be pushed into the stack and pop() which returns the integer poped out from the stack(-1 if the stack is empty).

Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/



/*
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity);

// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
void enqueue(struct Queue* queue, int item);

// Function to remove an item from queue.
void dequeue(struct Queue* queue);
 
// Function to get front of queue
int front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);
*/

// Function to push an element into stack using two queues.
// 2 Queues q1 and q2 where q1 should be used as stack and q2 as helping queue
// num: number to be inserted 
void push(struct Queue *q1,struct Queue *q2,int num)
{
    while(!isEmpty(q1))
    {
        enqueue(q2, front(q1));
        dequeue(q1);
    }
    enqueue(q1, num);
    while(!isEmpty(q2))
    {
        enqueue(q1, front(q2));
        dequeue(q2);
    }
}

//Function to pop an element from stack using two queues. 
int pop(struct Queue *q1)
{
    if(isEmpty(q1))
        return -1;
    
    int ans = front(q1);
    dequeue(q1);
    return ans;
}
