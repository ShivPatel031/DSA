// Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
  
int trap(vector<int>& height) {

        int water = 0, left = 0, right = height.size() - 1, lmax = height[left],
            rmax = height[right];

        while (left < right) {

            if (height[left] < height[right]) {
                left++;
                if (height[left] > lmax) {
                    lmax = height[left];
                } else {
                    water += (lmax - height[left]);
                }

            } else {
                right--;
                if (height[right] > rmax) {
                    rmax = height[right];
                } else {
                    water += (rmax - height[right]);
                }
            }
        }

        return water;
    }
