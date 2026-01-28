#include <bits/stdc++.h>
using namespace std;

int main() {
  int vertex, edges;
  cout << "Enter vertex & edges : ";
  cin >> vertex >> edges;

  cout << "Undirected Weighted Graph\n";
  vector<pair<int, int>> AdjList[vertex];
  cout << "Enter elements u, v & weight : ";

  int u, v, weight;
  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> weight;
    AdjList[u].push_back(make_pair(v, weight));
    AdjList[v].push_back(make_pair(u, weight));
  }

  cout << "Printing graph-----\n";
  
  for (int i = 0; i < vertex; i++) {
    cout << i << " -> ";
    for (auto it : AdjList[i])
      cout << "(" << it.first <<", "<< it.second <<") ";
    cout << endl;
  }


  // cout << "Undirected Unweighted Graph\n";
  // vector<int> AdjList[vertex];
  // cout << "Enter elements u, v : ";
  // int u, v;
  // for (int i = 0; i < edges; i++) {
  //   cin >> u >> v;
  //   AdjList[u].push_back(v);
  //   AdjList[v].push_back(u); 
  // }

  // cout << "Printing graph-----\n";

  // for (int i = 0; i < vertex; i++) {
  //   cout << i << " -> ";
  //   for (int j = 0; j < AdjList[i].size(); j++)
  //     cout << AdjList[i][j] << " ";
  //   cout << endl; 
  // }

  return 0;
}