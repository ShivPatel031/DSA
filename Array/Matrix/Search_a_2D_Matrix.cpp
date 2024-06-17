// Search a 2D Matrix leetCode 74

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int start = 0 , end  =  matrix.size()-1,index=0;

        while(start<=end){

            int mid = start + (end-start)/2;
            if(matrix[mid][0] <= target){
                index=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        start=0;
        end=matrix[0].size()-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(matrix[index][mid] == target){
                return 1;
            }
            else if( matrix[index][mid]<target)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return 0;
        
    }


//  other way using one loop

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int start = 0 , end  =  matrix.size()*matrix[0].size()-1;

        while(start<=end){

            int mid = start + (end-start)/2;

            int row=mid/matrix[0].size();
            int column = mid%matrix[0].size();
            if(matrix[row][column] == target){
                return 1;
            }
            else if(matrix[row][column] < target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return 0;
        
}

