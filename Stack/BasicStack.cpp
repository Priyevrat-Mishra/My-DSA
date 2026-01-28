#include <bits/stdc++.h>
using namespace std;

//travsersal 
void show(stack<int>s){
  stack<int>t;
  while(s.size()>0){
    // cout<<s.top()<<" ";
    t.push(s.top());
    s.pop();
  }
  while(t.size()>0){
    cout<<t.top()<<" ";
    s.push(t.top());
    t.pop();
  }
}

int main(){
  stack<int>s,t,q;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  cout<<s.size()<<endl;

  // copy from s to t
  while(s.size()>0){
    // cout<<s.top()<<" ";
    t.push(s.top());
    s.pop();
  }
    // copy from t to q
  while(t.size()>0){
    // cout<<t.top()<<" ";
    q.push(t.top());
    t.pop();
  }
    // copy from q to s 
  while(q.size()>0){
    // cout<<q.top()<<" ";
    s.push(q.top());
    q.pop();
  }
  show(s);
  show(t);
  show(q);
  return 0;
}