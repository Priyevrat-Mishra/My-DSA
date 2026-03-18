#include <bits/stdc++.h>
using namespace std;
mutex mtx; // mutex for critical section

void hw(){
  cout << "hlo world  " << this_thread::get_id() << endl;
}

void printNumbers(int id){
  mtx.lock(); // Lock before entering critical section
  std::cout << "Thread " << id << " is running\n";
  mtx.unlock(); // Unlock after done
}

void printEven(int n){
  lock_guard<mutex> lock(mtx);
  cout << "even: " << n << endl; 
}

void printOdd(int n){
  lock_guard<mutex> lock(mtx);
  cout << "odd: " << n << endl;
}

int main(){
  thread t1(printEven, 2);
  thread t2(printOdd, 3);
  thread t3(printNumbers, 4);
  hw();
  t1.join();
  t2.join();
  t3.join();

  
      

  return 0;
}

