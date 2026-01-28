#include<iostream>
using namespace std;

class MaxHeap{
  int *arr;
  int size, total_size;
public:
  MaxHeap(int n){
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
    while(idx > 0 && arr[idx] > arr[(idx-1)/2]){
      swap(arr[idx], arr[(idx-1)/2]);
      idx = (idx-1)/2;
    }
    cout<<arr[idx]<<" is inserted into heap\n";
  }

  void Heapify(int idx){
    int maxi = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;

    if(left < size && arr[maxi] < arr[left]) maxi = left;
    if(right < size && arr[maxi] < arr[right]) maxi = right;

    if(maxi != idx){
      swap(arr[maxi], arr[idx]);
      Heapify(maxi);
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
  MaxHeap h1(6);
  h1.insert(4);
  h1.insert(5);
  h1.insert(8);
  h1.insert(2);
  h1.insert(41);
  h1.insert(49);
  h1.insert(490);
  h1.print();
  h1.Delete();
  h1.print();

  return 0;
}