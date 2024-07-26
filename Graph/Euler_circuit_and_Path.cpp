// Euler circuit and Path GFG

// An Eulerian Path is a path in graph that visits every edge exactly once. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

// Example 1:

// Input: 

// Output: 2
// Explanation: 
// Following is an eulerian circuit in the mentioned graph
// 1 -> 2 -> 0 -> 1
// Example 2:

// Input: 

// Output: 1
// Explanation: 
// Following is an eulerian path in the mentioned graph
// 1 -> 0 -> 2
// Your Task:
// You don't need to read or print anything. Your task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoted as V and an adjacency list of graph denoted as adj and returns 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, it returns 1, otherwise, it will return 0.

// Expected Time Complexity: O(V+E) where E is the number of edges in graph.
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 104
// 1 ≤ adj[i][j] ≤ V-1

void DFS(vector<int> adj[],vector<int> &visited,int node)
{
    visited[node]=1;
    
    for(int i = 0 ; i < adj[node].size() ; i++)
    {
        if(!visited[adj[node][i]])
        {
            DFS(adj,visited,adj[node][i]);
        }
    }
}

int isEulerCircuit(int V, vector<int>adj[])
{
    vector<int> visited(V,0);
    vector<int> Deg(V,0);
    int odd=0;
    
    for(int i = 0 ; i < V; i++)
    {
        Deg[i]=adj[i].size();
        if(Deg[i]%2!=0) odd++;
    }
    
    if(odd!=2 && odd!=0) return 0;
    
    for(int i = 0 ; i <V;i++)
    {
        if(Deg[i])
        {
            DFS(adj,visited,i);
            break;
        }
    }
    
    for(int k = 0 ;k < V;k++)
    {
        if(Deg[k] && !visited[k]) return 0;
    }
    
    if(!odd) return 2;
    
    return 1;
}
