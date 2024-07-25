// source to  destination shortest path

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src,int dest)
{
    vector<int> adj[N];
    vector<bool> visited(N,0);
    vector<int> path(N,-1);
    vector<int> parent(N,-1);
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
                parent[adj[node][i]]=node;
            }
        }
    }

    vector<int> std;

    while(dest!=1)
    {
      std.push_back(dest);
      dest=parent[dest];
    }

    reverse(std.begin(),std.end());
    
    return std;
    
}
