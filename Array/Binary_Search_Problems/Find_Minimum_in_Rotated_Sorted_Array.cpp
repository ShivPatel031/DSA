// Find Minimum in Rotated Sorted Array

Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

int findMin(vector<int>& arr) {

        if(arr.size() == 1){
            return arr[0];
        }

        int l = 0 , r = arr.size()-1;

        while (l<=r){
            int m = r + (l-r)/2;

            if(arr[m]<arr[m-1]){
                return arr[m];
            }
            else if(arr[m] > arr[0]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return arr[0];
        
    }
