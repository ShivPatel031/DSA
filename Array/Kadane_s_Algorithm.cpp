// Kadane's Algorithm

// Input: arr[] = {1,2,3,-2,5}, n = 5
// Output: 9
// Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

// Input: arr[] = {-1,-2,-3,-4}, n = 4
// Output: -1
// Explanation: Max subarray sum is -1 of element (-1)

// Input: arr[] = {5,4,7}, n = 3
// Output: 16
// Explanation: Max subarray sum is 16 of element (5, 4, 7)
// Expected Time Complexity: O(n)

long long maxSubarraySum(int arr[], int n) {

        long long max = INT_MIN,prefix = 0;
        
        for (int i = 0 ; i<n;i++){
            prefix += arr[i];
            
            if(max < prefix){
                max=prefix;
            }
            
            if(prefix < 0){
                prefix = 0;
            }
        }
        
        return max;
    }
