// Search in a row-column sorted Matrix GFG
// Search a 2D Matrix II leetCode 240
 

// Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.

// Example 1:

// Input:
// n = 3, m = 3, x = 62
// matrix[][] = {{ 3, 30, 38},
//               {36, 43, 60},
//               {40, 51, 69}}
// Output: 0
// Explanation:
// 62 is not present in the matrix, 
// so output is 0.
  
// Example 2:

// Input:
// n = 1, m = 6, x = 55
// matrix[][] = {{18, 21, 27, 38, 55, 67}}
// Output: 1
// Explanation: 55 is present in the matrix.

bool search(vector<vector<int> > matrix, int n, int m, int target) 
    {
        int index=0;

        while(index<n){
            
            if(matrix[index][0] <= target && target <= matrix[index][m-1]){
                
                int start=0;
                int end=m-1;
    
                while(start<=end){
                    
                    int mid = start + (end-start)/2;
                                 
                    if(matrix[index][mid] == target)
                    {
                        return 1;
                    }
                    else if( matrix[index][mid]<target)
                    {
                        start=mid+1;
                    }
                    else
                    {
                        end=mid-1;
                    }
                }
            
            }
            
            index++;
        }

        return 0; 
    }

//  more optimize way

// start with top right most corner

bool search(vector<vector<int> > matrix, int n, int m, int target) 
    {
        int row=0,column=m-1;
        
        while(row<n  &&  column >=0 ){
            if(matrix[row][column]== target){
                return 1;
            }
            else if(matrix[row][column] > target){
                    column--;
            }
            else{
                row++;
            }
        }
        
        return 0; 
  }
