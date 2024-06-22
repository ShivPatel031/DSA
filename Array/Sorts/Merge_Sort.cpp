// Merge Sort


void merge(vector<int> &arr,int left,int mid,int right)
{

    vector<int> temp;
    int i=left,j=mid+1;

    while(i<=mid && j<=right)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    i=0;
    while(left<=right)
    {
        arr[left]=temp[i];
        left++;
        i++;
    }

}

void mergeSort(vector<int> &arr,int left, int right)
{
    if(left>=right)
    {
        return;
    }

    int mid = left + (right-left)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,mid,right);

}

// if use array
// void merge(int arr[], int left, int mid, int right)
//     {
//         int temp[right+1-left];
        
//         int i=left,j=mid+1,k=0;

//         while(i<=mid && j<=right)
//         {
//             if(arr[i] <= arr[j])
//             {
//                 temp[k]=arr[i];
//                 i++;
//             }
//             else
//             {
//                 temp[k]=arr[j];
//                 j++;
//             }
//             k++;
//         }

//         while(i<=mid)
//         {
//             temp[k]=arr[i];
//             k++;
//             i++;
//         }
    
//         while(j<=right)
//         {
//             temp[k]=arr[j];
//             k++;
//             j++;
//         }
//         i=0;
//         while(left<=right)
//         {
//             arr[left]=temp[i];
//             left++;
//             i++;
//         }
//     }
