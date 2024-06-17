// Search in Rotated Sorted Array

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

// optimized way

 int search(vector<int>& arr, int target) {

        int l = 0 , r =arr.size()-1;

        while (l<=r){
            int m = l + (r-l)/2;

            if(arr[m]==target){
                return m;
            }
            else if(arr[m]>=arr[0]){
                if(arr[m]>target && arr[0]<=target){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }else{
                if(target <= arr[r] && target > arr[m]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
           
        }
        return -1;
        
    }




// How i thought

// int search(vector<int>& arr, int target) {

//         int l = 0 , r =arr.size()-1;

//         while (l<=r){
//             int m = l + (r-l)/2;

//             if(arr[m]==target){
//                 return m;
//             }
//             else if(arr[m]>=arr[l] && arr[m]>arr[r]){
//                 if ((arr[m]>target && arr[0]>target) || (target > arr[0] && target > arr[m])){
//                     l=m+1;
//                 }else{
//                     r=m-1;
//                 }
//             }
//             else if(arr[m]<arr[l] && arr[m]<arr[r]){
//                 if(target <= arr[r] && target >arr[m]){
//                     l=m+1;
//                 }else{
//                     r=m-1;
//                 }
//             }
//             else{
//                 if(arr[m]<target){
//                     l=m+1;
//                 }
//                 else{
//                     r=m-1;
//                 }
//             }
//         }
//         return -1;
        
//     }
