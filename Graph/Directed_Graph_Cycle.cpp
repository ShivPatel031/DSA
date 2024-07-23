// Directed Graph Cycle GFG

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
// In the adjacency list adj, element adj[i][j] represents an edge from i to j.

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

// using BFS by khan's algo
bool isCyclic(int V, vector<int> adj[]) 
{
    vector<int> InDeg(V,0);
    vector<int> ans;
    queue<int> q;
    
    for(int i = 0 ; i < V;i++)
    {
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            InDeg[adj[i][j]]++;
        }
    }
    
    for(int i = 0 ; i  < V ; i++)
    {
        if(InDeg[i]==0) q.push(i);
    }
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        ans.push_back(node);
        
        for(int i = 0 ; i < adj[node].size() ; i++)
        {
            InDeg[adj[node][i]]--;
            
            if(!InDeg[adj[node][i]]) q.push(adj[node][i]);
        }
    }
    
    int count = ans.size();
    
    return count!=V; 
}

// using DFS
bool DFS(vector<int> adj[],vector<bool> &path,vector<bool> &visited,int node)
{
    path[node]=1;
    visited[node]=1;
    
    for(int i = 0 ; i<adj[node].size();i++)
    {
        if(!path[adj[node][i]])
        {
            if(!visited[adj[node][i]])
            {
                if(DFS(adj,path,visited,adj[node][i])) return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    
    path[node]=0;
    
    return 0;
}

bool isCyclic(int V, vector<int> adj[]) 
{
  vector<bool> path(V,0);
  vector<bool> visited(V,0);
  
  for(int i = 0 ; i < V ; i++)
  {
      if(!visited[i] && DFS(adj,path,visited,i))
      {
          return 1;
      }
  }
  return 0; 
}
