#include <bits/stdc++.h>
using namespace std;

int prio(char ch){ 
  return ch == '+' || ch == '-' ? 1 : 2;
}

string solve(string a, string b, char op){
  string s = "";
  s+=a;
  s+=b;
  s.push_back(op);
  return s;
}

int main(){
  string s = "(7+9)*4/8-3";
  stack<string> val;
  stack<char> op;
  for (int i = 0; i < s.length(); i++){
    if (s[i] >= 48 && s[i] <= 57)  val.push(to_string(s[i] - 48));
    else{
      if (op.empty())    op.push(s[i]);
      else if(op.top()=='(')op.push(s[i]);
      else if(s[i]=='(')op.push(s[i]);
      else if(s[i]==')'){
        while(op.top()!='('){
          char ch = op.top();
          op.pop();
          string val2 = val.top();
          val.pop();
          string val1 = val.top();
          val.pop();
          val.push(solve(val1,val2,ch));
        }
        op.pop();
      }
      else if(prio(s[i]) > prio(op.top()))op.push(s[i]);
      else{
        while(op.size()>0 && prio(s[i]) <= prio(op.top())){
          char ch = op.top();
          op.pop();
          string val2 = val.top();
          val.pop();
          string val1 = val.top();
          val.pop();
          val.push(solve(val1,val2,ch));
        }
        op.push(s[i]);
      }
    }
  }
  while(op.size() > 0){
    char ch = op.top();
    op.pop();
    string val2 = val.top();
    val.pop();
    string val1 = val.top();
    val.pop();
    val.push(solve(val1,val2,ch));
  }
  cout<<val.top();
  return 0;
}