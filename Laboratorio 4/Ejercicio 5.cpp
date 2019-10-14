#include <iostream>

using namespace std;

struct numeros{
    int numero;
    numeros *sig;
};

void menu();
void mostrarElementos(int n,numeros *PInicio);
void xd(numeros *PInicio);


numeros *INICIO=NULL;
numeros *NUEVO=NULL;

int main(void){
    numeros *PInicio=NULL;
    numeros *nuevo=NULL;
    numeros *aux=NULL;
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
            xd(PInicio);
            PInicio=INICIO;
            mostrarElementos(1,PInicio);
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
    cout<<"2.Mostrar elementos de la lista en forma inversa"<<endl;
    cout<<"Digite la opcion:";
}

void xd(numeros *PInicio){
    if(PInicio==NULL){
        return;
    }
    else{
        NUEVO=new numeros;
        NUEVO->numero=PInicio->numero;
        NUEVO->sig=NULL;
        if(INICIO==NULL){
            INICIO=NUEVO;
        }
        else{
            NUEVO->sig=INICIO;
            INICIO=NUEVO;
        }
        return xd(PInicio->sig);
    }
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