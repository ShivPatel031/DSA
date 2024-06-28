// Next Smaller Element

vector<int> nextSmallerElement(vector<int> &arr)
{
    stack<int> temp;

    for(int i = 0;i<arr.size();i++)
    {
        while(!temp.empty() && arr[temp.top()] > arr[i])
        {
            arr[temp.top()]=arr[i];
            temp.pop();
        }

        temp.push(i);
    }

    while(!temp.empty())
    {
        arr[temp.top()]=-1;
        temp.pop();
    }

    return arr;
}
