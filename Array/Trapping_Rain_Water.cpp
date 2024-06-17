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

        int water = 0, maxindex = 0, lmax = 0, rmax = 0, maxheight = 0;

        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxheight) {
                maxheight = height[i];
                maxindex = i;
            }
        }

        int i = 0;

        while (i < maxindex) {
            if (height[i] > lmax) {
                lmax = height[i];
            }
            water += (lmax - height[i]);
            i++;
        }

        i = height.size() - 1;

        while (maxindex < i) {
            if (height[i] > rmax) {
                rmax = height[i];
            }
            water += (rmax - height[i]);
            i--;
        }

        return water;
    }
