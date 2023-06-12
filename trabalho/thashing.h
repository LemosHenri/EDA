#include<string>
using namespace std;


class StopWord{
    private:
        string chave;   //A chave será a palavra
        int quantidade; //Quantas vezes ela aparece na frase
    public:
        StopWord();
        StopWord(string, int);
        virtual string getChave();
        virtual int getQuantidade();
        virtual void incrementaQuantidade();
};

class THashing{
    private:
        virtual int hash(StopWord);
        int tamanho;
        int quant_elementos;
        StopWord *tabela;
    public:
        THashing(int);
        ~THashing();
        virtual int getQuantelementos();
        virtual bool inserir(StopWord);
        virtual bool remover(StopWord);
        virtual int buscar(StopWord);
        virtual void imprimir();
        virtual bool isChave(string);
};