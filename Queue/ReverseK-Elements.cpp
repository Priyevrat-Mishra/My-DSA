#include <bits/stdc++.h>
using namespace std;

void show(queue<int>&q){
  int n = q.size();
  for(int i=0;i<n;i++){
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    q.push(x);
  }
  cout<<endl;
} 

void reverseKElements(queue<int>&q,int k){
  stack<int>s;
  for(int i=0;i<k;i++){
    s.push(q.front());
    q.pop();
  }
  while(s.size()>0){
    q.push(s.top());
    s.pop();
  }
  int n = q.size();
  for(int i=0; i<n-k; i++){
    q.push(q.front());
    q.pop();
  }
}

int main(){
  queue<int>q;
  q.push(1);
  q.push(2);  
  q.push(3);  
  q.push(4);
  q.push(5);
  q.push(6);
  show(q);
  reverseKElements(q,2);
  show(q);

  return 0;
}