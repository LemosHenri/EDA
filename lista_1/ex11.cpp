#include<iostream>
using namespace std;

main(){
    double x,y,z;
    int horas, minutos, segundos = 0, cont=0;
    cout << "Informe massa (y)";
    cin >> y;
    cout << "Informe limiar (z)";
    cin >> z;
    cout << "Informe tempo (x)";
    cin >> x;

    do{
        y = y/2;
        cont++;
    }while(y > x);

    segundos = cont*x;
    minutos = segundos/60;
    if(segundos >= 60) segundos = segundos%60;
    horas = minutos/60;
    if(minutos >= 60) minutos = minutos%60;

    cout << "\nTempo: " << horas << "H " << minutos << "min " << segundos << "s "  << endl;
}