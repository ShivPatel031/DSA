// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

// Example 2:

// Input: x = 8
// Output: 2
//Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.


int mySqrt(int x) {


        if(x<2){
            return x;
        }

        int l=0,r = x,ans=0;
        
        while (l<=r){
            int mid = l + (r - l)/2;

            if (mid == x/mid){ return mid; } // mid*mid == x  === mid == x/mid

            else if (mid > x/mid){ r = mid-1; }

            else{
                ans=mid;
                l = mid +1;
            }
        }

        return ans;
        
    }
