#include<iostream>
#include<math.h>
using namespace std;

main(){
    int quant_comodo=0, quant[3] = {0,0,0}, classe, tamanho;
    double tot_lampadas=0;
    do{
        cout << "Pressionar 0 para encerrar conta" << endl;
        cout << "Informe classe do cômodo:";
        cin >> classe;
        cout << "Informe tamanho do cômodo:";
        cin >> tamanho;
        switch (classe){
            case 1:
                tot_lampadas += (double)tamanho/4; 
                quant_comodo++;
                quant[classe-1]++;
                break;
            case 2:
                tot_lampadas += (double)tamanho/3.3;
                quant_comodo++;
                quant[classe-1]++;
                break;
            case 3:
                tot_lampadas += (double)tamanho/3;
                quant_comodo++;
                quant[classe-1]++;
                break;
            case 0:
                cout << "Finalizando Calculo..." << endl;
            default:
                cout << "Opção inválida" << endl;
                break;
        }
    }while(classe != 0);

    cout << "Quantidade de comodos na casa: " << quant_comodo 
        << "\nClasse 1: " << quant[0]
        << "\nClasse 2: " << quant[1]
        << "\nClasse 3: " << quant[2]
        << "\nQuantidade de lâmpadas: " << floor(tot_lampadas) << endl;
}