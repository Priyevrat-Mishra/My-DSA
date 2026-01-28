#include <bits/stdc++.h>
using namespace std;

int prio(char ch){ 
  return ch == '+' || ch == '-' ? 1 : 2;
}

int solve(int a, int b, char op){
  if (op == '+')  return a + b;
  else if (op == '-')  return a - b;
  else if (op == '*')  return a * b;
  else  return a / b;
}

int main(){
  string s = "(7+9)*4/8-3";
  stack<int> val;
  stack<char> op;
  for (int i = 0; i < s.length(); i++){
    if (s[i] >= 48 && s[i] <= 57)  val.push(s[i] - 48);
    else{
      if (op.empty())    op.push(s[i]);
      else if(op.top()=='(')op.push(s[i]);
      else if(s[i]=='(')op.push(s[i]);
      else if(s[i]==')'){
        while(op.top()!='('){
          char ch = op.top();
          op.pop();
          int val2 = val.top();
          val.pop();
          int val1 = val.top();
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
          int val2 = val.top();
          val.pop();
          int val1 = val.top();
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
    int val2 = val.top();
    val.pop();
    int val1 = val.top();
    val.pop();
    int ans = solve(val1,val2,ch);
    val.push(ans);
  }
  cout<<val.top();
  return 0;
}