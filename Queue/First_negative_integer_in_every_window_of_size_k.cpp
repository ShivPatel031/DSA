// First negative integer in every window of size k GFG

// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6
 
// Example 2:
  
// Input : 
// N = 8
// A[] = {12, -1, -7, 8, -15, 30, 16, 28}
// K = 3
// Output :
// -1 -1 -7 -15 -15 0 
 
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)

// Constraints:
// 1 <= N <= 105
// -105 <= A[i] <= 105
// 1 <= K <= N


// timecomplexity O(N)
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{    
    vector<long long > ans;
    queue<long long > q;
    
    for(long long int i = 0 ; i < K-1;i++)
    {
        if(A[i]<0)
        {
            q.push(i);
        }
    }
    
    for(long long int i=K-1;i<N;i++)
    {
        if(A[i]<0)
        {
            q.push(i);
        }
        
        if(!q.empty() && q.front()<=i-K)
        {
            q.pop();
        }
        
        if(!q.empty())
        {
            ans.push_back(A[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    
    }
    
    return ans;
                                                 
}

// timecomplexsity O(NK)
// int findNegative(queue<long long int> q)
// {
//     while(!q.empty())
//     {
//         if(q.front()<0){
//             return q.front();
//         }
        
//         q.pop();
//     }
    
//     return 0;
// }

// vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
//     vector<long long > ans;
//     queue<long long > q;
    
//     for(long long int i = 0 ; i < K-1;i++)
//     {
//         q.push(A[i]);
//     }
    
//     for(long long int i=K-1;i<N;i++)
//     {
//         q.push(A[i]);
//         ans.push_back(findNegative(q));
//         q.pop();
//     }
    
//     return ans;
                                                 
//  }
