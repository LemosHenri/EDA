#include<string>
#include<iostream>
using namespace std;

#include "estrutura.h"

//---------------------------------------------------------------------------------------

    No::No(string n){
        this->valor = n;
        this->prox = NULL;
    }
    string No::getValor(){ return valor;}
    void No::setValor(string n){ valor = n;}
    No *No::getProx(){ return prox;}
    void No::setProx(No* p){    prox = p;}

//----------------------------------------------------------------------------------------

    Lista::Lista(){
        inicio = NULL;
    }
    Lista::Lista(string n){
        inicio = new No(n);
    }
    Lista::~Lista(){
        delete inicio;
    }
    void Lista::imprimir(){
        No *aux = inicio;
        if(aux == NULL) cout << "Lista vazia!" << endl;
        else{
            while(aux){
                cout << aux->getValor() << "\t";
                aux = aux->getProx();
            }
            cout << endl;
        }
    }
    void Lista::inserir(int pos, string n){
        No *aux = inicio;

        if(pos < this->size()){
            No *novo_no = new No(n);
            for(int i=0;i<pos-1;i++) aux = aux->getProx();
            novo_no->setProx(aux->getProx());
            aux->setProx(novo_no);
        } 
        if(pos == 0){
            No *novo_no = new No(n);
            novo_no->setProx(inicio);
            inicio = novo_no;
        }
        else cout << "Posição maior que o tamanho" << endl;
        
    }
    void Lista::inserir(string n){
        No *novo_no = new No(n);
        No *aux = inicio;
        while(aux->getProx()) aux = aux->getProx();
        aux->setProx(novo_no);
    }
    void Lista::remover(int pos){
        No *aux = inicio;
        No *r;
        for(int i=0;i<pos-1;i++) aux = aux->getProx();
        r = aux->getProx();
        aux->setProx(r->getProx());
        delete r;
    }
    int Lista::size(){
        No *aux = inicio;
        int cont = 0;

        if(aux == NULL){
             cout << "Lista vazia!" << endl;
             return 0;
        }
        else{
            while(aux){
                cont++;
                aux = aux->getProx();
            }
            return cont;
        }
    }
