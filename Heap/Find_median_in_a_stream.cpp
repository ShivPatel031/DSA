// Find median in a stream GFG

// Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

// Example 1:

// Input:
// N = 4
// X[] = 5,15,1,3
// Output:
// 5
// 10
// 5
// 4
// Explanation:Flow in stream : 5, 15, 1, 3 
// 5 goes to stream --> median 5 (5) 
// 15 goes to stream --> median 10 (5,15) 
// 1 goes to stream --> median 5 (5,15,1) 
// 3 goes to stream --> median 4 (5,15,1 3) 
 
// Example 2:

// Input:
// N = 3
// X[] = 5,10,15
// Output:
// 5
// 7.5
// 10
// Explanation:Flow in stream : 5, 10, 15
// 5 goes to stream --> median 5 (5) 
// 10 goes to stream --> median 7.5 (5,10) 
// 15 goes to stream --> median 10 (5,10,15) 
// Your Task:
// You are required to complete the class Solution. 
// It should have 2 data members to represent 2 heaps. 
// It should have the following member functions:
// insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
// balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
// getMedian() does not take any arguments. It should return the current median of the stream.

// Expected Time Complexity : O(nlogn)
// Expected Auxilliary Space : O(n)
 
// Constraints:
// 1 <= N <= 106
// 1 <= x <= 106

priority_queue<int> leftMaxHeap;
priority_queue<int,vector<int>,greater<int>> rightMinHeap;

void insertHeap(int &x)
{
    if(leftMaxHeap.empty())
    {
        leftMaxHeap.push(x);
        return;
    }
    
    if(x>leftMaxHeap.top())
    {
        rightMinHeap.push(x);
    }
    else
    {
        leftMaxHeap.push(x);
    }
    
    balanceHeaps();
}

void balanceHeaps()
{
    if(leftMaxHeap.size()<rightMinHeap.size())
    {
        leftMaxHeap.push(rightMinHeap.top());
        rightMinHeap.pop();
    }
    else if(leftMaxHeap.size()>rightMinHeap.size()+1)
    {
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();
    }
}

double getMedian()
{
    if(leftMaxHeap.size()==rightMinHeap.size())
    {
        return (leftMaxHeap.top()+rightMinHeap.top())/2;
    }
    else
    {
        return leftMaxHeap.top();
    }
}
