// Kth Smallest GFG

// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.
// Note:-  l and r denotes the starting and ending index of the array.

// Example 1:

// Input:
// n = 6
// arr[] = 7 10 4 3 20 15
// k = 3
// l=0 r=5

// Output : 
// 7

// Explanation :
// 3rd smallest element in the given 
// array is 7.

// Example 2:

// Input:
// n = 5
// arr[] = 7 10 4 20 15
// k = 4 
// l=0 r=4

// Output : 
// 15

// Explanation :
// 4th smallest element in the given 
// array is 15.
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer k as input and returns the kth smallest element.
 
// Expected Time Complexity: O(n*log(n) )
// Expected Auxiliary Space: O(log(n))
// Constraints:
// 1 <= n <= 105
// l = 0
// r = N-1
// 1<= arr[i] <= 105
// 1 <= k <= n


// can do using stl priority queue also
// most optimize way
void heapify(int arr[],int index,int n)
{
    int largest = index;
    int left = 2*index+1;
    int right= 2*index+2;
    
    if(left<n && arr[left]>arr[largest] ) largest=left;
    
    if(right<n && arr[right]>arr[largest]) largest=right;
    
    if(index!=largest)
    {
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}

void buildheap(int arr[],int k)
{
    for(int i = k/2-1;i>=0;i--)
    {
        heapify(arr,i,k);
    }
}

int kthSmallest(int arr[], int l, int r, int k) 
{
    buildheap(arr,k);
    
    for(int i = k;i<=r;i++)
    {
        if(arr[i]<arr[0])
        {
            swap(arr[i],arr[0]);
            heapify(arr,0,k);
        }
    }
    return arr[0];
}
