// Next Greater Element in Circular Array GFG leetcode 503

// Given an circular array arr[ ] of size n having distinct elements, the task is to find the next greater element for each element of the array .
// Note : The next greater element of an element in the array is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number. 

// Example 1:

// Input: 
// n = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3, 3 is 4, 2 is 4 and for 4? 
// since it doesn't exist, it is -1.

// Example 2:

// Input: 
// n = 5, arr[] = [6 8 0 1 3]
// Output:
// 8 -1 1 3 6
// Explanation:
// In the array, the next larger element to 6 is 8, 
// for 8 there is no larger elements hence it is -1, for 0 it is 1,
// for 1 it is 3 and then 
// for 3 there is 6.

// Your Task:
// This is a function problem. You only need to complete the function nextLargerElement() that takes list of integers arr[ ] and n as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)

// Constraints:
// 1 ≤ n ≤ 10^6
// 0 ≤ arri ≤ 10^18

vector<long long> nextLargerElement(vector<long long> &arr, int n)
{        
    long long max = arr[0];
    int index = 0;
    
    for(int i = 1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            index=i;
        }
        
    }
    
    stack<int> temp;
    
    int i;
    
    if(index+1>=n)
    {
        i=0;
    }
    else
    {
        i=index+1;
    }
    
    temp.push(i);
    i++;
    
    int count = 1;
    
    while(count < n)
    {
        if(i>=n){
            i=0;
        }
        
        if(arr[temp.top()]<arr[i])
        {
            while(!temp.empty() && arr[temp.top()]<arr[i])
            {
                arr[temp.top()]=arr[i];
                temp.pop();
            }
            
            temp.push(i);
        }
        else
        {
            temp.push(i);
        }
        
        i++;
        count++;
        
    }
    
    while(!temp.empty())
    {
        arr[temp.top()]=-1;
        temp.pop();
    }
    
    return arr;
}
