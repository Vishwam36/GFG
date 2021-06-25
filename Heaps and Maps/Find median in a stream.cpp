// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#
// Decent

/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X 
to the new stream.

Example 1:
Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 

Example 2:
Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 

Your Task:
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:

    insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
    balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
    getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 10^6
1 <= x <= 10^6
*/

class Solution
{
    public:
    priority_queue<int> pq1; // will contain half smaller elements
    priority_queue<int, vector<int>, greater<int> > pq2; // will contain next half greater elements

    void insertHeap(int &x)
    {
        pq1.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(pq1.size() - pq2.size() == 2)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq2.size())
        {
            if(pq1.top() > pq2.top())
            {
                int t1 = pq1.top(); pq1.pop();
                int t2 = pq2.top(); pq2.pop();
                
                pq1.push(t2);
                pq2.push(t1);
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(pq1.size() > pq2.size())
            return pq1.top();
        
        return ((double)pq1.top()+pq2.top())/2;
    }
};
