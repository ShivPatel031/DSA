// Height of Heap GFG

// Given a Binary Heap of size N in an array arr[]. Write a program to calculate the height of the Heap.

// Note: Return 1 if the N is 1.

// Example 1:

// Input: N = 6
// arr = {1, 3, 6, 5, 9, 8}
// Output: 2
// Explaination: The tree is like the following
//            (1)
//        /   \
//     (3)    (6)
//     / \     /
//   (5) (9) (8)

int heapHeight(int N, int arr[])
{
    if(N==1)
    {
        return 1;
    }
    
    int height=0;
    
    while(N>1)
    {
        height++;
        N/=2;
    }
    
    return height;
}
