// Rotting Oranges GFG leetcode 994

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. 

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0. 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

int row[4]={-1,1,0,0};
int column[4] = {0,0,-1,1};
int r;
int c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;
}

int orangesRotting(vector<vector<int>>& grid) 
{
    r=grid.size();
    c=grid[0].size();
    int timer=0,count;

    queue<pair<int,int> > q;


    for(int i=0 ; i<r ;i++)
    {
        for(int j=0 ; j<c;j++)
        {
            if(grid[i][j]==2)
            {
                q.push(make_pair(i,j));
            }
        }
    }

    if(q.empty())
    { 
        for(int i=0; i < r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }

        return 0;
    }

    while(!q.empty())
    {
        count=q.size();
        timer++;
        while(count--)
        {
            int k =q.front().first;
            int l = q.front().second;
            q.pop();

            for(int m = 0;m < 4;m++)
            {
                if(valid(row[m]+k,column[m]+l) && grid[row[m]+k][column[m]+l]==1)
                {
                    grid[row[m]+k][column[m]+l]=2;
                    q.push(make_pair(row[m]+k,column[m]+l));
                }
            }
        }
    }

    for(int i=0; i < r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]==1) return -1;
        }
    }

    return timer-1;
}
