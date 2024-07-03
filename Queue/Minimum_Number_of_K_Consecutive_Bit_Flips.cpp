// Minimum Number of K Consecutive Bit Flips leetcode 995

// You are given a binary array nums and an integer k.

// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [0,1,0], k = 1
// Output: 2
// Explanation: Flip nums[0], then flip nums[2].
// Example 2:

// Input: nums = [1,1,0], k = 2
// Output: -1
// Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
// Example 3:

// Input: nums = [0,0,0,1,0,1,1,0], k = 3
// Output: 3
// Explanation: 
// Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
// Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
// Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
 
// Constraints:

// 1 <= nums.length <= 105
// 1 <= k <= nums.length

int minKBitFlips(vector<int>& nums, int k) {
    deque<int> d;
    int flip=0;

    for(int i = 0 ; i < nums.size() ; i++)
    {   
        // bool flag = 0;

        if(!d.empty() && d.front()<i)
        {
            d.pop_front();
        }

        if(d.size()%2==nums[i])
        {
            if(i+k-1>=nums.size())
            {
                return -1;
            }
            d.push_back(i+k-1);
            flip++;
        }

        // if(nums[i]==0)
        // {
        //     if(d.size()%2==0)
        //     flag=1;
        // }
        // else if(d.size()%2==1)
        // {
        //     flag=1;
        // }

        // if(flag)
        // {
        //     if(i+k-1>=nums.size())
        //     {
        //         return -1;
        //     }
        //     d.push_back(i+k-1);
        //     flip++;
        // }
    }  

    return flip; 
}
