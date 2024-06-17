//leetCode

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

int missingNumber(vector<int>& nums) {
        int sum1=0,sum2=0;

        for (int i=0;i<nums.size();i++){
            sum1+=i+1;
            sum2+=nums[i];
        }
        return sum1-sum2;
}

//GFG

// Input:
// n  =  4                                        
// arr = {1, 4, 3}
// Output: 2

int missingNumber(int n, vector<int> &arr) {
        
        int sum1=(n*(n+1))/2;
        int sum2=0;
        
        for(int i=0;i<n-1;i++){
            sum2+=arr[i];
        }
        // code here
        return sum1-sum2;
}
