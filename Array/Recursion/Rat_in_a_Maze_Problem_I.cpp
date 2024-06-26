// Rat in a Maze Problem - I GFG

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.
// Your Task:  
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

int row[4]={-1,0,1,0};
int column[4]={0,1,0,-1};
string direction="URDL";

bool valid(int i,int j,int n)
{
    if(i<0 || j<0 || i>n-1 || j>n-1)
    {
        return false;
    }
    
    return true;
}

void route(vector<string> &ans,string &temp,vector<vector<int> > &m,vector<vector<bool> > &check,int i,int j,int n)
{
    if(i==m.size()-1 && j==m[0].size()-1)
    {
        ans.push_back(temp);
        return;
    }
    
    check[i][j]=1;
    
    for(int k = 0;k<4;k++)
    {
        if(valid(i+row[k],j+column[k],n) && !check[i+row[k]][j+column[k]] && m[i+row[k]][j+column[k]])
        {
            temp.push_back(direction[k]);
            
            route(ans,temp,m,check,i+row[k],j+column[k],n);
            
            temp.pop_back();
        }
    }
    
    check[i][j]=0;
    
}


vector<string> findPath(vector<vector<int>> &m, int n) 
{    
    vector<string> ans;
    
    if(m[0][0]==0 || m[n-1][n-1]==0)
    {
        return ans;
    }
    
    string temp="";
    vector<vector<bool>> check(n,vector<bool> (n,0));
    
    route(ans,temp,m,check,0,0,m.size());
    
    return ans;
}

// not best way but work

// void route(vector<string> &ans,string &temp,vector<vector<int> > &m,vector<vector<bool> > &check,int i,int j)
// {
//     if(i==m.size()-1 && j==m[0].size()-1)
//     {
//         ans.push_back(temp);
//         return;
//     }
    
//     // up
//     if(i>0)
//     {
//         if(m[i-1][j]==1 && !check[i-1][j])
//         {
//             check[i-1][j]=1;
//             temp.push_back('U');
            
//             route(ans,temp,m,check,i-1,j);
            
//             check[i-1][j]=0;
//             temp.pop_back();
//         }
//     }
    
//     if(i<m.size()-1)
//     {
//         if(m[i+1][j]==1 && !check[i+1][j])
//         {
//             check[i+1][j]=1;
//             temp.push_back('D');
            
//             route(ans,temp,m,check,i+1,j);
            
//             check[i+1][j]=0;
//             temp.pop_back();
//         }
//     }
    
//     if(j>0)
//     {
//         if(m[i][j-1]==1 && !check[i][j-1])
//         {
//             check[i][j-1]=1;
//             temp.push_back('L');
            
//             route(ans,temp,m,check,i,j-1);
            
//             check[i][j-1]=0;
//             temp.pop_back();
//         }
//     }
    
//     if(j<m[0].size()-1)
//     {
//         if(m[i][j+1]==1 && !check[i][j+1])
//         {
//             check[i][j+1]=1;
//             temp.push_back('R');
            
//             route(ans,temp,m,check,i,j+1);
            
//             check[i][j+1]=0;
//             temp.pop_back();
//         }
//     }
    
// }


// vector<string> findPath(vector<vector<int>> &m, int n) {
    
//     vector<string> ans;
    
//     if(m[0][0]==0 || m[n-1][n-1]==0)
//     {
//         ans.push_back("-1");
//         return ans;
//     }
    
//     string temp="";
//     vector<vector<bool>> check(n,vector<bool> (n,0));
    
//     check[0][0]=1;
    
//     route(ans,temp,m,check,0,0);
    
//     return ans;
// }
