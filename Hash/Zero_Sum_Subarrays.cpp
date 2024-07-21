// Zero Sum Subarrays GFG

// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

// Examples:

// Input: n = 6, arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].

//   Input: n = 10, arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4
// Explanation: The 4 subarrays are [-1 -3 4], [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

//   Expected Time Complexity: O(n*log(n))
// Expected Auxilliary Space: O(n)

// Constraints:    
// 1 <= n <= 10^6
// -10^9 <= arr[ i ] <= 10^9


long long int findSubarray(vector<long long int> &arr, int n ) 
{
    unordered_map<long long int,long long int> m;
    
    long long int totalcount = 0;
    
    m[0]=1;
    
    long long int sum = 0 ;
    
    for(int i = 0 ; i < n ; i++)
    {
        sum+=arr[i];
        
        if(m.count(sum))
        {
            totalcount+=m[sum];
            m[sum]++;
        }
        else
        {
            m[sum]=1;
        }
        
    }
    
    return totalcount;
}
