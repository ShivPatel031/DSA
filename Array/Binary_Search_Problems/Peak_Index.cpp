// Peak Index in a Mountain Array


//Example 1:

//Input: arr = [0,1,0]
//Output: 1

//Example 2:

//Input: arr = [0,2,1,0]
//Output: 1

//Example 3:

//Input: arr = [0,10,5,2]
//Output: 1



int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0,r = arr.size()-1,result = 0;

        while(l<=r){

            int m = r + (l-r)/2;

                if(arr[m]  > arr[m+1] && arr[m] > arr[m-1]){
                    result=m;
                    break;
                }
                else if (arr[m] > arr[m-1]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
        }

        return result;
    }
