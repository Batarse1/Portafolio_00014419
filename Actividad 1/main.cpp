#include <iostream>

using namespace std;

void calculos(int num, int *doble, int *triple){
    cout<<"La direccion de memoria de la variable doble a la que esta apuntando el puntero es "<<doble<<endl;
    cout<<"La direccion de memoria de la variable triple a la que esta apuntando el puntero es "<<triple<<endl;
    cout<<"La direccion de memoria del puntero que esta apuntando a la variable doble es "<<&doble<<endl;
    cout<<"La direccion de memoria del puntero que esta apuntando a la variable triple es "<<&triple<<endl;
    cout<<"El valor de la variable doble a la que esta apuntando el puntero es "<<*doble<<endl;
    cout<<"El valor de la variable triple a la que esta apuntando el puntero es "<<*triple<<endl;
    *doble=2*num;
    *triple=3*num;
}

int main() {
    int numero=2,doble=0,triple=0;

    calculos(numero, &doble, &triple);
    cout<<"El doble de 2 es "<<doble<<endl;
    cout<<"El triple de 2 es "<<triple<<endl;

    return 0;
}