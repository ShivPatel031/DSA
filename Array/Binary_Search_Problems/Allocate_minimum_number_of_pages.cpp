
// Allocate minimum number of pages


// You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}

int findPages(int arr[], int N, int M) 
    {
        if (M>N) return -1;
        
        int start=arr[0],end=arr[0],ans;
        
        for (int i=1;i<N;i++){
            if(start < arr[i]){
                start=arr[i];
            }
            end+=arr[i]; 
        }
        
        while(start<=end){
            int mid = start + (end - start)/2;
            
            int page = 0,count=1;
            
            for(int i = 0;i<N;i++){
                page += arr[i];
                if(page> mid){
                    count++;
                    page=arr[i];
                }
            }
            
            if(count <= M){
                ans=mid;
                end=mid-1;
            }else{
                start=mid +1;
            }
            
        }
        
        return ans;
    }
