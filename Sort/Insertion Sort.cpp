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

// using recursion
void insertion_sort(vector<int>& arr,int n){
        if(n>=arr.size()) return;
        
        for(int i = n;i>0;i--){
            if(arr[i]<arr[i-1]){
                int temp = arr[i];
                arr[i]=arr[i-1];
                arr[i-1] = temp;
            }else{break;}
        }
        
        insertion_sort(arr,n+1);
    }
    void insertionSort(vector<int>& arr) {
        insertion_sort(arr,1);
    }

// Approach: 

// Select an element in each iteration from the unsorted array(using a loop).
// Place it in its corresponding position in the sorted part and shift the remaining elements accordingly (using an inner loop and swapping).
// The “inner while loop” basically shifts the elements using swapping.
