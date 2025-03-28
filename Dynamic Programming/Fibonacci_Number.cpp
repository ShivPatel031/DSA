// Fibonacci Number leetcode 509

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n). 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

// Example 3:
  
// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 
// Constraints:

// 0 <= n <= 30


// top down 
int fibo(int n,vector<int> &dp)
{
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];
    else return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

int fib(int n) {

    vector<int> dp(n+1,-1);

    return fibo(n,dp);        
}


// bootom up 
int fib(int n) 
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    if(n>0) dp[1]=1;

    for(int i = 2 ; i < n+1 ; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}


// bottom up with space optimization
int fib(int n) 
{
    if(n<=1) return n;

    vector<int> dp(3,-1);
    dp[0]=0;
    dp[1]=1;

    for(int i = 2 ; i < n+1 ; i++)
    {
        dp[2]=dp[1]+dp[0];
        dp[0]=dp[1];
        dp[1]=dp[2];
    }

    return dp[2];
}

// using map
int returnfib(int n,map<int,int> &m)
{
    if(m[n]) return m[n];
    if(n<=2) return 1;
    m[n]=returnfib(n-1,m)+returnfib(n-2,m);
    return m[n];
}
int fib(int n) {

    if(n<=1) return n;
    map<int,int> m;

    return returnfib(n,m);
}
