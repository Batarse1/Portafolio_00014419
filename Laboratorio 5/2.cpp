#include <iostream>
using namespace std;

//------ Creacion de nodo y de arbol ------
struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;
int pares=0,impares=0,sumapares=0,sumaimpares=0,negativos=0,ceros=0,positivos=0;

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

void recorrerPersonalizado(Arbol p){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nSe encuentra en el nodo " << p->info <<endl;
        cout << "\t1)Agregar nodo izquierda\n\t2)Agregar nodo derecha\n";
        cout << "\t3)Ir sub-arbol izquierdo\n\t4)Ir sub-arbol derecho\n";
        cout << "\t5)Regresar al nodo padre\n\tOpcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                if (p->izq == NULL){
                    int numero = 0;
                    cout << "Numero a agregar: ";
                    cin >> numero;
                    asignarIzq(p, numero);
                    cout << "Numero agregado exitosamente" << endl;
                }
                else
                    cout << "Error: ya existe sub-arbol izquierdo" << endl;
                break;
            case 2:
                if (p->der == NULL){
                    int numero = 0;
                    cout << "Numero a agregar: ";
                    cin >> numero;
                    asignarDer(p, numero);
                    cout << "Numero agregado exitosamente" << endl;
                }
                else
                    cout << "Error: ya existe sub-arbol derecho" << endl;
                break;
            case 3:
                if (p->izq != NULL)
                    recorrerPersonalizado(p->izq);
                else
                    cout << "Error: NO existe sub-arbol izquierdo" << endl;
                break;
            case 4:
                if (p->der != NULL)
                    recorrerPersonalizado(p->der);
                else
                    cout << "Error: NO existe sub-arbol derecho" << endl;
                break;
            case 5:
                continuar = false;
                break;
            default:
                cout << "Error: Opcion no valida" << endl;
                break;
        }
    }while(continuar);
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

void mostrarnodospares(Arbol a){
    if(a != NULL){
        if(a->info%2==0){
            pares+=1;
        }
        mostrarnodospares(a->izq);
        mostrarnodospares(a->der);
    }
}

void mostrarnodosimpares(Arbol a){
    if(a != NULL){
        if(a->info%2==1){
            impares+=1;
        }
        mostrarnodosimpares(a->izq);
        mostrarnodosimpares(a->der);
    }
}

void sumanodospares(Arbol a){
    if(a != NULL){
        if(a->info%2==0){
            sumapares+=a->info;
        }
        sumanodospares(a->izq);
        sumanodospares(a->der);
    }
}

void sumanodosimpares(Arbol a){
    if(a != NULL){
        if(a->info%2==1){
            sumaimpares+=a->info;
        }
        sumanodosimpares(a->izq);
        sumanodosimpares(a->der);
    }
}

void mostrarnodosnegativos(Arbol a){
    if(a != NULL){
        if(a->info<0){
            negativos+=1;
        }
        mostrarnodosnegativos(a->izq);
        mostrarnodosnegativos(a->der);
    }
}

void mostrarnodosceros(Arbol a){
    if(a != NULL){
        if(a->info==0){
            ceros+=1;
        }
        mostrarnodosceros(a->izq);
        mostrarnodosceros(a->der);
    }
}

void mostrarnodospositivos(Arbol a){
    if(a != NULL){
        if(a->info>0){
            positivos+=1;
        }
        mostrarnodospositivos(a->izq);
        mostrarnodospositivos(a->der);
    }
}

int main(){
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;

    Arbol arbol = crearArbol(variable);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu:\n\t1) Mostrar recorridos";
        cout << "\n\t2) Recorrer personalizado";
        cout << "\n\t3) Mostrar cantidad de nodos pares e impares\n\t4) Mostrar suma de los nodos pares\n\t5) Mostrar suma de los nodos impares\n\t6) Mostrar cantidad de nodos negativos, ceros y positivos\n\t7) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: recorrerArbol(arbol);
            break;
            case 2: recorrerPersonalizado(arbol);
            break;
            case 3: pares=0;mostrarnodospares(arbol);cout<<"Cantidad de nodos pares: "<<pares<<endl;impares=0;mostrarnodosimpares(arbol);cout<<"Cantidad de nodos impares: "<<impares<<endl;
            break;
            case 4: sumapares=0;sumanodospares(arbol);cout<<"Suma de los nodos pares: "<<sumapares<<endl;
            break;
            case 5: sumaimpares=0;sumanodosimpares(arbol);cout<<"Suma de los nodos impares: "<<sumaimpares<<endl;
            break;
            case 6: negativos=0;mostrarnodosnegativos(arbol);cout<<"Cantidad de nodos negativos: "<<negativos<<endl;ceros=0;mostrarnodosceros(arbol);cout<<"Cantidad de nodos ceros: "<<ceros<<endl;positivos=0;mostrarnodospositivos(arbol);cout<<"Cantidad de nodos positivos: "<<positivos<<endl;
            break;
            case 7: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}