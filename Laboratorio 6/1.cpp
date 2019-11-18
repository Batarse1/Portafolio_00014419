#include <iostream>
#include <stack>

using namespace std;
bool termino=false;
bool noesta=false;
stack<int>nodos;
//------ Creacion de nodo y de arbol ------
struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (numero a agregar)
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;

    Arbol p = a;

    //desplazarse hasta el lugar adecuado
    while(true){
        if(numero < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }

    //agregar el nuevo nodo
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << " " << a->info;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->info;
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}

void listainorden(Arbol a){
    if(a != NULL){
        listainorden(a->izq);
        nodos.push(a->info);
        listainorden(a->der);
    }
}

void arreglar(int numero){
    if(!nodos.empty()){
        while(nodos.top()!=numero){
            nodos.pop();
            if(nodos.empty()){
                cout<<"El elemento no se encontro!"<<endl;
                noesta=true;
                break;
            }
        }
    }
    else{
        cout<<"El arbol esta vacio!"<<endl;
    }
}

void recorrerLista(){
    while (!nodos.empty()) {
        cout << nodos.top() << endl;
        nodos.pop();
    }
}

void recorrerArbolLista(Arbol a){
    int numero=0;
    cout<<"Numero hasta el cual quiere recorrer el arbol: ";cin>>numero;
    cout<<"Ruta de busqueda de un nodo en inorden"<<endl;
    listainorden(a);
    arreglar(numero);
    if(noesta==true){
        listainorden(a);
        noesta=false;
    }
    recorrerLista();
}

int main(){
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;

    Arbol arbol = crearArbol(variable);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
             << "\n\t3) Ruta de busqueda de un numero por inorden con una pila \n\t4) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
                break;
            case 2: recorrerArbol(arbol);
                break;
            case 3: recorrerArbolLista(arbol);termino=false;
                break;
            case 4: continuar = false;
                break;
            default: cout << "Opcion erronea!" << endl;
                break;
        }
    }while(continuar);

    return 0;
}