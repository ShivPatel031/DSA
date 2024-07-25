// Shortest path in Undirected Graph GFG

// You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

// Example1:

// Input:
// n = 9, m= 10
// edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
// src=0
// Output:
// 0 1 2 1 2 3 3 4 4
// Explanation:

// Example2:

// Input:
// n = 4, m= 4
// edges=[[0,0],[1,1],[1,3],[3,0]] 
// src=3
// Output:
// 1 1 -1 0
// Explanation:
// Your Task:
// You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array of edges representing the edges of an undirected graph with unit weight, an integer n as the number of nodes, an integer m as a number of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance from src to all nodes.

// Constraint:
// 1<=n,m<=10000
// 0<=edges[i][j]<=n-1

// Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
// Expected Space Complexity: O(N)

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
{
    vector<int> adj[N];
    vector<bool> visited(N,0);
    vector<int> path(N,-1);
    queue<int> q;
    
    for(int i = 0 ; i < M ; i++)
    {
        if(edges[i][0]!=edges[i][1])    
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]); //because this is undirected graph must remember
        }
    }
    
    q.push(src);
    visited[src]=1;
    path[src]=0;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop(); 
        
        for(int  i = 0 ; i < adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                visited[adj[node][i]]=1;
                path[adj[node][i]]=path[node]+1;
                q.push(adj[node][i]);
            }
        }
    }
    
    return path;
    
}
