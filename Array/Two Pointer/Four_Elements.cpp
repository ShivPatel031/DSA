// Four Elements

// Given an array A of N integers. You have to find whether a combination of four elements in the array whose sum is equal to a given value X exists or not.
 

// Example 1:

// Input:
// N = 6
// A[] = {1, 5, 1, 0, 6, 0}
// X = 7
// Output:
// 1
// Explantion:
// 1, 5, 1, 0 are the four elements which makes sum 7.

bool find4Numbers(int A[], int n, int X)  
{
        vector<int> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back(A[i]);
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-3;i++){
            
            int remain1 = X-arr[i];
            
            for(int j=i+1;j<n-2;j++){ 
                
                int remain2 = remain1-arr[j];
                
                int start=j+1,end=n-1;
            
                while(start<end){
                    
                    if(arr[start]+arr[end]==remain2){
                        
                        return 1;
                    }
                    else if(arr[start]+arr[end]>remain2){
                        
                        end--;
                    }
                    else{
                        start++;
                    }
                }
            
            }
    
        }
        
        return 0;
    
    
}
