// subset leetcode 78

// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
  
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

void subset(vector<vector<int>> &ans,int index,int n,vector<int> temp,vector<int> &nums){

        if(index==n)
        {
            ans.push_back(temp);
            return;
        }

        subset(ans,index+1,n,temp,nums);
        temp.push_back(nums[index]);
        subset(ans,index+1,n,temp,nums);
        
}
vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        subset(ans,0,nums.size(),temp,nums);

        return ans;
        
}
