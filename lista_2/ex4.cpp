#include<iostream>
#include<math.h>
using namespace std;

double variancia(double *v, int n, int media){
    double var = 0;
    for(int i=0;i<n;i++) var += pow(v[i]-media,2);
    return var/n;
}
main(){
    double v[6] = {1,2,3,4,5,6}, media=0;

    for(int i=0;i<6;i++) media += v[i];
    media = media/6.0;

    cout << "Variância: " << variancia(v,6,media) 
        << "\nMédia: " << media << endl;
}