#include<iostream>
#include<stdlib.h>
using namespace std;

double *enfileirar(double **m, int nl, int nc){
    double *v = (double*)malloc((nl*nc)*sizeof(double));
    int k=0;
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            v[k] = m[i][j];
            k++;
        }
    }
    return v;
}

main(){
    double **m, *v;
    int nl, nc;

    nl = 2;
    nc = 2;

    m = (double**)malloc(nl*sizeof(double*));
    for(int i=0;i<nl;i++) m[i] = (double*)malloc(nc*sizeof(double));

    m[0][0] = 1;
    m[0][1] = 0;
    m[1][0] = 9;
    m[1][1] = 5;

    v = enfileirar(m,nl,nc);

    for(int i=0;i<nl*nc;i++) cout << v[i] << "\t";
    cout << "\n";
}
