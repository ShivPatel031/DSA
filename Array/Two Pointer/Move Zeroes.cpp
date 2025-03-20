// Move Zeroes
// GFG

// How i solved
void moveZeroes(vector<int>& nums) {
    int i=0,j;
    
    while(i<nums.size() && j<nums.size()){
        while(i<nums.size() && nums[i]){
            i++;
        }
        j=i+1;
        while(j<nums.size() && !nums[j]){
            j++;
        }
        if(j>=nums.size()){
            break;
        }
        swap(nums[i],nums[j]);
    }
    
}

// optimize solution
void moveZeroes(vector<int>& nums) {
         int lastNonZeroFoundAt = 0;
      // If the current element is not 0, then we need to
      // append it just in front of last non 0 element we found.
      for (int i = 0; i < nums.size(); i++) {
          if (nums[i] != 0) {
              nums[lastNonZeroFoundAt++] = nums[i];
          }
      }
    // After we have finished processing new elements,
    // all the non-zero elements are already at beginning of array.
    // We just need to fill remaining elements in the array with 0's.
      for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
          nums[i] = 0;
      }
    }
