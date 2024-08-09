// Magic Squares In Grid leetcode 840

// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
// Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

// Example 1:

// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:
// while this one is not:
// In total, there is only one magic square inside the given grid.

// Example 2:

// Input: grid = [[8]]
// Output: 0
 
// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 10
// 0 <= grid[i][j] <= 15

// good and optimize way
bool isMagic(vector<vector<int>>&grid, int i, int j)
{
    int n=grid.size();
    int m=grid[0].size();
    if(i+2<n && j+2<m){

        int col1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        int col2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
        int col3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
        int row1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
        int row2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
        int row3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
        int dia1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int dia2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

        if((col1==col2) && (col1==col3) && (col1==row1) && (col1==row2) && (col1==row3) && (col1==dia1) && (col1==dia2)){
            set<int>s{1,2,3,4,5,6,7,8,9};
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    s.erase(grid[i+k][j+l]);
                }
            }
            return s.empty();
        }
    }
    return false;
}
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isMagic(grid,i,j)){
                count++;
            }
        }
    }
    return count;
}


// what infirst thought
int numMagicSquaresInside(vector<vector<int>>& grid) 
{
    int row=grid.size(),col=grid[0].size();

    if(row<2 or col<2) return 0;

   int count=0;

   int rt=0,rb=2,cl=0,cr=2,c=0;

   while(rb<row)
   {
        bool flag=0;
        int sum=INT_MIN;

        vector<int> check(10,0);

        for(int i=rt;i<=rb;i++)
        {
            int temp=0;
            for(int j=cl;j<=cr;j++)
            {
                temp+=grid[i][j];

                if(grid[i][j]>9 or grid[i][j]==0 or check[grid[i][j]]==1)
                { 
                    flag=1;
                    break;
                }
                else
                {
                    check[grid[i][j]]++;
                }
            }
            
            if(sum==INT_MIN)    sum=temp;
            else if(sum != temp)
            {   
                flag=1;
                break;
            }
        }

        if(!flag)
        {
            for(int i=cl;i<=cr;i++)
            {
                int temp=0;
                for(int j=rt;j<=rb;j++) temp+=grid[j][i];
                
                if(sum != temp)
                {   
                    flag=1;
                    break;
                }
            }
        }

        if(!flag)
        {
            int temp=0;
            int j = cl;
            for(int i = rt ; i <=rb ; i++)
            {
                temp+=grid[i][j];
                j++;
            }
           
            if(sum!=temp)   flag=1;

            if(!flag)
            {
                temp=0;
                j=cl;
                for(int i=rb;i>=rt;i--)
                {
                    temp+=grid[i][j];
                    j++;
                }
               
                if(sum!=temp)   flag=1;
            }
        }
        
        if(!flag) count++;

        if(cr<col-1)
        {
            cl++;
            cr++;
        }
        else
        {
            cr=2;
            cl=0;
            rt++;
            rb++;
        }
   } 

   return count;    
}
