// Search Insert Position

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4



int searchInsertK(vector<int>nums, int N, int target)
    {
        
        if(target > nums[N-1]){
            return nums.size();
        }
        int l=0,r=nums.size()-1,index=0;
        

        while(l<=r){
            int m = l + (r-l)/2;

            if(nums[m] == target){
                return m;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
                index = m;
            }
        }

        return index;
    }
