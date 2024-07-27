// Articulation Point - I GFG

// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// Example 1:

// Input:

// Output:{1,4}
// Explanation: Removing the vertex 1 will
// discconect the graph as-

// Removing the vertex 4 will disconnect the
// graph as- 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 
// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
 
// Constraints:
// 1 ≤ V ≤ 105

void DFS(int node,int parent,int &count,vector<int> adj[],vector<bool> &ans,vector<int> &disc,vector<int> &low,vector<bool> &visited)
{
    disc[node]=low[node]=count;
    visited[node]=1;
    int child=0;
    
    for(int i = 0 ; i< adj[node].size();i++)
    {
        int neighbour=adj[node][i];
        
        if(neighbour==parent) continue;
        
        else if(visited[neighbour]) low[node]=min(low[node],disc[neighbour]);
        
        else
        {
            child++;
            count++;
            DFS(neighbour,node,count,adj,ans,disc,low,visited);
            
            if(disc[node]<=low[neighbour] && parent!=-1)
            {
                ans[node]=1;
            }
            
            low[node]=min(low[node],low[neighbour]);
        }
    }
    
    if(child>1 && parent==-1) ans[0]=1;
}

vector<int> articulationPoints(int V, vector<int>adj[]) 
{
    vector<bool> ans(V,0);
    vector<int> disc(V,0);
    vector<int> low(V,0);
    vector<bool> visited(V,0);
    int count=0;
    
    DFS(0,-1,count,adj,ans,disc,low,visited);
    
    vector<int> finalAns;
    
    for(int i = 0 ; i < ans.size() ; i++)
    {
        if(ans[i]==1) finalAns.push_back(i);
    }
    
    if(!finalAns.size()) finalAns.push_back(-1);
    
    return finalAns;
}
