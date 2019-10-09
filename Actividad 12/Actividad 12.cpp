#include <iostream>
#include <string>

using namespace std;

struct Orden{
    int revueltas;
    int frijolConQueso;
    int queso;
    bool arroz;

    Orden *sig;
};

void menu();
void mostrar(Orden *lista,int n);

int main() {
    Orden *Pinicio=NULL;
    Orden *nuevo=NULL;
    Orden *aux=NULL;
    string res;
    int n=1;
    do{
        menu();
        cout<<"Digite una opcion: ";
        cin>>n;
        if(n==0){
            cout<<"Saliendo..."<<endl;
        }

        else if(n==1){
            nuevo= new Orden;
            cout<<"Digite cuantas pupusas revueltas: ";
            cin>>nuevo->revueltas;
            cout<<"Digite cuantas pupusas frijol con queso: ";
            cin>>nuevo->frijolConQueso;
            cout<<"Digite cuantas pupusas queso: ";
            cin>>nuevo->queso;
            cout<<"Quiere sus pupusas de arroz?: ";
            cin>>res;
            if(res=="Si" or res=="si" or res=="SI"){
                nuevo->arroz=true;
            }
            else{
                nuevo->arroz=false;
            }

            nuevo->sig=NULL;

            if(Pinicio==NULL){
                Pinicio=nuevo;
            }
            else{
                aux=Pinicio;
                while(aux->sig!=NULL){
                    aux=aux->sig;
                }
                aux->sig=nuevo;
            }

        }
        else if(n==2){
            mostrar(Pinicio,1);
        }
        else{
            cout<<"Digito un numero incorrecto"<<endl;
        }
    }while(n!=0);

    return 0;
}

void menu(){
    cout<<"0. Salir"<<endl;
    cout<<"1. Insertar pedido"<<endl;
    cout<<"2. Mostrar pedido"<<endl;
}

void mostrar(Orden *lista,int n){
    if(lista==NULL){
        return;
    }
    else{
        cout<<"PEDIDO "<<n<<endl;
        if(lista->arroz==true){
            cout<<"Pupusas de arroz"<<endl;
        }
        else{
            cout<<"Pupusas de maiz"<<endl;
        }
        cout<<"Pupusas revueltas: "<<lista->revueltas<<endl;
        cout<<"Pupusas de frijol con queso: "<<lista->frijolConQueso<<endl;
        cout<<"Pupusas de queso: "<<lista->queso<<endl;

        return mostrar(lista->sig,++n);
    }
}