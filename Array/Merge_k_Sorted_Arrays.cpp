// Merge k Sorted Arrays GFG

vector<int> mearge(vector<int> & l1,vector<int> &l2)
{
    int i = 0 ,j=0;
    vector<int> ans;
    
    while(i<l1.size() && j < l2.size())
    {
        if(l1[i]<l2[j])
        {
            ans.push_back(l1[i++]);
        }
        else
        {
            ans.push_back(l2[j++]);
        }
    }
    
    while(i<l1.size())
    {
        ans.push_back(l1[i++]);
    }
    
    while(j<l2.size())
    {
        ans.push_back(l2[j++]);
    }
    
    return ans;
}

void meargeSort(vector<vector<int>> &arr,int start,int end)
{
    if(start>=end) return;
    
    int mid = (start+end)/2;
    
    meargeSort(arr,start,mid);
    meargeSort(arr,mid+1,end);
    
    arr[start] = mearge(arr[start],arr[mid+1]);
}

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    meargeSort(arr,0,K-1);
    return arr[0];
}
