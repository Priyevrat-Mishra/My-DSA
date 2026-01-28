#include<iostream>
using namespace std;

class student {
  public:
  string name;
  int rollno;
  int standard;
}; 

class boys:public student {
  public:
  void setdata(string n,int r,int s){
    this->name=n;
    this->rollno=r;
    this->standard=s;
  }
};

int main(){
  boys b1;
  b1.setdata("Rahul",1,10);
  cout<<b1.name<<endl;
  cout<<b1.rollno<<endl;
  cout<<b1.standard<<endl;

  return 0;
}