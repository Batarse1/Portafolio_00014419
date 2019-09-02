#include <iostream>

using namespace std;

int main() {
    int cont=0;
    int matriz[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

    for(int i=0;i<5;i++){
        for(int j=cont;j<5;j++){
            cout<<"Digite el numero que quiera ingresar en la posicion ("<<i<<","<<j<<"):";cin>>matriz[i][j];
        }
        cont++;
    }

    cout<<endl;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }

    return 0;
}
