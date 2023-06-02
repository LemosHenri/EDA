#include<iostream>
using namespace std;

int modulo(int x){
    if(x>=0) return x;
    else return -x;
}
main(){
    int x;
    cout << "Informe um valor inteiro: ";
    cin >> x; 
    
    cout << "Móduto de " << x << " : " << modulo(x) << endl;
}