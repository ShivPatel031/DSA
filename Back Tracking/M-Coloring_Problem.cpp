// M-Coloring Problem GFG

// Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
// Example 1:

// Input:
// N = 4
// M = 3
// E = 5
// Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
// Output: 1
// Explanation: It is possible to colour the
// given graph using 3 colours.

// Example 2:

// Input:
// N = 3
// M = 2
// E = 3
// Edges[] = {(0,1),(1,2),(0,2)}
// Output: 0
// Your Task:
// Your task is to complete the function graphColoring() which takes the 2d-array graph[], the number of colours and the number of nodes as inputs and returns true if answer exists otherwise false. 1 is printed if the returned value is true, 0 otherwise. The printing is done by the driver's code.
// Note: In Example there are Edges not the graph.Graph will be like, if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.Function will be contain 2-D graph not the edges.

// Expected Time Complexity: O(MN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 20
// 1 ≤ E ≤ (N*(N-1))/2
// 1 ≤ M ≤ N

bool giveColor(bool graph[101][101],int m,int n,vector<int> &color,int node)
{
   
   for(int i = 0 ; i < m ; i++)
   {
       bool isPossible = 0 ;
       
       for(int j = 0 ; j<n;j++)
       {
           if(graph[node][j] && color[j]==i) 
           {
               isPossible=1;
               break;
           }
       }
       
       if(isPossible) continue;
       
       color[node]=i;
       isPossible=0;
       
       for(int j = 0 ; j<n;j++)
       {
           if(graph[node][j] && color[j]==-1) 
           {
              if(!giveColor(graph,m,n,color,j))
              {
                  isPossible=1;
                  break;
              }
           }
       }
       
       if(!isPossible) return 1;
     
        color[node]=-1;
   }
       
    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n) 
{
    vector<int> color(n,-1);
    
    for(int i = 0 ; i< n;i++)
    {
        if(color[i]==-1 && !giveColor(graph,m,n,color,i))
        {
            return 0;   
        }
    }
    
    return 1;
}
