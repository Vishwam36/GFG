// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/sort-a-stack/1#
// Good question

/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. 
(The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity : O(N*N)
Expected Auixilliary Space : O(N) recursive.

Constraints:
1<=N<=100

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function 
problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

// TC : O(N*N)
// Idea is we push minimum element from top size elements at size th position and then we reduce size by 1

int mini; // minimum element from stack with size elements
int min_freq; // frequeny of mini

void rec(stack<int> &s, int size)
{
    if(size == 0)
    {
        min_freq--;
        s.push(mini); // push minimum element from stack with top size elements
        return;
    }
    
    int a = s.top(); s.pop();
	
    if(mini == a)
    {
        min_freq++;
    }
    else if(mini > a)
    {
        mini = a;
        min_freq = 1;
    }
    
    rec(s, size-1);
    
    if(a == mini && min_freq > 0) // push only if mini is remaining, if we dont add this condition one mini will be added extra
    {
        min_freq--;
        s.push(a);
    }
    else if(a != mini)
    {
        s.push(a);
    }
}

void SortedStack :: sort()
{
    int size = s.size();
    while(size)
    {
        min_freq = 0;
        mini = INT_MAX;
        rec(s, size);
        size--;
    }
}
