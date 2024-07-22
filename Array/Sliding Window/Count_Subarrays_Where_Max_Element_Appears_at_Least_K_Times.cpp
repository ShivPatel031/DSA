// Count Subarrays Where Max Element Appears at Least K Times leetcode 2962

// You are given an integer array nums and a positive integer k.
// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
// A subarray is a contiguous sequence of elements within an array.

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

// Example 2:

// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times. 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= k <= 105

long long countSubarrays(vector<int>& nums, int k) 
{
    int maxElement = 0;

    for(int i = 0 ; i  < nums.size() ; i++)
    {
        maxElement = max(maxElement,nums[i]);
    }    

    int start = 0 , end  = 0;
    
    long long subArrayCount = 0;

    int maxElementCount = 0;

    while(end<nums.size())
    {
        if(nums[end]==maxElement)   maxElementCount++;

        while(maxElementCount == k && start<=end)
        {
            subArrayCount+=nums.size()-end;

            if(nums[start]==maxElement) maxElementCount--;

            start++;
        }

        end++;
    }

    return subArrayCount;
}
