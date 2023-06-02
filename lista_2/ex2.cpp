#include<iostream>
using namespace std;

void imprimir_vetor(double *v, int n){
    cout << "Imprimindo vetor em ordem:\t";
    for(int i=0;i<n;i++) cout << v[i] << "\t";
    cout << "\nImprimindo vetor na ordem contrária:\t";
    for(int i=n-1;i>=0;i--) cout << v[i] << "\t";
    cout << "\n";
}
main(){
    double x[4] = {1,2,3,4};
    imprimir_vetor(x,4);
}