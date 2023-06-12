#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
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
    string *k = t.chaves();
    int num_chaves = k->length(), cont = 0, *vet = new int[num_chaves], j = 0;
    
    for(int i=0;i<num_chaves;i++){
        while(j < l.size()){
            if(k[i] == l.valor(j)){
                cont++;
                j++;
            }
            else j++;
        }
        vet[i] = cont;
        cont = 0;
        j = 0; 
    }
    return vet;
}
double *normalizacao(int *vet, int tam){
    double *n = new double[tam];
    
    for(int i=0;i<tam;i++) n[i] = (double)vet[i]/tam;
    return n;
}

double cosseno(double *v1, double *v2, int tam){
    double nume = 0, norma1 = 0, norma2 = 0;
    for(int i=0;i<tam;i++) nume += (v1[i] * v2[i]);
    for(int i=0;i<tam;i++) norma1 += pow(v1[i],2);
    for(int i=0;i<tam;i++) norma2 += pow(v2[i],2);
    norma1 = sqrt(norma1);
    norma2 = sqrt(norma2);
    return nume/(norma1 * norma2);
}

main(int argc, char **argv){
    THashing c(TAM); //criação de uma tabela de hash com 12 espaços.
    
    //-------------primeira fase------------
    //inserção da frase "água no joelho" numa lista a e inserção da frase "joelho na água" numa lista b.
    Lista a = dividir("Por favor, qual o valor da diária?");
    Lista b = dividir("Por favor, qual o valor da bebida?");
    a.imprimir();
    b.imprimir();
    
    //inserção das stop words na tabela t
    StopWord sw1("o",1),sw2("da",1);
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

    //Criação dos vetores i e j com a quantidade de recorrencia das chaves nas listas al e bl, respectivamente
    int *i = contador_palavras(al,s);
    int *j = contador_palavras(bl,s);

    //-------------terceira fase------------
    int tamanho = s.getQuantelementos();
    double *ni = normalizacao(i,tamanho);
    double *nj = normalizacao(j,tamanho);

    //-------------quarta fase--------------
    cout << cosseno(ni,nj,tamanho) << endl;
}