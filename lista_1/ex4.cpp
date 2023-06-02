#include<iostream>
using namespace std;

main(){
    int n, cont=0;

    cout << "Informe um valor: ";
    cin >> n;

    for(int i=1;i<=n;i++) cont += i;

    cout << "A soma de 1 até " << n << " é igual a " << cont << endl;
}