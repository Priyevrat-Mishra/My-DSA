#include<bits/stdc++.h>
using namespace std;

int main(){
  // Pair------
  // pair<pair<int,int>, pair<int,int> >p;
  // p = make_pair(make_pair(22,33), make_pair(222,333));
  // cout<<p.first.first<<" "<<p.first.second<<endl;
  // cout<<p.second.first<<" "<<p.second.second;

  // List(DLL)-------
  // list<int>l;
  // l.push_back(10);
  // l.push_back(20);
  // l.push_back(30);
  // l.push_front(300);
  // l.push_front(200);
  // l.push_front(100);
  // l.push_front(3000);
  // l.pop_front();
  // l.pop_back();
  // cout<<l.size()<<endl;
  // for(auto i : l) cout << i << " ";
  // for(auto i=l.begin();i!=l.end();i++)
  //   cout<<*i<<" ";
  // for(auto i=l.rbegin();i!=l.rend();i++)
  //   cout<<*i<<" ";

  //ssts
  set<int>s;
  s.insert(2);
  s.insert(10);
  s.insert(12);
  s.insert(34);
  s.insert(99);
  s.insert(12);
  cout<<s.size()<<endl;
  // for(auto i : s) cout << i << " ";
  for(auto it = s.rbegin(); it != s.rend();it++)
    cout << *it << " ";

  // multiset<int>ms;
  // ms.insert(2);
  // ms.insert(10);
  // ms.insert(12);
  // ms.insert(34);
  // ms.insert(99);
  // ms.insert(12);
  // for(auto i : ms) cout << i << " ";

  // Map
  map<int,int>m;
  // m[13] = 456;
  // m.insert(make_pair(20,333));
  // m.insert(make_pair(26,367));
  // m.insert(make_pair(120,393));
  // m.insert(make_pair(126,670));
  // m.insert(make_pair(22,398));
  // for(auto i : m){
  //   cout<<i.first<<" -> "<<i.second<<"\n";
  // }


  return 0;
}