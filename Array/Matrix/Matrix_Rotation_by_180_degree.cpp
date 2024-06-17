// Matrix Rotation by 180 degree GFG

// Given a square matrix of size N X N, turn it by 180 degrees in anticlockwise direction without using extra memory.
 

// Example 1:

// Input: N = 4, 
// matrix = {{1, 2, 3, 4}, 
//           {5, 6, 7 ,8}, 
//           {9, 10, 11, 12},
//           {13, 14, 15, 16}}
// Output: {{16, 15, 14, 13}, 
//          {12, 11, 10, 9}, 
//          {8, 7, 6, 5}, 
//          {4, 3, 2, 1}}

// Example 2:

// Input: N = 2,
// matrix = {{1, 2},
//           {3, 4}}
// Output: {{4, 3}, 
//          {2, 1}}



void rotate(vector<vector<int> >& matrix) {
        
        int start=0,end=matrix.size()-1;
        
        while(start<end){
            
            for(int i=0;i<matrix.size();i++){
                
                int temp = matrix[start][i];
                matrix[start][i]=matrix[end][i];
                matrix[end][i]=temp;
            }
            
            start++;
            end--;
        }
        
        for(int i = 0 ;i<matrix.size();i++){

            start =0 ,end=matrix.size()-1;

            while(start<end){
                
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
