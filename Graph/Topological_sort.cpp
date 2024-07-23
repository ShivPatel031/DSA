// Topological sort GFG

// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

// In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.

// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ (N*(N-1))/2

// using BFS khan's algorithm
vector<int> topoSort(int V, vector<int> adj[]) 
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
    
    return ans;
}

// using DFS
void DFS(vector<int> adj[],vector<bool> &check,stack<int> &tempans,int node)
{
  check[node]=1;
  
  for(int i = 0 ; i < adj[node].size();i++)
  {
      if(!check[adj[node][i]])
      {
          DFS(adj,check,tempans,adj[node][i]);
      }
  }
  
  tempans.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
  vector<bool> check(V,0);
  stack<int> tempans;
  
  for(int i = 0 ; i < V;i++)
  {
      if(!check[i])
      {
          DFS(adj,check,tempans,i);
      }
  }
  
  vector<int> ans;
  
  while(!tempans.empty())
  {
      ans.push_back(tempans.top());
      tempans.pop();
  }
  
  return ans;
}
