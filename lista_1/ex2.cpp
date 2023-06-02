#include<iostream>
using namespace std;

main(){
    double x;

    cout << "Informe um número";
    cin >> x;

    if(x>=0){
        cout << "O número " << x << " é positivo." << endl;
    } else {
        cout << "O número " << x << " é negativo." << endl;
    }
}