#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string getPassword(int len){
  string Password = "";
  string characters = "aquickbrownfoxjumpsoverthelazydogAQUICKBROWNFOXJUMPSOVERTHELAZYDOG0123456789";
  srand(time(0));
  int randIdx;
  for (int i = 0; i < len; i++){
    randIdx = rand() % characters.size();
    Password += characters[randIdx];
  }
  return Password;
}

int main(){
  int len = 0;
  cout << "Enter Password's length :: ";
  cin >> len;
  cout << "Your Generated Password :: " << getPassword(len);;
  return 0;
}