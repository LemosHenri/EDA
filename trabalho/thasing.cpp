#include<iostream>
#include<string>
using namespace std;

#include "thashing.h"

StopWord::StopWord(){
        chave = "";
        quantidade = 0;
    }
    StopWord::StopWord(string c, int q){
        chave = c;
        quantidade = q;
    }
    string StopWord::getChave(){
        return chave;
    }
    int StopWord::getQuantidade(){
        return quantidade;
    }
    void StopWord::incrementaQuantidade(){
        quantidade++;
    }

//----------------------------------------------------------------------------------------

    THashing::THashing(int tam){
        tamanho = tam;
        quant_elementos = 0;
        tabela = new StopWord[tam];
    }
    THashing::~THashing(){
        delete [] tabela;
    }
    int THashing::hash(StopWord sw){
        int cont=0;
        for(int i=0;i<sw.getChave().length();i++) cont += int(sw.getChave()[i]);
        return cont % tamanho;
    }
    int THashing::getQuantelementos(){
        return quant_elementos;
    }
    bool THashing::inserir(StopWord sw){
        int pos = hash(sw);
        int i = 0;
        do{
            if(tabela[pos].getChave() == sw.getChave()){
                tabela[pos].incrementaQuantidade();
                break;
            } 
            if(tabela[pos].getChave() != "") pos = (pos+1)%tamanho;
            else{
                tabela[pos] = sw;
                quant_elementos++;
                return true;
            }
            i++;
        }while(i< tamanho);
        return false;
    }
    bool THashing::remover(StopWord sw){
        int pos = buscar(sw);
        if(pos >= 0){
            tabela[pos] = StopWord();
            quant_elementos--;
            return true;
        }
        return false;
    }
    int THashing::buscar(StopWord sw){
        int pos = hash(sw);
        int i = 0;
        do{
            StopWord aux = tabela[pos];
            if(sw.getChave() != aux.getChave()) pos = (pos+1)%tamanho;
            else return pos;
            i++;
        }while((i<tamanho) || (tabela[pos].getChave() == ""));
        return -1;
    }
    void THashing::imprimir(){
        cout << "\n-----Tabela--------\n";
        for(int i=0;i<tamanho;i++){
            if(tabela[i].getChave() != ""){
                cout << "Chave: " << tabela[i].getChave() 
                    << "\tRecorrencia: " << tabela[i].getQuantidade()
                    << endl; 
            }
        }
        cout << endl;
    }
    bool THashing::isChave(string s){
        for(int i=0;i<tamanho;i++){
            if(tabela[i].getChave() == s) return true;
        }
        return false;
    }