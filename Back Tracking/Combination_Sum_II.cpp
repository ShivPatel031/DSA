// Combination Sum II leetcode 40

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ] 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

// optimize way
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1]) continue;
        if (arr[i] > target) break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
  
// what i thought first and give time limit error
void combination(set<vector<int>> &ans,int &target,int index,int &sum,vector<int> &temp,vector<int> &candidates)
{
    if(target==sum)
    {
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }

    if(sum>target or index >= candidates.size()) return;

    temp.push_back(candidates[index]);
    sum+=candidates[index];
    combination(ans,target,index+1,sum,temp,candidates);
    
    auto it = find(temp.begin(), temp.end(), candidates[index]); 
    if (it != temp.end()) { 
        temp.erase(it); 
    }
    sum-=candidates[index];
    combination(ans,target,index+1,sum,temp,candidates);
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    set<vector<int>> tempans;
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=0;

    combination(tempans,target,0,sum,temp,candidates);

    for(auto i : tempans)
    {
        ans.push_back(i);
    }

    return ans;
}
