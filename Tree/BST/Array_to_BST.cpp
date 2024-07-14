// Array to BST GFG

// Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST). Find the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
// Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

void helper(vector<int> &ans,vector<int> &nums,int start,int end)
{
    if(start>end) return;
    
    int mid=start + (end-start)/2;
    
    ans.push_back(nums[mid]);
    
    helper(ans,nums,start,mid-1);
    helper(ans,nums,mid+1,end);
}

vector<int> sortedArrayToBST(vector<int>& nums)
{
    vector<int> ans;
    
    helper(ans,nums,0,nums.size()-1);
    
    return ans;
}
