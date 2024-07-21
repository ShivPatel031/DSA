// Merge k Sorted Arrays GFG

// Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).

// Examples :

// Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
// Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
// Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
// Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
// Expected Time Complexity: O(k2*Log(k))
// Expected Auxiliary Space: O(k2)

// Constraints:
// 1 <= k <= 100

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector< pair< int, pair< int,int > >> temp;
    
    for(int i = 0 ; i < K ; i++)
    {
        temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
    }
    
    priority_queue< pair< int, pair<int,int> >, vector< pair< int, pair<int,int> > >,greater< pair< int, pair<int,int> > > > q(temp.begin(),temp.end());
    
    vector<int> ans;
    pair< int, pair<int,int> > element;
    int i,j;
    
    while(!q.empty())
    {
        element = q.top();
        q.pop();
        
        ans.push_back(element.first);
        i=element.second.first;
        j=element.second.second;
        
        if(j+1<K)   q.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
    }
    
    return ans;
}
