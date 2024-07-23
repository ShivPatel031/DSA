#include<iostream>
using namespace std;

int main()
{
  // unweighted undirected graph
  int vertex,edges;

  cin>>vertex>>edges;

  vector<int> adjList[vertex];

  int u,v;

  for(int i = 0 ; i < edges ; i++)
  {
      cin>>u>>v;
      adjList[u].push_back(v);
    // for directed remove reverse connection
      adjList[v].push_back(u);
  }

  // unweighted directed graph
  int vertex,edges;

  cin>>vertex>>edges;

  vector<pair<int,int> > adjList[vertex];

  int u,v,weight;

  for(int i = 0 ; i < edges ; i++)
  {
      cin>>u>>v;
      adjList[u].push_back(make_pair(v,weight));
    // for directed remove reverse connection
      adjList[v].push_back(make_pair(u,weight));
  }
}
