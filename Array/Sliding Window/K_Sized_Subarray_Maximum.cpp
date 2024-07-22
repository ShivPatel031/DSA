// K Sized Subarray Maximum GFG

// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
// Example 1:

// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output: 
// 3 3 4 5 5 5 6 
// Explanation: 
// 1st contiguous subarray = {1 2 3} Max = 3
// 2nd contiguous subarray = {2 3 1} Max = 3
// 3rd contiguous subarray = {3 1 4} Max = 4
// 4th contiguous subarray = {1 4 5} Max = 5
// 5th contiguous subarray = {4 5 2} Max = 5
// 6th contiguous subarray = {5 2 3} Max = 5
// 7th contiguous subarray = {2 3 6} Max = 6

// Example 2:

// Input:
// N = 10, K = 4
// arr[] = 8 5 10 7 9 4 15 12 90 13
// Output: 
// 10 10 10 15 15 90 90
// Explanation: 
// 1st contiguous subarray = {8 5 10 7}, Max = 10
// 2nd contiguous subarray = {5 10 7 9}, Max = 10
// 3rd contiguous subarray = {10 7 9 4}, Max = 10
// 4th contiguous subarray = {7 9 4 15}, Max = 15
// 5th contiguous subarray = {9 4 15 12}, 
// Max = 15
// 6th contiguous subarray = {4 15 12 90},
// Max = 90
// 7th contiguous subarray = {15 12 90 13}, 
// Max = 90
// Your Task:  
// You dont need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(k)

// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ K ≤ N
// 0 ≤ arr[i] ≤ 109


vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    
    int start = 0 ,end = 0 , maxElement = 0;
    
    bool flag = 0;
    
    while(end<n)
    {
        if(end==k-1) flag=1;
        
        if(maxElement<arr[end]) maxElement=arr[end];
        
        if(flag) ans.push_back(maxElement);
        
        if(flag)
        {
            if(arr[start]==maxElement)
            {
                maxElement=0;
                for(int i = start+1;i<=end;i++)
                {
                    maxElement = max(maxElement,arr[i]);
                }
            }
            
            start++;
        }
        
        end++;
    }
    
    return ans;
}
