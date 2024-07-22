// Minimum Size Subarray Sum leetcode 209

// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
  
// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 
// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104

int minSubArrayLen(int target, vector<int>& nums) 
{
    int s=0,e=0,sum=0,length = INT_MAX;

    while(e<nums.size())
    {
        sum+=nums[e];

        while(sum>=target && s<=e)
        {
            if(length>e-s+1 && sum>=target) length=e-s+1;
            sum-=nums[s];
            s++;
        }
        e++;
    }

    return length == INT_MAX ? 0 : length;    
}
