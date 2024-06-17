// Triplet Sum in Array

// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.

// Example 2:

// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in 
// the array sums up to 10.

bool find3Numbers(int A[], int n, int X)
    {
        vector<int> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back(A[i]);
        }
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-2;i++){
            int remain = X-arr[i];
            
            int start=i+1,end=n-1;
            
            while(start<end){
                if(arr[start]+arr[end]==remain){
                    return 1;
                }
                else if(arr[start]+arr[end]>remain){
                    end--;
                }else{
                    start++;
                }
            }
        }
        
        return 0;
        
    }
