// Find the number of islands GFG leetcode 200

// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
// Example 1:

// Input:
// grid = {{0,1},{1,0},{1,1},{1,0}}
// Output:
// 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.

// Example 2:

// Input:
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output:
// 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0 
// There are two islands :- one is colored in blue 
// and other in orange.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

// Expected Time Complexity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500

// in leetcode we didn't consider digonal so we have to show just 4 side;

int row[8]={-1,-1,0,1,1,1,0,-1};
int column[8]={0,1,1,1,0,-1,-1,-1};
int r,c;

bool valid(int i ,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}

int numIslands(vector<vector<char>>& grid) 
{
    
    r=grid.size();
    c=grid[0].size();
    
    queue<pair<int,int>> q;
    int islandCount=0;
    
    for(int i = 0 ; i < r; i++)
    {
        for(int j = 0 ; j < c; j++)
        {
            if(grid[i][j]=='1')
            {
                q.push(make_pair(i,j));
                islandCount++;
                grid[i][j]='0';
                
                while(!q.empty())
                {
                    int k = q.front().first;
                    int l = q.front().second;
                    q.pop();

                  // grid[k][l]='0'; this is working but gives timelimit error;
                    
                    for(int m = 0 ; m<8;m++)
                    {
                        if(valid(row[m]+k,column[m]+l) && grid[row[m]+k][column[m]+l]=='1')
                        {
                            grid[row[m]+k][column[m]+l]='0';
                            q.push(make_pair(row[m]+k,column[m]+l));
                        }
                    }
                }
    
            }
        }
    }
    
    
    return islandCount;
}
