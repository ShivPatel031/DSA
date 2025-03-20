// Check if Array Is Sorted and Rotated
// GFG

// code that i made
bool check(vector<int>& nums) {
        bool ans = true;
        int rotationIndex = -1;
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                rotationIndex=i+1;
            }
        }
        if(rotationIndex==-1){
            return ans;
        }
        int j = rotationIndex;
        
        int travel = nums.size()-1;

        while(travel){
            if(j==nums.size()){
                j=0;
            }
            
            if(j==nums.size()-1){
                if(nums[j]>nums[0]){
                    ans=false;
                    break;
                }
            }
            else if(nums[j]>nums[j+1]){
                ans=false;
                break;
            }

            j++;
            
            travel--;
        }

        return ans;
    }

// othere way
bool check(vector<int>& nums) {
    int n = nums.size();

    // Construct the rotated array
    vector<int> checkSorted(n);

    // Iterate through all possible rotation offsets
    for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
        int currIndex = 0;
        for (int index = rotationOffset; index < n; ++index) {
            checkSorted[currIndex++] = (nums[index]);
        }
        for (int index = 0; index < rotationOffset; ++index) {
            checkSorted[currIndex++] = (nums[index]);
        }

        // Check if the constructed array is sorted
        bool isSorted = true;
        for (int index = 0; index < n - 1; ++index) {
            if (checkSorted[index] > checkSorted[index + 1]) {
                isSorted = false;
                break;
            }
        }

        // If sorted, return true
        if (isSorted) {
            return true;
        }
    }

    // If no rotation makes the array sorted, return false
    return false;
}
