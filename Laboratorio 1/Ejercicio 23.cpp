#include <iostream>

using namespace std;

struct numero{
    int imaginario;
    int real;
};

numero funcion(numero num1, numero num2);

int main() {
    numero num1,num2,suma;

    cout<<"PROGRAMA PARA SUMAR IMAGINARIOS "<<endl;
    cout<<"Digite la parte real del primer numero: ";cin>>num1.real;
    cout<<"Digite la parte imaginaria del primer numero: ";cin>>num1.imaginario;
    cout<<"Digite la parte real del segundo numero: ";cin>>num2.real;
    cout<<"Digite la parte imaginaria del segundo numero: ";cin>>num2.imaginario;
    suma=funcion(num1,num2);
    cout<<"La suma es "<<suma.real<<"+"<<suma.imaginario<<"j";
    return 0;
}

numero funcion(numero num1, numero num2){
    numero resultado;
    resultado.real=num1.real+num2.real;
    resultado.imaginario=num1.imaginario+num2.imaginario;
    return resultado;
}