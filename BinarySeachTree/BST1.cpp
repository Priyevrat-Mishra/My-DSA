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

void show(node* root){      //DFS
  if(!root)  return;
  show(root->left);
  cout<<root->data<<" ";
  show(root->right);
}

// TC = O(n)    SC = O(h)
node* insert(node* root, int target){
  if(!root){
    node* t = new node(target);
    return t;
  }
  if(root->data > target)
    root->left = insert(root->left,target);
  else root->right = insert(root->right,target);
  return root;
}

// TC = O(n)    SC = O(h)
node* search(node* root, int target){ 
  if(!root) return nullptr;
  if(root->data == target) return root;
  if(root->data > target) return search(root->left, target);
  else  return search(root->right, target);
}

int main(){
  vector<int>v = {3,7,4,1,2,6,8};
  node* root = nullptr;

  for(int i=0; i<v.size(); i++)
    root = insert(root,v[i]);

  show(root);

  cout<<"\n"<<search(root, 4)->data;

  return 0;
}
// for insertion and searching, if tree is one sided then SC = O(n)