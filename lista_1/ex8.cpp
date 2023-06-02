#include<iostream>
using namespace std;

main(){
    char sexo;
    int cont_m=0,cont_f=0,cont_total;

    do{
        cout << "------MENU-------\n[M] - Adicionar Masculino\n[F] - Adicionar Feminino\n[S] - Sair\nOpição:";
        cin >> sexo;
        switch (sexo){
            case 'm':
            case 'M':
                cont_m++;
                cout << "Masculino Adicionado";
                break;
            case 'f':
            case 'F':
                cont_f++;
                cout << "Feminino Adicionado";
                break;
            case 's':
            case 'S':
                cout << "Finalizando Contagem...\n";
                break;
            default:
                cout << "Valor inválido!!\n";                
                break;
        }
    }while(!((sexo == 's') || (sexo == 'S')));

    cout << "Contagem Final:\nMasculino: "<< cont_m << "\nFeminino: "<< cont_f 
         <<  "\nPorcentagem Masculino: " << 100*(double)cont_m/(cont_m+cont_f) 
         <<  "%\nPorcentagem Feminino: " << 100*(double)cont_f/(cont_m+cont_f) << "%"
         << endl;
}