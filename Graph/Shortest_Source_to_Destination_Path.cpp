// Shortest Source to Destination Path GFG

// Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
// Note: You can only move left, right, up and down, and only through cells that contain 1.

// Example 1:

// Input:
// N=3, M=4
// A=[[1,0,0,0], 
//    [1,1,0,1],
//    [0,1,1,1]]
// X=2, Y=3 
// Output:
// 5
// Explanation:
// The shortest path is as follows:
// (0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).

// Example 2:

// Input:
// N=3, M=4
// A=[[1,1,1,1],
//    [0,0,0,1],
//    [0,0,0,1]]
// X=0, Y=3
// Output:
// 3
// Explanation:
// The shortest path is as follows:
// (0,0)->(0,1)->(0,2)->(0,3).
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

// Expected Time Complexity:O(N*M)
// Expected Auxillary Space:O(N*M)

// Constraints:
// 1 <= N,M <= 250
// 0 <= X < N
// 0 <= Y < M
// 0 <= A[i][j] <= 1

int row[4]={-1,1,0,0};
int column[4]={0,0,-1,1};
int r,c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;
}

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) 
{
    r=N;c=M;
    
    vector<vector<int>> visited(N,vector<int> (M,0));
    queue<pair<int,int> > q;
    
    if(A[0][0]!=1) return -1;
    
    q.push({0,0});
    visited[0][0]=1;
    int count=0,t = 0;
    bool flag = 0;
    
    while(!q.empty())
    {
        t++;
        count=q.size();
        while(count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i==X && j==Y) flag=1;
            
            for(int m = 0 ; m < 4; m++)
            {
                if(valid(row[m]+i,column[m]+j) && !visited[row[m]+i][column[m]+j] && A[row[m]+i][column[m]+j])
                {
                    visited[row[m]+i][column[m]+j]=1;
                    q.push({row[m]+i,column[m]+j});
                }   
                if(flag) break;
            }   
            if(flag) break;
        }
        if(flag) break;
    }
    
    return flag ? t-1 : -1;
}
