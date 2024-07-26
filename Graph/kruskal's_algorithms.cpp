// Kruskal's algorithms 

// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing pairs of integers. Each pair represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

// Example 1:

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1

// Output:
// 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.
// Example 2:

// Input:
// 2 1
// 0 1 5

// Output:
// 5
// Explanation:
// Only one Spanning Tree is possible
// which has a weight of 5.
 
// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

// Expected Time Complexity: O(ElogV).
// Expected Auxiliary Space: O(V2).
 
// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// The graph is connected and doesn't contain self-loops & multiple edges.

int findParent(int node,vector<int> &parent)
{
  if(node==parent[node]) return node;
  
  return parent[node] = findParent(parent[node],parent);
}

void UnionByRank(int u,int v,vector<int> &parent,vector<int> &rank)
{
  int pu = findParent(u,parent);
  int pv = findParent(v,parent);
  
  if(rank[pu]>rank[pv])
  {
      parent[pv]=pu;
  }
  else if(rank[pv]>rank[pu])
  {
      parent[pu]=pv;
  }
  else
  {
      parent[pv]=pu;
      rank[pu]++;
  }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V,0);
    
    for(int i = 0 ; i<V;i++) parent[i]=i;
    
    priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    
    for(int i = 0; i<V;i++)
    {
        for(int j = 0 ; j<adj[i].size();j++)
        {
            q.push({adj[i][j][1],{i,adj[i][j][0]}});
        }
    }
    
    int cost = 0 ,edges = 0;
    
    while(!q.empty())
    {
        int w = q.top().first;
        int u = q.top().second.first;
        int v = q.top().second.second;
        q.pop();
        
        if(findParent(u,parent) != findParent(v,parent))
        {
            cost+=w;
            
            UnionByRank(u,v,parent,rank);
            edges++;
        }
        
        if(edges==V-1) break;
    }
    
    return cost;
}
