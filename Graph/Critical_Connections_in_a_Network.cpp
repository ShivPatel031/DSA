// Critical Connections in a Network leetcode 1192 GFG

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

// Example 1:

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]] 

// Constraints:

// 2 <= n <= 105
// n - 1 <= connections.length <= 105
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.

void DFS(int node,int parent,int &count,vector<int> adj[], vector<vector<int>> &bridges,vector<bool> &visited,vector<int> &disc,vector<int> &low)
{
    disc[node]=low[node]=count;
    visited[node]=1;
    int neig;

    for(int i = 0 ; i<adj[node].size() ;i++)
    {
        neig=adj[node][i];

        if(neig==parent) continue;

        else if(visited[neig])  low[node] = min(low[node],low[neig]);

        else
        {
            count++;
            DFS(neig,node,count,adj,bridges,visited,disc,low);

            if(low[neig]>disc[node])
            {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(neig);
                bridges.push_back(temp);
            }

            low[node] = min(low[node],low[neig]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
{
    vector<int> adj[n];

    for(int i = 0 ; i < connections.size() ; i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    vector<vector<int>> bridges;
    vector<bool> visited(n,0);
    vector<int> disc(n);
    vector<int> low(n);
    int count=0; 

    DFS(0,-1,count,adj,bridges,visited,disc,low);  

    return bridges;
}
