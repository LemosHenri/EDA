#include<iostream>
#include<stdlib.h>
using namespace std;

bool verifica_linha(double **m, int nl, int nc){
    double pivo;
    for(int i=0;i<nl;i++){
        for(int j=1;j<nc;j++){
            pivo = m[i][j];
            for(int k=0;k<nc;k++)  if((k!=j) && (pivo != m[i][k])) pivo = m[i][k];
            if(pivo == m[i][j]) return true;
        }
    }
    return false;
}

main(){
    double **m;
    int nl, nc;
    bool linha;

    nl = 2;
    nc = 2;

    m = (double**)malloc(nl*sizeof(double*));
    for(int i=0;i<nl;i++) m[i] = (double*)malloc(nc*sizeof(double));

    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 9;
    m[1][1] = 9;

    linha = verifica_linha(m,nl,nc);
    if(linha) cout << "Esta matriz possui uma linha com o mesmo elemento" << endl;
    else cout << "Esta matriz não possui uma linha com o mesmo elemento" << endl;
}