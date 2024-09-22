// Climbing Stairs leetcode 70

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:

// 1 <= n <= 45

// Using recursion
int find(int i,int n,vector<int> &dp)
{
    if(i==n) return 1;
    if(i>n) return 0;

    if(dp[i]!=-1) return dp[i];

    return dp[i]=find(i+1,n,dp)+find(i+2,n,dp);
}
int climbStairs(int n) {
    vector<int> dp(n+2,-1);

    return find(0,n,dp);
}

// using loop bottom up
int climbStairs(int n) 
{
    vector<int> dp(n+2,-1);
    dp[n]=1;
    dp[n+1]=0;

    for(int i=n-1;i>=0;i--)
    {
        dp[i]=dp[i+1]+dp[i+2];
    }

    return dp[0];
}

// optimize way
int climbStairs(int n) 
{
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    
    int n1=1,n2=2,i=2,n3;

    while(i<n){
        n3=n2+n1;
        n1=n2;
        n2=n3;
        i++;
    }

    return n3;
}
