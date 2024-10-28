// Rotate Array leetcode 189

// What i thought
void rotate(vector<int>& nums, int k) 
{
    k=k%nums.size();

    vector<int> ans;

    for(int i=nums.size()-k;i<nums.size();i++)
    {
        ans.push_back(nums[i]);
    }    

    for(int i = 0 ; i < nums.size()-k;i++)
    {
        ans.push_back(nums[i]);
    }

    for(int i = 0;i<ans.size();i++)
    {
        nums[i]=ans[i];
    }
}

// Other way
void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    k = k % n;
    vector<int> rotated(n);

    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = rotated[i];
    }        
}
