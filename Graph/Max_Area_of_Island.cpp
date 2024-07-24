// Max Area of Island leetcode 695 
// Unit Area of largest region of 1's GFG

// Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
// Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 
// Example 1:

// Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
// Output: 5
// Explanation: The grid is-
// 1 1 1 0
// 0 0 1 0
// 0 0 0 1
// The largest region of 1's is colored
// in orange.

// Example 2:

// Input: grid = {{0,1}}
// Output: 1
// Explanation: The grid is-
// 0 1
// The largest region of 1's is colored in 
// orange.

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m) 

// Constraints:
// 1 ≤ n, m ≤ 500

// in leetcode we didn't accept digonal area as island

int row[8]={-1,-1,0,1,1,1,0,-1};
int column[8]={0,1,1,1,0,-1,-1,-1};
int r,c;

bool valid(int i ,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}

int findMaxArea(vector<vector<int>>& grid) 
{
    r=grid.size();
    c=grid[0].size();
    
    queue<pair<int,int>> q;
    int maxIslandArea=0,area;
    
    for(int i = 0 ; i < r; i++)
    {
        for(int j = 0 ; j < c; j++)
        {
            if(grid[i][j]==1)
            {
                area=0;
                q.push(make_pair(i,j));
                grid[i][j]=0;
                
                while(!q.empty())
                {
                    int k = q.front().first;
                    int l = q.front().second;
                    q.pop();
                    area++;

                  // grid[k][l]='0'; this is working but gives timelimit error;
                    
                    for(int m = 0 ; m<8;m++)
                    {
                        if(valid(row[m]+k,column[m]+l) && grid[row[m]+k][column[m]+l]==1)
                        {
                            grid[row[m]+k][column[m]+l]=0;
                            q.push(make_pair(row[m]+k,column[m]+l));
                        }
                    }
                }
                
                if(maxIslandArea<area) maxIslandArea=area;
    
            }
        }
    }
    
    return maxIslandArea;  
}
