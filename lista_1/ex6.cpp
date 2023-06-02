#include<iostream>
#include<math.h>
using namespace std;

main(){
    int x,n;

    cout << "Informe base: ";
    cin >> x;
    cout << "Informe potência: ";
    cin >> n;

    cout << "X^n = " << pow(x,n) << endl;
}