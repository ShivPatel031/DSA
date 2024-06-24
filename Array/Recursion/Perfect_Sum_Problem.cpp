// Perfect Sum Problem GFG

// Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7.

// Examples:

// Input: 
// n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
// Output: 
// 3
// Explanation: 
// {5, 2, 3}, {2, 8}, {10} are possible subsets.
  
// Input: 
// n = 5, arr = [2, 5, 1, 4, 3], sum = 10
// Output: 
// 3
// Explanation: 
// {2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.


// not best uproach in timecoplexity
int findSameSumCount(int arr[],int index, int sum,int n)
{
    if(n==index)
    {
        return sum==0;
    }

    return findSameSumCount(arr,index+1,sum,n)+findSameSumCount(arr,index+1,sum-arr[index],n);
}

int perfectSum(int arr[], int n, int sum)
{
      return findSameSumCount(arr,0,sum,n);
}
