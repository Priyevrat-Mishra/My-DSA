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
  cout<<endl;
}

void pushDown(stack<int>&s,int val){
  stack<int>t;
  while(s.size()>0){
    t.push(s.top());
    s.pop();
  }
  s.push(val);
  while(t.size()>0){
    s.push(t.top());
    t.pop();
  }
}

void pushIdx(stack<int>&s,int val,int idx){
  stack<int>t;
  while(s.size()>idx){
    t.push(s.top());
    s.pop();
  }
  s.push(val);
  while(t.size()>0){
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
  show(s);
  pushDown(s,70);
  pushIdx(s,100,0);
  show(s);
  return 0;
}