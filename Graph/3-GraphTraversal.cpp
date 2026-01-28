#include <bits/stdc++.h>
using namespace std;

void bfs(int v, vector<int> adj[]){
  vector<bool> vst(v, 0);
  queue<int> q;
  q.push(0);
  vst[0] = 1;
  while (!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (int j = 0; j < adj[node].size(); j++){
      int neighbour = adj[node][j];
      if (!vst[neighbour]){
        vst[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }
}

void dfs(int v, vector<int>adj[]){
  vector<bool> vst(v, 0);
  stack<int> s;
  s.push(0);
  while(!s.empty()){
    int node = s.top();
    s.pop();

    if(!vst[node]){
      cout << node << " ";
      vst[node] = 1;
    }
    
    for(int j=adj[node].size()-1; j>=0; j--){
      int neighbour = adj[node][j];
      if (!vst[neighbour])
        s.push(neighbour);
    }
  }
}

// dfs recursive
void dfs(int node, vector<int> adj[], vector<bool>&vst){
  vst[node] = 1;
  cout << node << " ";
  for(int neighbour : adj[node])
    if(!vst[neighbour]) 
      dfs(neighbour, adj, vst);
}

// bfs recursive
void bfs(queue<int>&q, vector<int>adj[], vector<bool>&vst){
  if(q.empty()) return;
  int node = q.front();
  q.pop();
  cout << node << " ";
  for(int neighbour : adj[node])
    if(!vst[neighbour]){
      vst[neighbour] = 1;
      q.push(neighbour);
    }
  bfs(q, adj, vst);
}

int main(){
  

  return 0;
}