#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cout << "========================\n";
    cout << "Enter Your Choice----- \n\t0 for Rock\n\t1 for Paper\n\t2 for Scissor\n ";
    cout << "========================\n";

    do{
        cout << "Your Turn : ";
        cin >> a;
    } while (a < 0 || a > 2);

    srand(time(0));
    int b = rand() % 3;

    cout << "Your Choice : " << a << "\nComp Choice : " << b << endl;

    if (a == b)  cout << "It's Draw!\n";
    else{
        if (a == 0 && b == 1)  cout << "You Lost!";
        else if (a == 0 && b == 2)  cout << "You Won!";
        else if (a == 1 && b == 0)  cout << "You Won!";
        else if (a == 1 && b == 2)  cout << "You Lost!";
        else if (a == 2 && b == 0)  cout << "You Lost!";
        else if (a == 2 && b == 1)  cout << "You Won!";
        else  cout << "Error\n";
    }
    return 0;
}