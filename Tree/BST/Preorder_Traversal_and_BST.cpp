// Preorder Traversal and BST GFG

// Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.

// Example 1:

// Input:
// N = 3
// arr = {2, 4, 3}
// Output: 1
// Explaination: Given arr[] can represent
// preorder traversal of following BST:
//                2
//                 \
//                  4
//                 /
//                3
// Example 2:

// Input:
// N = 3
// Arr = {2, 4, 1}
// Output: 0
// Explaination: Given arr[] cannot represent
// preorder traversal of a BST.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function canRepresentBST() which takes the array arr[] and its size N as input parameters and returns 1 if given array can represent preorder traversal of a BST, else returns 0.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105
// 0 ≤ arr[i] ≤ 105


// using itration
int canRepresentBST(int arr[], int N) 
{
    stack<int> lower,upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    
    for(int i=0;i<N;i++)
    {
        if(arr[i]<lower.top()) return 0;
        
        while(arr[i]>upper.top())
        {
            lower.pop();
            upper.pop();
        }
        
        int low=lower.top();
        int up=upper.top();
        lower.pop();
        upper.pop();
        
        lower.push(arr[i]);
        upper.push(up);
        
        lower.push(low);
        upper.push(arr[i]);
    }
    
    return 1;
}

// this code is true but onilne compiler will give you error because recursion will use static memory and online compiler give low static memory so but if we solve 
// it using stl stack then it will work because stack use dynamic memory
void checkBST(int arr[],int N,int &index,int low,int high)
{
    if(index==N || arr[index]<low || arr[index]>high) return;
    
    int val=arr[index++];
    
    if(index<N)
    {
        
        if(arr[index]<val && arr[index]>low)
        {
            checkBST(arr,N,index,low,val);
        }
        
        if(arr[index]>val && arr[index]<high)
        {
            checkBST(arr,N,index,val,high);
        }
    }
}

int canRepresentBST(int arr[], int N) 
{
    int index = 0;
    
    checkBST(arr,N,index,INT_MIN,INT_MAX);
    
    return index==N;
}
