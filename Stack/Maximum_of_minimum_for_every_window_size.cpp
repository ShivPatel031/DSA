// Maximum of minimum for every window size

// Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
// Note: Window size varies from 1 to the size of the Array.

// Example 1:

// Input:
// N = 7
// arr[] = {10,20,30,50,10,70,30}
// Output: 70 30 20 10 10 10 10 
// Explanation: 
// 1.First element in output
// indicates maximum of minimums of all
// windows of size 1.
// 2.Minimums of windows of size 1 are {10},
//  {20}, {30}, {50},{10}, {70} and {30}. 
//  Maximum of these minimums is 70. 
// 3. Second element in output indicates
// maximum of minimums of all windows of
// size 2. 
// 4. Minimums of windows of size 2
// are {10}, {20}, {30}, {10}, {10}, and
// {30}.
// 5. Maximum of these minimums is 30 
// Third element in output indicates
// maximum of minimums of all windows of
// size 3. 
// 6. Minimums of windows of size 3
// are {10}, {20}, {10}, {10} and {10}.
// 7.Maximum of these minimums is 20. 
// Similarly other elements of output are
// computed.

// Example 2:

// Input:
// N = 3
// arr[] = {10,20,30}
// Output: 30 20 10
// Explanation: First element in output
// indicates maximum of minimums of all
// windows of size 1.Minimums of windows
// of size 1 are {10} , {20} , {30}.
// Maximum of these minimums are 30 and
// similarly other outputs can be computed
// Your Task:
// The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

// Expected Time Complxity : O(N)
// Expected Auxilliary Space : O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= arr[i] <= 106

// can solve using next right smallest  and next left smallest element usnig stack in O(N)
vector <int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n,0);
    stack<int> temp;
    
    for(int i = 0 ;i<n;i++)
    {   
        while(!temp.empty() && arr[temp.top()]>arr[i])
        {
            int index = temp.top();
            temp.pop();
            int range = 0;
            
            if(temp.empty())
            {
                range= i;
            }
            else{
                range=i-temp.top()-1;
            }
            
            ans[range-1]=max(ans[range-1],arr[index]);
        }
        
        temp.push(i);
    }
    
    while(!temp.empty())
    {
        int index = temp.top();
        temp.pop();
        int range = 0;
        
        if(temp.empty())
        {
            range= n;
        }
        else{
            range=n-temp.top()-1;
        }
        
        ans[range-1]=max(ans[range-1],arr[index]);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    
    return ans;
}


// but timeCommplexity is O(n^3)
// vector <int> maxOfMin(int arr[], int n)
// {
//     vector<int> ans(n,0);
    
//     for(int i = 0 ;i<n;i++)
//     {   
//         for(int j = 0 ; j<n-i;j++)
//         {
//             int m = INT_MAX;
//             for(int k=j ; k<j+i+1; k++)
//             {
//                 m=min(m,arr[k]);
//             }   
//             ans[i]=max(ans[i],m);
//         }   
//     } 
//     return ans;
// }
