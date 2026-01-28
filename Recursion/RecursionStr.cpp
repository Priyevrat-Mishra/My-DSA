#include<iostream>
using namespace std;

//string reverse 
void strrev(string &str,int i,int j){
  cout<<"string: "<<str<<endl;
  if(i>j)
    return ;

  swap(str[i++],str[j--]);
  strrev(str,i,j);
}

//palindrome
bool pal(string &str,int i,int j){
  if(i>j)
    return true;

  if(str[i] != str[j]){
    return false;
  }
  else{
    return pal(str,i+1,j+1);
  }
}

int main(){
  string name="abcdef";
  strrev(name,0,name.length()-1);
  cout<<"Reverse:"<<name;
  if(pal(name,0,name.length()-1))
    cout<<"your name is palindrome"<<endl;
  else
    cout<<"your name isn't palindrome"<<endl;
  
  return 0;
}