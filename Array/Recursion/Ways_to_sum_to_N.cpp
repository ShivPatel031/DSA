// Ways to sum to N GFG

// Given a set of m distinct positive integers and a value ‘N’. Count the total number of ways we can form ‘N’ by  adding the array elements. Repetitions and different arrangements are allowed.
// all posible arrangemen even same with diffrent place like 1,5,1 and 1,1,5 are allowed even with repetation

// Input:
// m = 3 , N = 7
// Arr[] = {1,5,6}
// Output: 6
// Explanation: The different ways are:
// 1+1+1+1+1+1+1
// 1+1+5
// 1+5+1
// 5+1+1
// 1+6
// 6+1


// but not best way because time complexsity need to use DP

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
  findTargetSum(arr,ans,0,sum-arr[index],temp);
  temp.pop_back();
}

vector<vector<int> > findTargetSumWithRepetation(vector<int> &arr,int sum){

  vector<vector<int> > ans;
  vector<int> temp;

  findTargetSum(arr,ans,0,sum,temp);

  return ans;
}
