#include<bits/stdc++.h>
using namespace std;

//length of string
int getlength(char name[]){
    int count=0;
    for(int i=0; name[i]!='\0'; i++)    count++;
    return count;
}

//reverse of string
void strrev(char* name,int n){
    int s=0,e=n-1;
    while(s<e)    swap(name[s++],name[e--]);
}

//palindrome
bool ispalindrome(char* name,int n){
    int s=0,e=n-1;
    while(s<=e){
        if(name[s]!=name[e])    return false;
        else{
            s++;
            e--;
        }
    }
  return true;
}

int main(){
char name[20];
cout<<"enter your name:";
cin.getline(name,20);
cout<<"your name is:"<<name<<endl;
int length=getlength(name);
cout<<"length of your name is:"<<length<<endl;
strrev(name,length);
cout<<"reverse of your name is:"<<name<<endl;
cout<<"your name is palindrome:"<<ispalindrome(name,length)<<endl;

  // char str[10];
  // cin.getline(str,10);
  // string str="prem";
  // // getline(cin,str);
  // cout<< str.length();

return 0;
}