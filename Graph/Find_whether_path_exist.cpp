// Find whether path exist GFG

// Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
// The description of cells is as follows:

// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall.
// Note: There are only a single source and a single destination.
 
// Examples :

// Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
// Output: 0
// Explanation: The grid is-
// 3 0 3 0 0 
// 3 0 0 0 3 
// 3 3 3 3 3 
// 0 2 3 0 0 
// 3 0 0 1 3 
// There is no path to reach at (3,1) i,e at destination from (4,3) i,e source.
// Input: grid = {{1,3},{3,2}}
// Output: 1
// Explanation: The grid is-
// 1 3
// 3 2
// There is a path from (0,0) i,e source to (1,1) i,e destination.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)
 
// Constraints:
// 1 ≤ n ≤ 500

int row[4]={-1,1,0,0};
int column[4]={0,0,-1,1};
int n;

bool valid(int i ,int j)
{
    return i>=0 && i<n && j>=0 && j<n;
}

bool is_Possible(vector<vector<int>>& grid) 
{
    n = grid.size();
    
    queue<pair<int,int> > q;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j<n;j++)
        {
            if(grid[i][j]==1)
            {
                q.push({i,j});
                grid[i][j]=0;
                break;
            }
        }
    }
    
    while(!q.empty())
    {
        int i =q.front().first;
        int j =q.front().second;
        q.pop();
        
        for(int k=0;k<4;k++)
        {
            if(valid(row[k]+i,column[k]+j) && grid[row[k]+i][column[k]+j]!=0)
            {
                if(grid[row[k]+i][column[k]+j]==2) return 1;
                
                grid[row[k]+i][column[k]+j]=0;
                q.push({row[k]+i,column[k]+j});
            }
        }
    }
    
    return 0;
}
