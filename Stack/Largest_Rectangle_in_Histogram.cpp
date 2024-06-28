// Largest Rectangle in Histogram leetCode 84

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
  
// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
  
// Example 2:

// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

 int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size(),ans=0,index = 0;

    stack<int> temp;

    for(int i = 0;i<n;i++){

        while(!temp.empty() && heights[temp.top()]>heights[i])
        {   
            index=temp.top();
            temp.pop();

            if(!temp.empty())
            {
                ans=max(ans,heights[index]*(i-temp.top()-1));
            }
            else
            {
                ans=max(ans,heights[index]*i);
            }
        }

        temp.push(i);
    }

    while(!temp.empty())
    {
        index=temp.top();
        temp.pop();
        
        if(!temp.empty())
        {
            ans=max(ans,heights[index]*(n-temp.top()-1));
        }
        else
        {
            ans=max(ans,heights[index]*n);
        }
    }
    
    return ans;
}

// what i thought first
// int largestRectangleArea(vector<int>& heights) 
// {
//     int n = heights.size(),max=0;
//     vector<int> gleft(n, 1);
//     vector<int> gright(n,1);
//     stack<int> temp;

//     for (int i = 0; i < n; i++) {
//         while (!temp.empty() && heights[temp.top()] >= heights[i]) {
//             gleft[i] += gleft[temp.top()];
//             temp.pop();
//         }

//         temp.push(i);
//     }

//     while(!temp.empty())
//     {
//         temp.pop();
//     }

//     for (int i = n-1;i>=0; i--) {
//         while (!temp.empty() && heights[temp.top()] >= heights[i]) {
//             gright[i] += gright[temp.top()];
//             temp.pop();
//         }

//         temp.push(i);
//     }

//     for(int i = 0;i<n;i++)
//     {
//         gleft[i]+=gright[i]-1;

//         if(max<gleft[i]*heights[i])
//         {
//             max=gleft[i]*heights[i];
//         }
//     }

//     return max;
// }
