// Quick Sort
// GFG

void quickSort(vector<int>& arr, int low, int high) {
        if(low<high)
        {
            int p =  partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }   
    }


int partition(vector<int>& arr, int low, int high) {
     int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// This algorithm is basically a repetition of two simple steps that are the following:

// Pick a pivot and place it in its correct place in the sorted array.
// Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.
// Now, let’s discuss the steps in detail considering the array {4,6,2,5,7,9,1,3}:

// Step 1: The first thing is to choose the pivot. A pivot is basically a chosen element of the given array. The element or the pivot can be chosen by our choice. So, in an array a pivot can be any of the following:

// The first element of the array
// The last element of the array
// Median of array
// Any Random element of the array
// After choosing the pivot(i.e. the element), we should place it in its correct position(i.e. The place it should be after the array gets sorted) in the array. For example, if the given array is {4,6,2,5,7,9,1,3}, the correct position of 4 will be the 4th position.

// Note: Here in this tutorial, we have chosen the first element as our pivot. You can choose any element as per your choice.

// Step 2: In step 2, we will shift the smaller elements(i.e. Smaller than the pivot) to the left of the pivot and the larger ones to the right of the pivot. In the example, if the chosen pivot is 4, after performing step 2 the array will look like: {3, 2, 1, 4, 6, 5, 7, 9}. 

// From the explanation, we can see that after completing the steps, pivot 4 is in its correct position with the left and right subarray unsorted. Now we will apply these two steps on the left subarray and the right subarray recursively. And we will continue this process until the size of the unsorted part becomes 1(as an array with a single element is always sorted).

// So, from the above intuition, we can get a clear idea that we are going to use recursion in this algorithm.

// To summarize, the main intention of this process is to place the pivot, after each recursion call, at its final position, where the pivot should be in the final sorted array.

