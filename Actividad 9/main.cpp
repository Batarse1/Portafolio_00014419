//Actividad 8 echa con libreria stack
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int a=0;
    stack <float> p;
    p.push(1.2);
    p.push(3.4);
    p.push(5.6);

    if(p.empty()){
        cout<<-1;
    }
    else{
        a=p.size();
        float arreglo[a];
        for(int i=0;i<a;i++){
            if(p.empty()){
                cout<<-1;
            }
            else{
                arreglo[a-1-i]=p.top();
                p.pop();
            }
        }
        for(int i=0;i<a;i++){
            p.push(arreglo[i]);
        }
        cout<<"Ultimo elemento de la pila (dejandola pila intacta): "<<arreglo[0]<<endl;
    }

    if(p.empty()){
        cout<<-1;
    }
    else{
        for(int i=0;i<p.size()+1;i++){
            if(p.empty()){
                cout<<-1;
            }
            else{
                p.pop();
            }
        }
        cout<<"Ultimo elemento de la pila (dejandola vacia): "<<p.top();
    }
    return 0;
}