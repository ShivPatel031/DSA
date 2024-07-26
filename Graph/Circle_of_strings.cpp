// Circle of strings GFG

// Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
// A string X can be chained together with another string Y if the last character of X is same as first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and second with the last character of the string), it will form a circle.

// For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

// Example 1:

// Input:
// N = 3
// A[] = { "abc", "bcd", "cdf" }
// Output:
// 0
// Explaination:
// These strings can't form a circle 
// because no string has 'd'at the starting index.

// Example 2:

// Input:
// N = 4
// A[] = { "ab" , "bc", "cd", "da" }
// Output:
// 1
// Explaination:
// These strings can form a circle 
// of strings.

// Your Task:
// You don't need to read input or print output. Your task is to complete the function isCircle() which takes the length of the array N and the array A as input parameters and returns 1 if we can form a circle or 0 if we cannot.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints: 
// 1 ≤ N ≤ 104
// 1 ≤ Length of strings ≤ 20


void DFS(vector<int> adj[],vector<bool> &visited,int node)
{
    visited[node]=1;
    
    for(int i = 0 ; i < adj[node].size() ; i++)
    {
        if(!visited[adj[node][i]])
        {
            DFS(adj,visited,adj[node][i]);
        }
    }
}

int isCircle(int N, vector<string> A)
{
    vector<int> adj[26];
    vector<bool> visited(26,0);
    vector<int> InDeg(26,0),OutDeg(26,0);
    
    for(int i = 0 ; i < N ; i++)
    {
        adj[A[i][0]-'a'].push_back(A[i][A[i].size()-1]-'a');
        InDeg[A[i][A[i].size()-1]-'a']++;
        OutDeg[A[i][0]-'a']++;
    }
    
    for(int i = 0 ; i < 26 ; i++)
    {
        if(InDeg[i]!=OutDeg[i]) return 0;
    }
    
    DFS(adj,visited,A[0][0]-'a');
    
    for(int i = 0 ; i < 26 ; i++)
    {
        if(InDeg[i] && !visited[i]) return 0;
    }
    
    return 1;
}
