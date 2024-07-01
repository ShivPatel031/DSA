// Queue Reversal GFG

// Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

// Example 1:

// Input:
// 6
// 4 3 1 10 2 6
// Output: 
// 6 2 10 1 3 4
// Explanation: 
// After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.

// Your Task: You need to complete the function rev that takes a queue as parameter and returns the reversed queue. The printing is done automatically by the driver code.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ elements of Queue ≤ 105

queue<int> rev(queue<int> q)
{
    stack<int> temp;
    
    while(!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
    
    return q;
}
