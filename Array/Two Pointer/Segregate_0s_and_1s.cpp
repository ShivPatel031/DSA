// Segregate 0s and 1s

// Given an array of length n consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s on the left side and 1s on the right side of the array.

// Example 1:
// Input:
// n = 5
// arr[] = {0, 0, 1, 1, 0}
// Output: {0, 0, 0, 1, 1}
// Explanation: 
// After segregate all 0's on the left and 1's on the right modify array will be {0, 0, 0, 1, 1}.

// Example 2:
// Input:
// n = 4
// arr[] = {1, 1, 1, 1}
// Output: {1, 1, 1, 1}
// Explanation: There are no 0 in the given array, so the modified array is 1 1 1 1.

void segregate0and1(int arr[], int n) {
        
        int start = 0, end = n-1;
        
        while(start<end){
            if(arr[start]==0){
                start++;
            }
            else{
                if(arr[end]==0){
                    int temp=arr[start];
                    arr[start]=arr[end];
                    arr[end]=temp;
                    start++;
                    end--;
                }
                else{
                    end--;
                }
            }
        }
        
    }
