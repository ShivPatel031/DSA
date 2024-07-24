// Replace O's with X's GFG

// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Example 1:

// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix. 

// Example 2:

// Input: 
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500


// what i thought
int row[4] = {-1,1,0,0};
int column[4] = {0,0,-1,1};
int r,c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;    
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    queue<pair<int,int> > q;
    
    r=n;c=m;
    
    for(int i = 0 ; i<n;i++)
    {
        for(int j = 0 ; j <m ; j++)
        {
            if(!(i==0 or i==n-1) && !(j==0 or j==m-1)) continue;
            
            if(mat[i][j]=='O')
            {
                q.push(make_pair(i,j));
                
                
                while(!q.empty())
                {
                    int k = q.front().first;
                    int l = q.front().second;
                    q.pop();
                    mat[k][l]='T';
            
                    for(int m = 0 ; m<4;m++ )
                    {
                        if(valid(row[m]+k,column[m]+l) && mat[row[m]+k][column[m]+l]=='O')
                        {
                            q.push(make_pair(row[m]+k,column[m]+l));
                        }
                    }
                }
            }
            
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j<m;j++)
        {
            if(mat[i][j]=='O') mat[i][j]='X';
            else if(mat[i][j]=='T') mat[i][j]='O';
        }
    }
    
    return  mat;
}

// other way
int row[4] = {-1,1,0,0};
int column[4] = {0,0,-1,1};
int r,c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;    
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    queue<pair<int,int> > q;   
    r=n;c=m;
    
    for(int i = 0 ; i< m ;i++)
    {
        if(mat[0][i]=='O')
        {
            mat[0][i]='T';
            q.push(make_pair(0,i));
        }
    }
    
    for(int i = 1 ; i< n;i++)
    {
        if(mat[i][0]=='O')
        {
            mat[i][0]='T';
            q.push(make_pair(i,0));
        }
    }
    
    for(int i = 1 ; i< n;i++)
    {
        if(mat[i][m-1]=='O')
        {
            mat[i][m-1]='T';
            q.push(make_pair(i,m-1));
        }
    }
    
    for(int i = 1 ; i< m-1;i++)
    {
        if(mat[n-1][i]=='O')
        {
            mat[n-1][i]='T';
            q.push(make_pair(n-1,i));
        }
    }

    while(!q.empty())
    {
        int k = q.front().first;
        int l = q.front().second;
        q.pop();
        
        for(int m = 0 ; m<4;m++ )
        {
            if(valid(row[m]+k,column[m]+l) && mat[row[m]+k][column[m]+l]=='O')
            {
                mat[row[m]+k][column[m]+l]='T';
                q.push(make_pair(row[m]+k,column[m]+l));
            }
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j<m;j++)
        {
            if(mat[i][j]=='O') mat[i][j]='X';
            else if(mat[i][j]=='T') mat[i][j]='O';
        }
    }
    
    return  mat;
}
