// Selection Sort
// GFG
void selectionSort(vector<int> &arr) {
        for(int i = 0 ; i < arr.size();i++){
            for(int j=i;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    int temp = arr[i];
                    arr[i] =  arr[j];
                    arr[j]=temp;
                }
            }
        }
    }

// TC N^2
// SC 1

// Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.

// First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
// Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.
// We keep doing this until we get all elements moved to correct position.
