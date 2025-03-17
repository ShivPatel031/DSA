// Merge Sort
// GFG

void merge(vector<int>& arr,int l,int m,int r){
        int ls=l;
        int rs=m+1;
        vector<int> temp;
        
        while(ls<=m && rs<=r){
            if(arr[ls]>arr[rs]){
                temp.push_back(arr[rs]);
                rs++;
            }
            else{
                temp.push_back(arr[ls]);
                ls++;
            }
        }
        
        while(ls<=m){
            temp.push_back(arr[ls]);
                ls++; 
        }
        
        while(rs<=r){
            temp.push_back(arr[rs]);
                rs++; 
        }
        
        int ti=0;
        
        for(int i = l ; i<=r;i++){
            arr[i]=temp[ti];
            ti++;
        }
        
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r) return;
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }


// for best  understand and well writen code
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}
