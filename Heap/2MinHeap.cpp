#include<iostream>
using namespace std;

class MinHeap{
  int *arr;
  int size, total_size;
public:
  MinHeap(int n){
    arr = new int[n];
    size = 0;
    total_size = n;
  }

  void print(){
    for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
  }

  void insert(int val){
    if(size == total_size){
      cout<<"Heap OverFlow\n";
      return;
    }
    arr[size] = val;
    int idx = size;
    size++;
    //Compare val with parents
    while(idx > 0 && arr[idx] < arr[(idx-1)/2]){
      swap(arr[idx], arr[(idx-1)/2]);
      idx = (idx-1)/2;
    }
    cout<<arr[idx]<<" is inserted into heap\n";
  }

  void Heapify(int idx){
    int mini = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;

    if(left < size && arr[mini] > arr[left]) mini = left;
    if(right < size && arr[mini] > arr[right]) mini = right;

    if(mini != idx){
      swap(arr[mini], arr[idx]);
      Heapify(mini);
    }
  }

  void Delete(){
    if(size == 0){
      cout<<"Heap UnderFlow\n";
      return;
    }
    cout<<arr[0]<<" is deleted from heap\n";
    arr[0] = arr[size-1];
    size--;

    if(size == 0) return;
    Heapify(0);
  }
};

int main(){
  MinHeap h1(6);
  h1.insert(4);
  h1.insert(5);
  h1.insert(8);
  h1.insert(2);
  h1.insert(41);
  h1.insert(49);
  // h1.insert(490);
  h1.print();
  h1.Delete();
  h1.print();

  return 0;
}