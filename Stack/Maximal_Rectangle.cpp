// Maximal Rectangle leetcode 85 GFG

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

// Example 2:

// Input: matrix = [["0"]]
// Output: 0

// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 
// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

int maximalRectangle(vector<vector<char>>& matrix) 
{
    int n = matrix.size(), index = 0, ans = 0;
    int m = matrix[0].size();

    vector<int> arr(m, 0);
    stack<int> temp;

    for (int k = 0; k < n; k++) 
    {
        for (int l = 0; l < m; l++) 
        {
            if (matrix[k][l] == '1') 
            {
                arr[l]++;
            } 
            else 
            {
                arr[l] = 0;
            }
        }

        for (int i = 0; i < m; i++) 
        {
            while (!temp.empty() && arr[temp.top()] > arr[i]) 
            {
                index = temp.top();
                temp.pop();

                if (!temp.empty()) 
                {
                    ans = max(ans, arr[index] * (i - temp.top() - 1));
                } 
                else 
                {
                    ans = max(ans, arr[index] * i);
                }
            }

            temp.push(i);
        }

        while (!temp.empty()) 
        {
            index = temp.top();
            temp.pop();

            if (!temp.empty()) 
            {
                ans = max(ans, arr[index] * (m - temp.top() - 1));
            } 
            else 
            {
                ans = max(ans, arr[index] * m);
            }
        }
    }

    return ans;
}
