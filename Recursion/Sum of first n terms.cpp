// Sum of first n terms
// GFG

int sumOfSeries(int n) {
        if(n==1)return 1;
        
        return n*n*n + sumOfSeries(n-1);
}

// Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.

// Examples:

// Input: n = 5
// Output: 225
// Explanation: 13 + 23 + 33 + 43 + 53 = 225
// Input: n = 7
// Output: 784
// Explanation: 13 + 23 + 33 + 43 + 53 + 63 + 73 = 784
// Constraints:
// 1 <= n <= 200 
