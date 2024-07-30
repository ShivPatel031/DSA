// Strongly connected component (Tarjans's Algo) GFG

// Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.
// Note - Sort both the individual components and array of the components.

// Example 1:

// Input:

// Output:
// 0 1 2,3,4,
// Explanation:

// We can clearly see that there are 3 Strongly
// Connected Components in the Graph as mentioned
// in the Output.

// Example 2:

// Input:

// Output:
// 0 1 2,
// Explanation:
// All of the nodes are connected to each other.
// So, there's only one SCC as shown.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
// Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order. The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).

// Constraints:
// 1 ≤ V  ≤ 105
// 1 ≤ E  ≤ 105
// 0 ≤ u, v ≤ N-1 

void DFS(int node,int &count,stack<int> &s,vector<bool> &visited,vector<bool> &instack,vector<int> &disc,vector<int> &low,vector<vector<int>>  &ans,vector<int> adj[])
{
    visited[node]=1;
    disc[node]=low[node]=count;
    s.push(node);
    instack[node]=1;
    
    for(int i = 0 ; i < adj[node].size();i++)
    {
        int neig = adj[node][i];
        
        if(!visited[neig])
        {
            count++;
            DFS(neig,count,s,visited,instack,disc,low,ans,adj);
            low[node]=min(low[node],low[neig]);
        }
        else
        {
            if(instack[neig]) low[node] = min(low[node],disc[neig]);
        }
    }
    
    if(disc[node]==low[node])
    {
        vector<int> temp;
        
        while(!s.empty() && (s.top()!=node) )
        {
            temp.push_back(s.top());
            instack[s.top()]=0;
            s.pop();
        }
        
        temp.push_back(node);
        instack[node]=0;
        s.pop();
        
        sort(temp.begin(),temp.end());
        
        ans.push_back(temp);
    }
}

vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    vector<vector<int>> ans;
    vector<int> disc(V);
    vector<int> low(V);
    int count=0;
    stack<int> s;
    vector<bool> visited(V,0);
    vector<bool> instack(V,0);
    
    for(int i = 0 ; i < V ; i++)
    {
        if(!visited[i]) 
        {
            DFS(i,count,s,visited,instack,disc,low,ans,adj);
        }
    }
    
    sort(ans.begin(),ans.end());
    
    return ans;
}
