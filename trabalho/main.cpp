#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

#include "thashing.h"
#include "lista.h"

#define TAM 12

Lista dividir(string str){
    Lista l;
    int ini = 0, fim = 0;
    while(fim <= str.length()){
        if(str[fim] == ' ' || str[fim] == '\0'){
            l.inserir(str.substr(ini,fim-ini));
            ini = fim + 1;
            fim++;
        }
        fim++;
    }
    return l;
}

Lista remover_stopword(Lista &l, THashing &t){
    Lista aux;
    for(int i=0;i<l.size();i++){
        if(!t.isChave(l.valor(i))) aux.inserir(l.valor(i));
    }
    return aux;
}

THashing mais_relevantes(Lista &l1, Lista &l2){
    THashing t(TAM);
    for(int i=0;i<l1.size();i++){
        StopWord sw(l1.valor(i),1);
        t.inserir(sw); 
    }
    for(int i=0;i<l2.size();i++){
        StopWord sw(l2.valor(i),1);
        t.inserir(sw); 
    }
    return t;
}

int *contador_palavras(Lista &l, THashing &t){
    
}

main(int argc, char **argv){
    THashing c(TAM); //criação de uma tabela de hash com 12 espaços.
    
    //-------------primeira fase------------
    //inserção da frase "água no joelho" numa lista a e inserção da frase "joelho na água" numa lista b.
    Lista a = dividir("água no joelho");
    Lista b = dividir("joelho na água");
    a.imprimir();
    b.imprimir();
    
    //inserção das stop words na tabela t
    StopWord sw1("na",1),sw2("no",1);
    c.inserir(sw1);
    c.inserir(sw2);
    c.imprimir();
    
    //Criação de novas listas sem as stopwords
    Lista al = remover_stopword(a,c);
    Lista bl = remover_stopword(b,c);
    al.imprimir();
    bl.imprimir();

    //-------------segunda fase------------
    //Criação de uma tabela s com as palavras mais relevantes:  s = al U bl
    THashing s = mais_relevantes(al,bl);
    s.imprimir();



}