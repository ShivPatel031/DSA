// Greater Number on left

vector<int> leftgreater(vector<int> &a)
{   
    int n = a.size();
    stack<int> temp;
    vector<int> arr(n,-1);
    
    for(int i = n-1;i>=0;i--)
    {
        while(!temp.empty() && a[temp.top()]<a[i])
        {
            arr[temp.top()]=a[i];
            temp.pop();
        }
        
        temp.push(i);
    }
    
    return arr;
}
