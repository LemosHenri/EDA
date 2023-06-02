#include<iostream>
using namespace std;
int fibo(int n){
    if((n==1) || (n==2)) return 1;
    else return fibo(n-1) + fibo(n-2);
}

main(){
    int n;

    cout << "Informe número de termos maior que 2: ";
    cin >> n;

    if(n<=2) cout << "É necessário o valor ser maior que 2" << endl;
    else cout << "Fibonacci: " << fibo(n) << endl;
    
}