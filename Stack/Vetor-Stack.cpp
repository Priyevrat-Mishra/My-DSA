#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
  vector<int>v;
  Stack(){}
  void push(int val){
    v.push_back(val);
  }

  void pop(){
    if(v.size()==0){
      cout<<"Stack is Empty"<<endl;
      return ;
    }
    v.pop_back(); 
  }

  int top(){
    if(v.size()==0){
      cout<<"Stack is Empty"<<endl;
      return -1;
    }
    return v.back();
  }

  int size(){
    return v.size();
  }
  
  void show(){
    for(int z:v)cout<<z<<" ";
    cout<<endl;
  }
};

int main(){
  Stack st;
  st.push(10);
  st.push(20); 
  st.push(30);
  st.push(40);
  st.push(50);
  st.push(60);
  // st.pop();
  cout<<st.size()<<endl<<st.top();
  st.show();
  return 0;
}
// use capital S in Stack