// Bipartite Graph GFG

// Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
// Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

// using DFS
bool DFS(vector<int> adj[],vector<int> &color,int node,int rb)
{
    if(color[node]==-1) color[node]=rb;
    
    for(int i = 0 ; i < adj[node].size() ; i++)
    {
        if(color[adj[node][i]]==-1)
        {
            color[adj[node][i]]=!rb;
            if(!DFS(adj,color,adj[node][i],!rb)) return 0;
        }
        else if(color[adj[node][i]]==rb)
        {
            return 0;
        }
    }
    
    return 1;
}
  
bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V,-1);
    
    for(int i = 0 ; i < V ; i++)
    {
        if(color[i]==-1 && !DFS(adj,color,i,0))
        {
              return 0;
        }
    }
    
    return 1;
}


// using BFS
bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V,-1);
    queue<int> q;
    
    
    for(int i = 0 ; i < V ; i++)
    {
    
        if(color[i]==-1)
        {
              q.push(i);
              color[i]=0;
              
              while(!q.empty())
              {
                  int node=q.front();
                  q.pop();
                  
                  for(int i = 0 ; i< adj[node].size();i++)
                  {
                      if(color[adj[node][i]]==-1)
                      {
                          color[adj[node][i]]=!color[node];
                          q.push(adj[node][i]);
                      }
                      else if(color[adj[node][i]]==color[node])
                      {
                          return 0;
                      }
                  }
              }
        }
    }
    
    return 1;
}
