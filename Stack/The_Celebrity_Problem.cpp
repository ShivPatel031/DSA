// The Celebrity Problem GFG

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Return the index of the celebrity, if there is no celebrity return -1.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N) 

// Example 1:

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity. 

// Example 2:

// Input:
// N = 2
// M[][] = {{0 1},
//          {1 0}}
// Output: -1
// Explanation: The two people at the party both
// know each other. None of them is a celebrity.

// Your Task:
// You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.

// Expected Time Complexity: O(N^2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 3000
// 0 <= M[][] <= 1

int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> temp;
    
    for(int i  = n-1 ; i>=0 ;i--)
    {
        temp.push(i);
    }
    
    while(temp.size()>1)
    {
        int first = temp.top();
        temp.pop();
        int second = temp.top();
        temp.pop();
        
        if(M[first][second]==1  && M[second][first]==0)
        {
            temp.push(second);
        }
        else if(M[first][second]==0  && M[second][first]==1)
        {
            temp.push(first);
        }
        
    }
    
    if(temp.empty())
    {
        return -1;
    }
    
    int index = temp.top();
    
    int row=0,column=0;
    
    for(int i = 0 ; i<n;i++)
    {
        row+=M[index][i];
        column+=M[i][index];
    }
    
    return row==0 && column==n-1 ? index :-1;
}
