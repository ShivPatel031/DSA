// Shortest Path in Weighted undirected graph GFG

// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 
// Note: The Graph doesn't contain any negative weight cycle.

// Example 1:

// Input:
// V = 2
// adj [] = {{{1, 9}}, {{0, 9}}}
// S = 0
// Output:
// 0 9
// Explanation:

// The source vertex is 0. Hence, the shortest 
// distance of node 0 is 0 and the shortest 
// distance from node 1 is 9.

// Example 2:

// Input:
// V = 3, E = 3
// adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
// S = 2
// Output:
// 4 3 0
// Explanation:

// For nodes 2 to 0, we can follow the path-
// 2-1-0. This has a distance of 1+3 = 4,
// whereas the path 2-0 has a distance of 6. So,
// the Shortest path from 2 to 0 is 4.
// The shortest distance from 0 to 1 is 1 .
 
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

// Expected Time Complexity: O(V2).
// Expected Auxiliary Space: O(V2).

// Constraints:
// 1 ≤ V ≤ 1000
// 0 ≤ adj[i][j] ≤ 1000
// 1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
// 0 ≤ S < V

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
{
    vector<bool> visited(n,0);
    vector<int> path(n,INT_MAX);
    vector<pair<int,int>> adj[n];
    vector<int> parent(n,-1);
    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> q;
    
    for(int i = 0 ; i < m ; i++ )
    {
        int u = edges[i][0]-1;
        int v = edges[i][1]-1;
        int w = edges[i][2];
        
        if(u!=v)
        {
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }
    
    q.push({0,0});
    path[0]=0;
    
    while(!q.empty())
    {
        int node = q.top().second;
        q.pop();
        
        if(!visited[node])
        {
            visited[node]=1;
            
            for(int i = 0 ; i < adj[node].size() ; i++ )
            {
                int neighbour = adj[node][i].first;
                int weight =  adj[node][i].second;
                
                if(!visited[neighbour] && path[neighbour]>path[node]+weight)
                {
                    path[neighbour]=path[node]+weight;
                    parent[neighbour]=node;
                    q.push({path[neighbour],neighbour});
                }
            }
        }
    }
    
    vector<int> ans;
    
    if(path[n-1]!=INT_MAX)
    {
    
        int dest=n-1;
        
        while(dest!=-1)
        {
           ans.push_back(dest+1);
           dest=parent[dest];
        }
        ans.push_back(path[n-1]);
        
        reverse(ans.begin(),ans.end());
    }
    else
    {
        ans.push_back(-1);
    }
    
    return  ans;
}
