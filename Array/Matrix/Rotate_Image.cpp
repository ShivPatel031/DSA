// Rotate Image leetCode 48

// CLOCKWISE(NOTE)

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++){

            for(int j=i+1;j<matrix.size();j++){

                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0 ;i<matrix.size();i++){

            int start =0 ,end=matrix.size()-1;

            while(start<end){
                
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }


// GFG

// ANTI-CLOCKWISE(NOTE)

// Given a square matrix of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space. 

// Example 1:

// Input:
// N = 3 
// matrix[][] = {{1, 2, 3},
//               {4, 5, 6}
//               {7, 8, 9}}
// Output: 
// Rotated Matrix:
// 3 6 9
// 2 5 8
// 1 4 7

// Example 2:

// Input:
// N = 2
// matrix[][] = {{1, 2},
//               {3, 4}}
// Output: 
// Rotated Matrix:
// 2 4
// 1 3

void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        
        for(int i=0;i<matrix.size();i++){

            for(int j=i+1;j<matrix.size();j++){

                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0 ;i<matrix.size();i++){

            int start =0 ,end=matrix.size()-1;

            while(start<end){
                
                swap(matrix[start][i],matrix[end][i]);
                start++;
                end--;
            }
        }
    
    }
