// Minimum Spanning Tree GFG

// prim's algorithoms

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

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> visited(V,0);
    vector<pair<int,int>> grid;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    
    q.push({0,0});
    int sum=0;
    
    while(!q.empty())
    {
        int node = q.top().second;
        int weight = q.top().first;
        q.pop();
        
        if(!visited[node])
        {
            sum+=weight;
            visited[node]=1;
            
            for(int i = 0 ; i < adj[node].size();i++)
            {
                if(!visited[adj[node][i][0]])
                {
                    q.push({adj[node][i][1],adj[node][i][0]});
                }
            }
        }
    }
    
    return sum;
}