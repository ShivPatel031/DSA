// Subarray Product Less Than K leetcode 713 GFG

// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

// Example 2:

// Input: nums = [1,2,3], k = 0
// Output: 0
 
// Constraints:

// 1 <= nums.length <= 3 * 104
// 1 <= nums[i] <= 1000
// 0 <= k <= 106


// optimize way

int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    int product = 1,s=0,e=0,totalcount = 0;

    while(e<nums.size())
    {
        product*=nums[e];

        while(product>=k && s<=e)
        {
            product/=nums[s];
            s++;
        }

        totalcount+=e-s+1;
        e++;
    }
    return totalcount;
}

// what i first thought
int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    int product = 1,s=0,e=0,totalcount = 0;

    for(int i = 0 ; i < nums.size();i++)
    {
        product *=nums[i];

        if(product<k)
        {
            totalcount+=e-s+1;
            e++;
        }
        else
        {
            while(product>=k && s<=e)
            {
                product/=nums[s];
                s++;
            }

            if(s<=e)
            {
                totalcount+=e-s+1;
            }

            e++;

        }
    }
    return totalcount;
}
