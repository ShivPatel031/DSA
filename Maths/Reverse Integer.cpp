// Reverse Integer
// Leetcode

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1

// how  i solve
int reverse(int x) 
{
        long ans = 0;
        bool isNegetive = x < 0;

        if(x==INT_MIN) return 0;

        if(isNegetive) x=x*-1;

        while(x){
            
            if(ans > INT_MAX/10) return 0;

            int rem = x % 10;
            ans=ans*10 + rem;
            x = x/10;

        }

        if(isNegetive) ans = ans*-1;

        return ans;
}

// othere solution
int reverse(int x) 
{
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x

            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause
                          // overflow/underflow
            }

            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10;             // Remove the last digit from x
        }
        return ans; // Return the reversed number
}
