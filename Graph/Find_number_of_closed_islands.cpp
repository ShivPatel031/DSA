// Find number of closed islands GFG leetcode 1254

// Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.
// An island is a 4-directional(up,right,down and left) connected part of 1's.

// Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.

// Example 1:

// Input:
// N = 5, M = 8
// mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
//            {0, 1, 1, 1, 1, 0, 0, 1}, 
//            {0, 1, 0, 1, 0, 0, 0, 1}, 
//            {0, 1, 1, 1, 1, 0, 1, 0}, 
//            {1, 0, 0, 0, 0, 1, 0, 1}}
// Output:
// 2
// Explanation:
// mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
//            {0, 1, 1, 1, 1, 0, 0, 1}, 
//            {0, 1, 0, 1, 0, 0, 0, 1}, 
//            {0, 1, 1, 1, 1, 0, 1, 0}, 
//            {1, 0, 0, 0, 0, 1, 0, 1}} 
// There are 2 closed islands. The islands in dark are closed because they are completely surrounded by 0s (water). There are two more islands in the last column of the matrix, but they are not completely surrounded by 0s. Hence they are not closed islands. 
// Example 2:

// Input:
// N = 3, M = 3
// mat[][] = {{1, 0, 0},
//            {0, 1, 0},
//            {0, 0, 1}}
// Output: 
// 1
// Explanation:
// mat[][] = {{1, 0, 0},
//           {0, 1, 0},
//           {0, 0, 1}}
// There is just a one closed island.
// Your task:
// You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(N*M)

// Constraints:
// 1 ≤ N,M ≤ 500



int row[4] = {-1,1,0,0};
int column[4] = {0,0,-1,1};
int r,c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;    
}

int closedIslands(vector<vector<int>>& matrix, int N, int M) 
{
    queue<pair<int,int> > q;
    
    r=N;c=M;
    
    int islandCount=0;
    
    for(int i = 0 ; i<N;i++)
    {
        for(int j = 0 ; j <M;j++)
        {
            if(!(i==0 or i==N-1) && !(j==0 or j==M-1)) continue;
            
            if(matrix[i][j]==1)
            {
                q.push(make_pair(i,j));
                matrix[i][j]=0;
                
                while(!q.empty())
                {
                    int k = q.front().first;
                    int l = q.front().second;
                    q.pop();
                    
                    for(int m = 0 ; m<4;m++)
                    {
                        if(valid(row[m]+k,column[m]+l) && matrix[row[m]+k][column[m]+l]==1)
                        {
                            matrix[row[m]+k][column[m]+l]=0;
                            q.push(make_pair(row[m]+k,column[m]+l));
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 1 ; i<N-1;i++)
    {
        for(int j = 1 ; j <M-1;j++)
        {
            if(matrix[i][j]==1)
            {
                q.push(make_pair(i,j));
                matrix[i][j]=0;
                islandCount++;
                
                while(!q.empty())
                {
                    int k = q.front().first;
                    int l = q.front().second;
                    q.pop();
                    
                    for(int m = 0 ; m<4;m++)
                    {
                        if(valid(row[m]+k,column[m]+l) && matrix[row[m]+k][column[m]+l]==1)
                        {
                            matrix[row[m]+k][column[m]+l]=0;
                            q.push(make_pair(row[m]+k,column[m]+l));
                        }
                    }
                }
            }
        }
    }
    
    return islandCount;
}
