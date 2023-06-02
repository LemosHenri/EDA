#include<iostream>
#include<math.h>
using namespace std;

int fatorial(int i){
    if(i==1) return 1;
    else return i*fatorial(i-1);
}
main(){
    double x, cont=0;
    int j=1;

    cout << "Informe Graus em radianos:";
    cin >> x;

    for(int i=1;i<20;i=i+2){
        cont+= j*(pow(x,i)/fatorial(i)); 
        j *= -1;
    }

    cout << "sen(x) = " << cont << endl;
 }