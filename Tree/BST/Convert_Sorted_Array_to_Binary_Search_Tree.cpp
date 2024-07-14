// Convert Sorted Array to Binary Search Tree leetcode 108

// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in a strictly increasing order.

TreeNode* helper(vector<int> &nums,int start,int end)
{
    if(start>end) return nullptr;
    
    int mid=start + (end-start)/2;

    TreeNode* temp=new TreeNode(nums[mid]);

    temp->left = helper(nums,start,mid-1);
    temp->right = helper(nums,mid+1,end);

    return temp;
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    return helper(nums,0,nums.size()-1);    
}
