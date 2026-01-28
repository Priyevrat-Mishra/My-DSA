#include<bits/stdc++.h>
using namespace std;

// Topologic Sort (BFS) : Kahn's Algo
void topoSort(int v, vector<int> adj[]){
  queue<int> q;
  vector<int> inDeg(v, 0);
  for(int i=0; i<v; i++)
    for(int j=0; j<adj[i].size(); j++)
      inDeg[adj[i][j]]++;

  for(int i=0; i<v; i++) 
    if(!inDeg[i])  q.push(i);

  while(!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";
    
    for(int neighbour : adj[node]){
      inDeg[neighbour]--;

      if(inDeg[neighbour] == 0)
        q.push(neighbour);
    }
  }
}

int main(){
  int vertex, edges;
  cout << "Enter vertex & edges : ";
  cin >> vertex >> edges;

  vector<int> AdjList[vertex];
  // Directed unweighted graph
  int u, v;
  for (int i = 0; i < edges; i++){
    cin >> u >> v;
    AdjList[u].push_back(v);
  }
  cout<<"Topologic Sort : ";
  topoSort(vertex, AdjList);
  return 0;
}