#include <bits/stdc++.h>
using namespace std;

void cumulativeSum(int arr[], int size, int index){
    // Base case: if index is 0, simply return (first element remains unchanged)
    if (index == 0)    return;
    // Recursive case: process the previous elements first
    cumulativeSum(arr, size, index - 1);
    // Update the current element by adding the previous element
    arr[index] += arr[index - 1];
}

int main(){
    // int arr[] = {1, 2, 3, 4, 5};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int result[size];  // Array to store the cumulative sum

    // cumulativeSum(arr, size, size-1);

    // cout << "Cumulative sum array: ";
    // for (int i = 0; i < size; i++)  cout << arr[i] << " ";
    // cout << endl;

    array<int, 5> a = {1, 12, 3, 4, 5}; 
    // for (int i = 0; i < 5; i++)  cout << a[i] << " ";
    // sort(a.begin(), a.end());
    // for (int i = 0; i < 5; i++)  cout << a[i] << " ";
    // cout << "\n element at index 2:" << a.at(2) << endl;
    // cout << "first element:" << a.front() << endl
    //      << "last element:" << a.back() << endl;
    cout << a.empty();

    /*      set<int> s;     //set
          s.insert(5);
          s.insert(4);
          s.insert(5);
          s.insert(6);
          s.insert(7);
          s.insert(9);
          for(auto i:s)
              cout<<i<<endl;

       map<int, string>m;  //map
       m[1]="start";
       m[2]="mid";
       m[3]="end";
       m.insert({5,"bheem"});
       for(auto i:m)
           cout<<i.first; */

    // vector<int> v;   //algorithm
    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(6);
    // v.push_back(7);
    // cout<<binary_search(v.begin(),v.end(),6);
    // cout<<lower_bound(v.begin(),v.end(),6)-v.begin();
    // cout<<upper_bound(v.begin(),v.end(),6)-v.begin();

    return 0;
}