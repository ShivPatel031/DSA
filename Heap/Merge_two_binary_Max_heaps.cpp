// Merge two binary Max heaps GFG

// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

// Example 1:

// Input  : 
// n = 4 m = 3
// a[] = {10, 5, 6, 2}, 
// b[] = {12, 7, 9}
// Output : 
// {12, 10, 9, 2, 5, 7, 6}
// Explanation :
 
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0. 

// Expected Time Complexity: O(n.Logn)
// Expected Auxiliary Space: O(n + m)

// Constraints:
// 1 <= n, m <= 105
// 1 <= a[i], b[i] <= 2*105

void heapify(vector<int> &ans,int index)
{
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if(left<ans.size() && ans[largest]<ans[left]) largest = left;
    if(right<ans.size() && ans[largest]<ans[right]) largest = right;
    
    if(index != largest)
    {
        swap(ans[index],ans[largest]);
        heapify(ans,largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
{
    vector<int> ans;
    
    for(int i = 0 ; i <  n ; i ++)
    {
        ans.push_back(a[i]);
    }
    
    for(int i = 0 ; i < m ; i++)
    {
        ans.push_back(b[i]);
    }
    
    for(int i = ans.size()/2-1;i>=0;i--)
    {
        heapify(ans,i);
    }
    
    return ans;
    
}
