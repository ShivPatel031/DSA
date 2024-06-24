// Permutations II leetCode 47 and All Unique Permutations of an array GFG

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order. 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
  
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

void permutation(vector<int> &arr,vector<vector<int>> &ans,int index)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }

    vector<bool> check(21,0);
    for(int i = index;i<arr.size();i++)
    {
            if(check[arr[i]+10]==0)
            {
                
                swap(arr[i],arr[index]);
                permutation(arr,ans,index+1);
                swap(arr[i],arr[index]);

                check[arr[i]+10]=1;
            }
    }
}

vector<vector<int>> permuteUnique(vector<int>& arr) 
{
    vector<vector<int>> ans;
    
    permutation(arr,ans,0);

    return ans;   
}
