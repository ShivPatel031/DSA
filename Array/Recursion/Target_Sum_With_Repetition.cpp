// Target Sum With Repetition

// not optimize way

// not work with value zero

void findTargetSum(vector<int> &arr,vector<vector<int>> &ans,int index,int sum,vector<int> &temp)
{
    if(sum==0)
    {
        ans.push_back(temp);
        return;
    }

    if(index==arr.size() || sum<0)
    {
        return;
    }

    findTargetSum(arr,ans,index+1,sum,temp);

    temp.push_back(arr[index]);
    findTargetSum(arr,ans,index,sum-arr[index],temp);
    temp.pop_back();

}

vector<vector<int> > findTargetSumWithRepetation(vector<int> &arr,int sum)
{
    vector<vector<int> > ans;
    vector<int> temp;

    findTargetSum(arr,ans,0,sum,temp);

    return ans;
}
