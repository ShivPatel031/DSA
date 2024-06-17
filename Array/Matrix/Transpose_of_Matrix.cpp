// Transpose of Matrix

// GFG

// Write a program to find the transpose of a square matrix of size N*N. Transpose of a matrix is obtained by changing rows to columns and columns to rows.

// Example 1:

// Input:
// N = 4
// mat[][] = {{1, 1, 1, 1},
//            {2, 2, 2, 2}
//            {3, 3, 3, 3}
//            {4, 4, 4, 4}}
// Output: 
// {{1, 2, 3, 4},  
//  {1, 2, 3, 4}  
//  {1, 2, 3, 4}
//  {1, 2, 3, 4}}

// Example 2:

// Input:
// N = 2
// mat[][] = {{1, 2},
//            {-9, -2}}
// Output:
// {{1, -9}, 
//  {2, -2}}


void transpose(vector<vector<int> >& matrix, int n)
    { 
        for(int i = 0 ;i<n;i++){
            for (int j=i;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        } 
    }


// Leetcode 867

// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
    
// Example 2:

// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

 vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix[0].size(),vector<int>(matrix.size()));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                result[j][i]=matrix[i][j];
            }
        }

        return result;
    }
