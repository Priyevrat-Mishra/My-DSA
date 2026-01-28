#include<bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node *left, *right;
  node(int val){
    data = val;
    left = right = NULL;
  }
};

vector<int> morris(node* root){
  vector<int>ans;
  while(root){
    if(!root->left){
      ans.push_back(root->data);
      root = root->right;
    }
    else{
      node* curr = root->left;
      while(curr->right && curr->right != root){
        curr = curr->right;
      }
      if(!curr->right){
        curr->right = root;
        root = root->left;
      }
      else{
        ans.push_back(root->data);
        curr->right = nullptr;
        root = root->right;
      }
    }
  }
  return ans;
}

int main(){
  node* a = new node(10);
  node* b = new node(20);
  node* c = new node(30);
  node* d = new node(40);
  node* e = new node(50);
  node* f = new node(60);
  node* g = new node(70);
  node* h = new node(80);
  node* i = new node(90);
  a->left = b, a->right = c;
  b->left = d, b->right = e;
  c->left = f, c->right = g;
  d->left = h, d->right = i;

  vector<int> v = morris(a);
  for(auto i : v)cout<<i<<" ";

  return 0;
}