// Permutations  LeetCode 46

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order. 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
  
// Example 3:

// Input: nums = [1]
// Output: [[1]]


// most optimize

void parmutation(vector<int> &arr,vector<vector<int> > &ans,int index)
{
    if(arr.size()==index)
    {
        ans.push_back(arr);
        return;
    }

    for(int i = index ;i<arr.size();i++)
    {
        swap(arr[i],arr[index]);
        parmutation(arr,ans,index+1);
        swap(arr[i],arr[index]);
    }
}
vector<vector<int>> permute(vector<int>& arr) 
{
    vector<vector<int> > ans;

    parmutation(arr,ans,0);

    return ans; 
}

// less optimize

// void parmutation(vector<vector<int>> &ans,vector<int> &arr,vector<int> &temp,vector<bool> &check)
// {
//     if(temp.size()==arr.size())
//     {
//         ans.push_back(temp);
//         return;
//     }

//     for(int i = 0;i<arr.size();i++)
//     {
//         if(check[i]==0)
//         {
//             check[i]=1;
//             temp.push_back(arr[i]);
//             parmutation(ans,arr,temp,check);
//             check[i]=0;
//             temp.pop_back();
//         }
//     }
// }


// vector<vector<int>> findAllParmutation(vector<int> &arr)
// {
//     vector<vector<int> > ans;
//     vector<int> temp;
//     vector<bool> check(arr.size(),0);

//     parmutation(ans,arr,temp,check);

//     return ans;

// }
