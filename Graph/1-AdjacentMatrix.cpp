// Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;

void showGraph(vector<vector<int>>v, int vertex) {
  for(int i=0; i<vertex; i++){
    for(int j=0; j<vertex; j++)
      cout << v[i][j] << " ";
    cout<<endl;
  }
}

int main(){
  int vertex, edges;
  cout<<"Enter vertex & edges : ";
  cin >> vertex >> edges;

  vector<vector<int>>AdjMat(vertex, vector<int>(vertex, 0));
  // cout << "Undirected Unweighted Graph\n";
  // int u, v;
  // for(int i=0; i<edges; i++){
  //   cin >> u >> v;
  //   AdjMat[u][v] = AdjMat[v][u] = 1;
  // }
  // showGraph(AdjMat, vertex);
  

  cout << "Undirected Weighted Graph\n";
  int u, v, weight;
  for(int i=0; i<edges; i++){
    cin >> u >> v >> weight;
    AdjMat[u][v] = AdjMat[v][u] = weight;
  }
  showGraph(AdjMat, vertex);

  
  return 0;
}