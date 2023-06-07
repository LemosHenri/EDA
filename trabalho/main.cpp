#include<iostream>
#include<stdlib.h>
using namespace std;

#include "estrutura.h"

main(){
    Lista l("oi");
    l.inserir("tudo");
    l.inserir("bom");
    l.inserir("com");
    l.inserir("você?");
    
    l.imprimir();
    cout << l.size() << endl;

    l.remover(1);
    l.imprimir();
    cout << l.size() << endl;

    l.inserir(0,"Uau");
    l.imprimir();
    cout << l.size() << endl;
}