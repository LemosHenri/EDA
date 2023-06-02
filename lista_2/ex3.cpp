#include<iostream>
#include<math.h>
using namespace std;

int fatorial(int n){
    if(n==1) return 1;
    else return n*fatorial(n-1);
}

double sen(int op, double x, int n){
    if(n==1) return op*(pow(x,n))/fatorial(n);
    else return op*(pow(x,n))/fatorial(n) + sen(-op,x,n-2);
}
main(){
    int n, x, op=1;

    cout << "Informe valor de x em radianos: ";
    cin >> x;

    cout << "Sen(x) = " << sen(1,x,21) << endl;
}