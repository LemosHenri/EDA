#include<string>
using namespace std;
#include "item.h"

class Lista{
    private:
        string elemento;
        Lista *prox;
    public:
        Lista();
        ~Lista();
        virtual void setElemento(string);
        virtual string getElemento();
        virtual void inserir(int,string);
        virtual void remover(int);
};