#include <iostream>

using namespace std;

struct numeros{
    int numero;
    numeros *sig;
};

void menu();
void mostrarElementos(int n,numeros *PInicio);
void mostrarSuma(int *n,int *x,numeros *PInicio);

int main(void){
    numeros *PInicio=NULL;
    numeros *nuevo=NULL;
    numeros *aux=NULL;
    int n=0;
    int x=0;
    int m=0;
    int l=0;
    do{
        menu();
        cin>>n;
        if(n==0){
        }
        else if(n==1){
            x++;
            nuevo=new numeros;
            cout<<"Digite el numero que quiere agregar a la lista:";
            cin>>nuevo->numero;
            nuevo->sig=NULL;
            if(PInicio==NULL){
                PInicio=nuevo;
            }
            else{
                aux=PInicio;
                while(aux->sig!=NULL){
                    aux=aux->sig;
                }
                aux->sig=nuevo;
            }
        }
        else if(n==2){
            mostrarElementos(1,PInicio);
        }
        else if(n==3){
            mostrarSuma(&m,&l,PInicio);
            cout<<"Suma de los numeros pares: "<<m<<endl<<"Suma de los numeros impares: "<<l<<endl;
            m=0;
            l=0;
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
    cout<<"3.Mostrar sumas de elementos pares e impares de la lista"<<endl;
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

void mostrarSuma(int *n,int *x,numeros *PInicio){
    if(PInicio==NULL){
        return;
    }
    else if(PInicio->numero%2==0){
        *n+=PInicio->numero;
        return mostrarSuma(n,x,PInicio->sig);
    }
    else{
        *x+=PInicio->numero;
        return mostrarSuma(n,x,PInicio->sig);
    }
}