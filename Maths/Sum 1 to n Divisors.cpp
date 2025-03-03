// Sum 1 to n Divisors
// GFG

// Given a positive integer n, The task is to find the value of Σi F(i) where i is from 1 to n and function F(i) is defined as the sum of all divisors of i.

// Examples:

// Input: n = 4
// Output: 15
// Explanation:
// F(1) = 1
// F(2) = 1 + 2 = 3
// F(3) = 1 + 3 = 4
// F(4) = 1 + 2 + 4 = 7
// So, F(1) + F(2) + F(3) + F(4)
//     = 1 + 3 + 4 + 7 = 15
// Input: n = 5
// Output: 21
// Explanation:
// F(1) = 1
// F(2) = 1 + 2 = 3
// F(3) = 1 + 3 = 4
// F(4) = 1 + 2 + 4 = 7
// F(5) = 1 + 5 = 6
// So,  F(1) + F(2) + F(3) + F(4) + F(5)
//     = 1 + 3 + 4 + 7 + 6 = 21
// Input: n = 1
// Output: 1
// Explanation:
// F(1) = 1
// So,  F(1) = 1 
// Constraints:
// 1 <= n <= 105


// what i thought n^2
int sumOfDivisors(int n) {
  int sum = n;
  for(int i = n; i>1;i--){
      sum+=i;
      for(int j = i-1;j>1;j--){
          if(i%j==0){
              sum+=j;
          }
      }
  }
  
  return sum;
}

// optimize n
int sumOfDivisors(int n) {
    int sum =0;
    
    for(int i = n;i>0;i--){
        int k = n/i;
        sum+=i*k;
    }
    
    return sum;
}
