// Union of Two Sorted Arrays GFG

// Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays. Return the elements in sorted order.

// Example 1:

// Input: 
// n = 5, arr1[] = {1, 2, 3, 4, 5}  
// m = 5, arr2 [] = {1, 2, 3, 6, 7}
// Output: 
// 1 2 3 4 5 6 7
// Explanation: 
// Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

// Example 2:

// Input: 
// n = 5, arr1[] = {2, 2, 3, 4, 5}  
// m = 5, arr2[] = {1, 1, 2, 3, 4}
// Output: 
// 1 2 3 4 5
// Explanation: 
// Distinct elements including both the arrays are: 1 2 3 4 5.

// Example 3:

// Input:
// n = 5, arr1[] = {1, 1, 1, 1, 1}
// m = 5, arr2[] = {2, 2, 2, 2, 2}
// Output: 
// 1 2
// Explanation: 
// Distinct elements including both the arrays are: 1 2.
// Your Task: 
// You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays.

// Expected Time Complexity: O(n+m).
// Expected Auxiliary Space: O(n+m).

// Constraints:
// 1 <= n, m <= 105
// -109 <= arr1[i], arr2[i] <= 109

int increment(int i,int arr[],int n)
{
    if(i+1<n)
    {
        int k = i+1;
        while(arr[k]==arr[i])
        {
            k++;
        }
        i=k;
    }
    else
    {
        i++;
    }
    
    return i;
}

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    
    int i = 0 , j = 0 ;
    
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j] || arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            
            if(arr1[i]==arr2[j])
            {
                j=increment(j,arr2,m);
            }
            
            i = increment(i,arr1,n);
            
            
        }
        else if(arr1[i]>arr2[j])
        {
            ans.push_back(arr2[j]);
            
            j=increment(j,arr2,m);
        }
    }
    
    while(i<n)
    {
        ans.push_back(arr1[i]);
            
        i = increment(i,arr1,n);
    }
    
    while(j<m)
    {
        ans.push_back(arr2[j]);
        
        j=increment(j,arr2,m);
    }
    
    return ans;
}
