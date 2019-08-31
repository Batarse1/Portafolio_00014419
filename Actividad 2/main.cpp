#include <iostream>

using namespace std;

float mediana(int *p, int tamano);

int main() {
    int n;
    cout<< "Digite el tamaño del arreglo: ";cin>>n;
    cout<< "Digite los datos del arreglo de forma ordenada"<<endl;
    int numeros[n];
    for(int i=0;i<n;i++){
        cout<< "Digite numero "<<(i+1)<<": ";cin>>numeros[i];
    }
    cout<<"La mediana del arreglo es: "<<mediana(numeros,n);
    return 0;
}

float mediana(int *p, int tamano){
    float sum;
    if(tamano%2==0){
        sum=((*(p+(tamano/2-1)))+(*(p+(tamano/2))));
        return sum/2;
    }
    else{
        sum=(*(p+(tamano/2)));
        return sum;
    }
}