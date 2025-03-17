// Insertion Sort
// GFG

void insertionSort(vector<int>& arr) {
        for(int i = 0 ; i < arr.size()-1 ; i++){
            for(int j = i+1;j>=1;j--){
                if(arr[j]<arr[j-1]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1]= temp;
                }
                else
                {
                    break;
                }
            }
        }
    }

// Approach: 

// Select an element in each iteration from the unsorted array(using a loop).
// Place it in its corresponding position in the sorted part and shift the remaining elements accordingly (using an inner loop and swapping).
// The “inner while loop” basically shifts the elements using swapping.
