#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

struct numeros{
    int numero;
    numeros *sig;
};

void menu();
void mostrarElementos(int n,numeros *PInicio);
void mostrarElementosInvertidos(int n,numeros *PInicio);
void mostrarPares(int n,numeros *PInicio);
void mostrarImpares(int n,numeros *PInicio);

int main(void){
    srand(time(NULL));
    numeros *PInicio=NULL;
    numeros *nuevo=NULL;
    int n=0;
    int x=0;
    do{
        menu();
        cin>>n;
        if(n==0){
        }
        else if(n==1){
            x++;
            nuevo=new numeros;
            nuevo->numero=rand()%100+1;
            nuevo->sig=NULL;
            if(PInicio==NULL){
                PInicio=nuevo;
            }
            else{
                nuevo->sig=PInicio;
                PInicio=nuevo;
            }
        }
        else if(n==2){
            mostrarElementos(1,PInicio);
        }
        else if(n==3){
            mostrarPares(1,PInicio);
        }
        else if(n==4){
            mostrarImpares(1,PInicio);
        }
        else if(n==5){
            mostrarElementosInvertidos(++x,PInicio);
        }
        else{
            cout<<"Opcion invalida"<<endl;
        }
    }while(n!=0);
    return 0;
}

void menu(){
    cout<<"0.Salir"<<endl;
    cout<<"1.Ingresar elemento aleatorio a la lista"<<endl;
    cout<<"2.Mostrar elementos de la lista"<<endl;
    cout<<"3.Mostrar elementos pares de la lista"<<endl;
    cout<<"4.Mostrar elementos impares de la lista"<<endl;
    cout<<"5.Mostrar todos los elementos de la lista en sentido inverso"<<endl;
    cout<<"Digite la opcion:";
}

void mostrarElementos(int n,numeros *PInicio){
    if(PInicio==NULL){
        return;
    }
    else{
        cout<<"Numero "<<n<<":"<<PInicio->numero<<endl;
        return mostrarElementos(++n,PInicio->sig);
    }
}

void mostrarElementosInvertidos(int n,numeros *PInicio){
    if(PInicio==NULL){
        return;
    }
    else{
        mostrarElementosInvertidos(--n,PInicio->sig);
        cout<<"Numero "<<n<<":"<<PInicio->numero<<endl;
        return;
    }
}

void mostrarPares(int n,numeros *PInicio){
    if(PInicio==NULL){
        return;
    }
    else if(PInicio->numero%2==0){
        cout<<"Numero "<<n<<":"<<PInicio->numero<<endl;
        return mostrarPares(++n,PInicio->sig);
    }
    else{
        return mostrarPares(n,PInicio->sig);
    }
}

void mostrarImpares(int n,numeros *PInicio){
    if(PInicio==NULL){
        return;
    }
    else if(PInicio->numero%2==1){
        cout<<"Numero "<<n<<":"<<PInicio->numero<<endl;
        return mostrarPares(++n,PInicio->sig);
    }
    else{
        return mostrarPares(n,PInicio->sig);
    }
}