#include <bits/stdc++.h>
using namespace std;

// T.C. = O(n) && S.C. = O(levels + 1) ~ O(height + 2) ~ O(h)
class node{
public:
  int data;
  node *left;
  node *right;
  node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

int levels(node *root){
  if (!root)   return 0;
  return 1 + max(levels(root->left), levels(root->right));
}

void nthLevel(node *root, int curr, int level){
  if (root == NULL)  return;
  if (curr == level){
    cout << root->data << " ";
    return;
  }
  nthLevel(root->left, curr + 1, level);
  nthLevel(root->right, curr + 1, level);
}

void levelOrder(node *root){
  int n = levels(root);
  for (int i = 1; i <= n; i++){
    nthLevel(root, 1, i);
    cout << endl;
  }
}

// In lvlOrderQueue, swap left right for reverse traversal
void lvlOrderQueue(node *root){ // BFS ->VIQ
  queue<node *> q;
  q.push(root);
  while (q.size() > 0){
    node *temp = q.front();
    q.pop();
    cout << temp->data << " ";
    if (temp->left)  q.push(temp->left);  
    if (temp->right)  q.push(temp->right);
  }
  cout << endl;
}

vector<int> spiralOrder(node* root){
  vector<int>ans;
  stack<node*>s1,s2;       //s1: R TO L  //s2: L TO R
  s1.push(root);
  while(!s1.empty() || !s2.empty()){
    if(!s1.empty()){
      while(!s1.empty()){
        node* t = s1.top();
        s1.pop();
        ans.push_back(t->data);
        if(t->right) s2.push(t->right);
        if(t->left) s2.push(t->left);
      }
    }
    else{ 
      while(!s2.empty()){
        node* t = s2.top();
        s2.pop();
        ans.push_back(t->data);
        if(t->left) s1.push(t->left);
        if(t->right) s1.push(t->right);
      }
    }
  }
  return ans;
}

int main(){
  node *a = new node(1);
  node *b = new node(2);
  node *c = new node(3);
  node *d = new node(4);
  node *e = new node(5);
  node *f = new node(6);
  node *g = new node(7);
  a->left = b, a->right = c;
  b->left = d, b->right = e;
  c->left = f, c->right = g;

  cout<<levels(a)<<endl;
  levelOrder(a);
  // nthLevel(a,1,2);
  // lvlOrderQueue(a);
  
  vector<int>v = spiralOrder(a);
  // for(int i : v)cout<<i <<" ";
  
  return 0;
}