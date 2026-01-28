#include<bits/stdc++.h>
using namespace std;

int main(){
  // ofstream out;
  // out.open("abc.txt");
  // out<<"twinkle twinkle little star,\nhow i wonder what u are,\nup above the world so high,\nlike a diamond in the sky";
  // out.close();

  string st,s1,s2;
  ifstream in;
  in.open("abc.txt");
  // in>>s1>>s2;
  while(in.eof()==0) {
    getline(in,st);
    cout<<st<<endl;
  }
  in.close();


  return 0;
}