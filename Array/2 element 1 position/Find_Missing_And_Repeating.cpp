// Find Missing And Repeating GFG

// Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
// Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

// Examples

// Input: n = 2 arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.

// Input: n = 3 arr[] = {1, 3, 3} 
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.

vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<int> ans;
        
        for(int i = 0;i<n;i++){
            arr[i]*=10;
        }
        
        for(int i=0;i<n;i++){
            arr[arr[i]/10-1]++;
        }
        
        int ans1=0,ans2=0;
        for(int i = 0;i<n;i++){
            if(arr[i]%10==2){
                ans1=i+1; 
            }
            else if(arr[i]%10==0){
                ans2=i+1;
            }
        }
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        return ans;
        
    }

// optimize way

vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            arr[arr[i]%(n+1)-1]+=n+1;
        }
        
        int ans1=0,ans2=0;
        
        for(int i = 0;i<n;i++){
            
            if(arr[i]/(n+1)==2){
                ans1=i+1; 
            }
            else if(arr[i]/(n+1)==0){
                ans2=i+1;
            }
        }
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        return ans;
        
    }
