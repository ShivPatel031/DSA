// Strongly Connected Components (Kosaraju's Algo) GFG

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 
// Example 1:

// Input:

// Output:
// 3
// Explanation:

// We can clearly see that there are 3 Strongly
// Connected Components in the Graph

// Example 2:

// Input:

// Output:
// 1
// Explanation:
// All of the nodes are connected to each other.
// So, there's only one SCC.
 
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph of size V as inputs and returns an integer denoting the number of strongly connected components in the given graph.

// Expected Time Complexity: O(V+E).
// Expected Auxiliary Space: O(V+E).
 
// Constraints:
// 1 ≤ V ≤ 5000
// 0 ≤ E ≤ (V*(V-1))
// 0 ≤ u, v ≤ V-1
// Sum of E over all testcases will not exceed 25*106


void topologicalSort(vector<vector<int>> &adj,stack<int> &s,vector<bool> &visited,int node)
{
  visited[node]=1;
  
  for(int i = 0 ; i<adj[node].size() ; i++)
  {
      if(!visited[adj[node][i]])
      {
          topologicalSort(adj,s,visited,adj[node][i]);
      }
  }
  
  s.push(node);
}

void DFS(vector<int> adj[],vector<bool> &visited,int node)
{
  visited[node]=1;
  
  for(int i = 0 ; i<adj[node].size() ; i++)
  {
      if(!visited[adj[node][i]])
      {
          DFS(adj,visited,adj[node][i]);
      }
  }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    vector<int> adj2[V];
    vector<bool> visited(V,0);
    stack<int> s;
    int count=0;
    
    for(int i = 0 ; i<V ;i++)
    {
        for(int j = 0 ; j<adj[i].size();j++)
        {
            adj2[adj[i][j]].push_back(i);
        }
    }
    
    for(int i = 0 ; i < V ; i++)
    {
        if(!visited[i]) topologicalSort(adj,s,visited,i);
    }

    for(int i = 0 ; i < V ; i++)
    {
        visited[i]=0;
    }
    
    while(!s.empty())
    {
        if(!visited[s.top()])
        {   
            count++;
            DFS(adj2,visited,s.top());
        }
        s.pop();
    }
    
    return count;
}
