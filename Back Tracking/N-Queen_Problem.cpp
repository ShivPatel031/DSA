// N-Queen Problem GFG leetcode 

// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

// Example 1:

// Input:
// 1
// Output:
// [1]
// Explaination:
// Only one queen can be placed 
// in the single cell available.

// Example 2:

// Input:
// 4
// Output:
// [2 4 1 3 ] [3 1 4 2 ]
// Explaination:
// These are the 2 possible solutions.
 
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function nQueen() which takes n as input parameter and returns a list containing all the possible chessboard configurations in sorted order. Return an empty list if no solution exists.

// Expected Time Complexity: O(n!)
// Expected Auxiliary Space: O(n2) 

// Constraints:
// 1 ≤ n ≤ 10 

// GFG
bool valid(int i,int j,int n,vector<vector<int>> &temp)
{
    int row = i,column = j;
    
    while(row>=0 && column>=0)
    {
        if(temp[row--][column--]==1) return 0;
    }
    
    row=i;
    column=j;
    
    while(row>=0 && column<n)
    {
        if(temp[row--][column++]==1) return 0;
    }
    
    return 1;
}

void findPosition(vector<vector<int>> &ans,vector<vector<int>> &temp,vector<bool> &column,int row)
{
    if(row>=temp.size())
    {
        vector<int> tempans;
        
        for(int i = 0 ; i < column.size() ; i++)
        {   
            for(int j = 0 ; j<column.size() ; j++)
            {
                if(temp[i][j]==1)
                {
                    tempans.push_back(j+1);
                }
            }
        }
        
        ans.push_back(tempans);
        
        return;
    }
    
    for(int i = 0 ; i < column.size(); i++)
    {
        if(!column[i] && valid(row,i,column.size(),temp))
        {
            temp[row][i]=1;
            column[i]=1;
            findPosition(ans,temp,column,row+1);
            temp[row][i]=0;
            column[i]=0;
        }
    }
}

vector<vector<int>> nQueen(int n) 
{
    vector<vector<int>> ans;
    vector<vector<int>> temp(n,vector<int> (n,0));
    vector<bool> column(n,0);
    
    findPosition(ans,temp,column,0);
    
    return ans;
}

// leetcode

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:

// Input: n = 1
// Output: [["Q"]]
 
// Constraints:
// 1 <= n <= 9
  
bool check(int n ,vector<string>&board,int i,int j)
{
    int row = i ,column = j;

    while(row>=0 && column>=0)
    {
        if(board[row][column]=='Q') return 0;
        row--;
        column--;
    }

    row=i;column=j;


    while(row>=0 && column<n)
    {
        if(board[row][column]=='Q') return 0;
        row--;
        column++;
    }

    return 1;
}


void find(int row,int n,vector<vector<string> > &ans,vector<string> &board,vector<bool> &column)
{   
    if(row==n)
    {
        ans.push_back(board);
    }

    for(int i = 0 ;i<n;i++)
    {
        if(column[i]==0 && check(n,board,row,i))
        {
            column[i]=1;
            board[row][i]='Q';
            find(row+1,n,ans,board,column);
            column[i]=0;
            board[row][i]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string> > ans;
    vector<string>board(n);
    vector<bool> column(n,0); 

    for(int i = 0 ; i<n ;i++)
    for(int j = 0 ; j < n ;j++)
    board[i].push_back('.');

    find(0,n,ans,board,column);

    return ans;
}
