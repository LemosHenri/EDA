#include<iostream>
#include<stdlib.h>
using namespace std;

double imprimir_matriz(double **m, int nl, int nc){
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++) cout << m[i][j] << "\t";
        cout << "\n";
    }
    cout << "\n";

}

double **prod_matriz(double **m, double **n, int nl1, int nc1, int nl2, int nc2){
    double **prod;

    if(nl2 == nc1){
        prod = (double**)calloc(nl1,sizeof(double*));
        for(int i=0;i<2;i++) prod[i] = (double*)calloc(nc2,sizeof(double));
        
        for(int i=0;i<nl1;i++){
            for(int j=0;j<nc2;j++){
                for(int k=0;k<nl2;k++) prod[i][j] += m[i][k]*n[k][j];  
            }
        }

        return prod;
    }
    else cout << "Impossivel efetuar produto" << endl;
    
}
main(){
    double **m, **n, **prod;
    m = (double**)malloc(2*sizeof(double*));
    for(int i=0;i<2;i++) m[i] = (double*)malloc(2*sizeof(double));

    n = (double**)malloc(2*sizeof(double*));
    for(int i=0;i<2;i++) n[i] = (double*)malloc(2*sizeof(double));
    
    m[0][0] = 1;
    m[1][0] = 2;
    m[0][1] = 3;
    m[1][1] = 4;

    n[0][0] = 3;
    n[1][0] = 7;
    n[0][1] = 1;
    n[1][1] = 2;

    imprimir_matriz(m,2,2);
    imprimir_matriz(n,2,2);

    prod = prod_matriz(m,n,2,2,2,2);

    imprimir_matriz(prod,2,2);
}