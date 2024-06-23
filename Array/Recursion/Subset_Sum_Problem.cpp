// Subset Sum Problem

// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

// Example 1:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 9
// Output: 1 
// Explanation: Here there exists a subset with
// sum = 9, 4+3+2 = 9.
  
// Example 2:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 30
// Output: 0 
// Explanation: There is no subset with sum 30.

// not good for time complexcity

bool find(vector<int> &arr,int index,int n,int target){
        if(target==0){
            return 1;
        }
        if(index==n || target<0){
            return 0;
        }
        
        return (find(arr,index+1,n,target) || find(arr,index+1,n,target-arr[index]));
    }
  bool isSubsetSum(vector<int>arr, int sum){
      
      
      return find(arr,0,arr.size(),sum);
  
      
  }
