// Hamiltonian Path GFG

// A Hamiltonian path, is a path in an undirected graph that visits each vertex exactly once. Given an undirected graph, the task is to check if a Hamiltonian path is present in it or not.
// Example 1:

// Input:
// N = 4, M = 4
// Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
// Output:
// 1 
// Explanation: 
// There is a hamiltonian path: 
// 1 -> 2 -> 3 -> 4 

// Example 2:

// Input:
// N = 4, M = 3 
// Edges[][] = { {1,2}, {2,3}, {2,4} } 
// Output: 
// 0 
// Explanation: 
// It can be proved that there is no 
// hamiltonian path in the given graph
// Your task:
// You don't need to read input or print anything. Your task is to complete the function check() which takes the N (the number of vertices), M (Number of edges) and the list of Edges[][] (where Edges[i] denotes the undirected Edge between vertices Edge[i][0] and Edges[i][1] ) as input parameter and returns true (boolean value) if the graph contains Hamiltonian path,otherwise returns false. 

// Expected Time Complexity: O(N!).
// Expected Auxiliary Space: O(N+M).

// Constraints:
// 1 ≤ N ≤ 10
// 1 ≤ M ≤ 15
// Size of Edges[i] is 2
// 1 ≤ Edges[i][0],Edges[i][1] ≤ N

bool DFS(vector<int> adj[],vector<bool> &visited,int node,int &count)
{
    visited[node]=1;
    count++;
    
    if(count==visited.size()) return 1;
    
    for(int i = 0 ;i< adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            if(DFS(adj,visited,adj[node][i],count)) return 1;
        }
    }
    
    visited[node]=0;
    count--;
    return 0;
}

bool check(int N,int M,vector<vector<int>> Edges)
{
    bool ans=0;
    vector<int> adj[N];
    
    for(int i = 0;i<M;i++)
    {
        int u = Edges[i][0]-1;
        int v = Edges[i][1]-1;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 0 ; i < N ;i++)
    {
        vector<bool> visited(N,0);
        int count=0;
        
        ans = DFS(adj,visited,i,count);
        
        if(ans) break;
    }
    
    return ans;
}
