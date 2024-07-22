// Subarray Sums Divisible by K leetcode 974 GFG

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// Example 2:

// Input: nums = [5], k = 9
// Output: 0 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104

// this question can be done by vector because remaider always come between 0 to k and we just have to track how many times reminder came

// Note if we use vector then timecomplexcity will be reduce more than map


int subarraysDivByK(vector<int>& arr, int k) 
{
    unordered_map<int,int> m;
    
    m[0]=1;
    
    int sum = 0 ,rem,totalcount=0;
    
    for(int i = 0 ; i < arr.size() ; i++)
    {
        sum+=arr[i];
        rem = sum%k;

        if(rem<0) rem=k+rem;


        
        if(m.count(rem))
        {
            totalcount+=m[rem];
            m[rem]++;
        }
        else
        {
            m[rem]++;
        }

        // can conver above if else in this ans still work
        // totalcount+=m[rem];
        // m[rem]++;
    }
    
    return totalcount;    
}
