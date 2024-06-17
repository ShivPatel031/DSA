// Find First and Last Position of Element in Sorted Array

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:

I// nput: nums = [], target = 0
// Output: [-1,-1]

vector<int> searchRange(vector<int>& nums, int target) {

        int l =0,r=nums.size()-1;
        vector<int> result(2,-1);

        while(l<=r){
            int m = l + (r -l)/2;

            if(nums[m] == target){
                result[0] = m;
                r = m-1;
            }
            else if(target > nums[m]){
                l=m+1;
            }
            else{
                r = m-1;
            }
        }

        l=0,r=nums.size()-1;
        while(l<=r){
            int m = l + (r -l)/2;

            if(nums[m] == target){
                result[1] = m;
                l = m+1;
            }
            else if(target > nums[m]){
                l=m+1;
            }
            else{
                r = m-1;
            }
        }

        return result;
        
    }
