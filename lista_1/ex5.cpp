#include<iostream>
using namespace std;

main(){
    int n, i=1, cont=0;

    cout << "Informe o número de termos da soma: ";
    cin >> n;

    for(int j=1; j <= n;j++){
        cont += i*j;
        i *= -1;
    }

    cout << "A soma de " << n << " termos é igual a " << cont << endl;

}