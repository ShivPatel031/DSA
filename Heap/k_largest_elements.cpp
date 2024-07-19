// k largest elements GFG

// Given an array arr of n positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

// Examples

// Input: arr[] = {12, 5, 787, 1, 23}, n = 5, k = 2
// Output: 787 23
// Explanation: 1st largest element in the array is 787 and second largest is 23.
// Input: arr[] = {1, 23, 12, 9, 30, 2, 50}, n = 7, k = 3 
// Output: 50 30 23
// Explanation: 3 Largest element in the array are 50, 30 and 23.

// Expected Time Complexity: O(k+(n-k)*logk)
// Expected Auxiliary Space: O(k+(n-k)*logk)

// Constraints:
// 1 ≤ k ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 106

vector<int> kLargest(int arr[], int n, int k) 
{
  priority_queue<int , vector<int> ,greater<int>> q;

    for(int i = 0 ; i < k ;i++)
    {
        q.push(arr[i]);
    }     

    for(int i = k ; i < n ; i ++ )
    {
        if(q.top()<arr[i])
        {
            q.pop();
            q.push(arr[i]);
        }
    }

    vector<int> ans(k);
    
    for(int i = k-1;i>=0;i--)
    {
        ans[i]=q.top();
        q.pop();
    }
    
    return ans;
    
}
