#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)    return a;
    return gcd(b, a % b);
}

int main() {
    int a, b, lcm;
    cout<<"Enter two numbers:";
    cin >> a >> b;
    cout <<"HCF is: " << gcd(a, b) << endl;
    lcm = (a*b)/gcd(a,b);
    cout << "LCM is: "<< lcm << endl;
    return 0;
}