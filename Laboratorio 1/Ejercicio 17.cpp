#include <iostream>

using namespace std;

int main() {
    int arreglo[10];
    int num=0,suma=0,promedio=0;
    while(num<10){
        cout<<"Numero "<<num+1<<": ";cin>>arreglo[num];
        num++;
    }
    num=0;
    while(num<10){
        suma+=arreglo[num];
        num++;
    }
    promedio=suma/10;
    cout<<"La suma de todos los numeros es: "<<suma<<endl;
    cout<<"El promedio es: "<<promedio<<endl;
    return 0;
}