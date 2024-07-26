// Knight Walk GFG

// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

// Note:
// The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

// Example 1:

// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:

// Knight takes 3 step to reach from
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1). 

// Example 2:

// Input:
// N=8
// knightPos[ ] = {7, 7}
// targetPos[ ] = {1, 5}
// Output:
// 4
// Explanation:
// Knight takes 4 steps to reach from
// (7, 7) to (1, 5):
// (4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.If it cannot reach the target position return -1.

// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(N2).

// Constraints:
// 1 <= N <= 1000
// 1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N


// little optimize
int row[8] ={-2,-2,2,2,-1,1,1,-1};
int column[8]={1,-1,-1,1,2,2,-2,-2};
int r,c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j >= 0 && j<c;
}
  
int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
{
    r=N;c=N;
    queue<pair<int,int> > q;
    vector<vector<int> > visited(N,vector<int> (N,0));
    
    q.push({KnightPos[0]-1,KnightPos[1]-1});
    visited[KnightPos[0]-1][KnightPos[1]-1]=1;
    
    int t=0,count=0;
    
    while(!q.empty())
    {
        t++;
        count=q.size();
        
        while(count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(TargetPos[0]-1==i && TargetPos[1]-1==j) return t-1;
            
            for(int k = 0 ; k < 8;k++)
            {
                  if(valid(row[k]+i,column[k]+j) && !visited[row[k]+i][column[k]+j])
                  {
                      visited[row[k]+i][column[k]+j]=1;
                      
                      q.push({row[k]+i,column[k]+j});
                  }
            }
            
        }
    }
    
    return -1;
}


// what i first thought
int row[4]={-1,1,0,0};
int column[4]={0,0,-1,1};
int drow[8] ={-1,-1,1,1,-1,1,-1,1};
int dcolumn[8]={-1,1,-1,1,-1,-1,1,1};
int r,c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j >= 0 && j<c;
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
{
  r=N;c=N;
  queue<pair<int,int> > q;
  vector<vector<int> > visited(N,vector<int> (N,0));
  
  q.push({KnightPos[0]-1,KnightPos[1]-1});
  visited[KnightPos[0]-1][KnightPos[1]-1]=1;
  
  int t=0,count=0;
  
  while(!q.empty())
  {
      t++;
      count=q.size();
      
      while(count--)
      {
          int i = q.front().first;
          int j = q.front().second;
          q.pop();
          
          if(TargetPos[0]-1==i && TargetPos[1]-1==j) return t-1;
          
          for(int k = 0 ; k < 4;k++)
          {
              for(int m=2*k ; m<(2*k+2) ;m++ )
              {
                  if(valid(row[k]+drow[m]+i,column[k]+dcolumn[m]+j) && !visited[row[k]+drow[m]+i][column[k]+dcolumn[m]+j])
                  {
                      visited[row[k]+drow[m]+i][column[k]+dcolumn[m]+j]=1;
                      
                      q.push({row[k]+drow[m]+i,column[k]+dcolumn[m]+j});
                  }
              }
          }
          
      }
  }
  
  return -1;
}
