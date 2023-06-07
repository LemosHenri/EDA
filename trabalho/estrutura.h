#include<string>
using namespace std;

class No{
    private:
        string valor;
        No *prox;
    public:
        No(string);
        string getValor();
        void setValor(string);
        No *getProx();
        void setProx(No*);
};

class Lista{
    private:
        No *inicio;
    public:
        Lista();
        Lista(string);
        ~Lista();
        virtual void imprimir();
        virtual int size();
        virtual void inserir(int,string);
        virtual void inserir(string);
        virtual void remover(int);
};