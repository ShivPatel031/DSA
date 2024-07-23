// Undirected Graph Cycle GFG

// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// Example 1:

// Input:  
// V = 5, E = 5
// adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
// Output: 1
// Explanation: 
// 1->2->3->4->1 is a cycle.

// Example 2:

// Input: 
// V = 4, E = 2
// adj = {{}, {2}, {1, 3}, {2}}
// Output: 0
// Explanation: 
// No cycle in the graph.
 
// Your Task:
// You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

// NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

// using BFS
bool cycle(vector<int> adj[],vector<bool> &check,int node)
{
    queue<pair<int,int> > q;
    
    q.push(make_pair(node,-1));
    
    while(!q.empty())
    {
        pair<int,int> node = q.front();
        q.pop();
        
        if(!check[node.first]) check[node.first]=1;
        
        for(int i = 0 ; i<adj[node.first].size();i++)
        {
            if(!check[adj[node.first][i]])
            {
                q.push(make_pair(adj[node.first][i],node.first));
            }
            else
            {
                if(adj[node.first][i] != node.second) return 1;
            }
        }
        
    }
    
    return 0;
}

bool isCycle(int V, vector<int> adj[]) 
{
    vector<bool> check(V,0);

    for(int i = 0 ; i<check.size() ; i++)
    {
        if(!check[i] && cycle(adj,check,i))
        {
            return 1;
        }
    }
    
    return 0;
}

// using DFS
bool cycle(vector<int> adj[],vector<bool> &check,int node,int parent)
{
    check[node]=1;
    
    for(int i = 0 ; i < adj[node].size();i++)
    {
        if(!check[adj[node][i]])
        {
            if(cycle(adj,check,adj[node][i],node)) return 1;
        }
        else
        {
            if(adj[node][i] != parent) return 1;
        }
    }
    
    return 0;
}

bool isCycle(int V, vector<int> adj[]) 
{
    vector<bool> check(V,0);
    
    bool ans = cycle(adj,check,0,-1);
    
    if(!ans)
    {
        for(int i = 0 ; i<check.size() ; i++)
        {
            if(!check[i])
            {
                ans = cycle(adj,check,i,-1);
                
                if(ans) return 1;
            }
        }
    }
    
    return ans;
}
