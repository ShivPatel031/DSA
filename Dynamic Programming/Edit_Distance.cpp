// Edit Distance GFG

// Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.
// Examples:

// Input: str1 = "geek", srt2 = "gesek"
// Output: 1
// Explanation: One operation is required, inserting 's' between two 'e'.
// Input : str1 = "gfg", str2 = "gfg"
// Output: 0
// Explanation: Both strings are same.
// Expected Time Complexity: O(|str1|*|str2|)
// Expected Space Complexity: O(|str1|*|str2|)

// Constraints:
// 1 ≤ str1.length(), str2.length() ≤ 100
// Both the strings are in lowercase.


int editDistance(string str1, string str2) 
{
    int n = str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i = 0 ; i <= n ; i++) dp[i][0]=i;
    
    for(int i = 0 ; i <= m ; i++) dp[0][i]=i;
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    
    return dp[n][m];
}
