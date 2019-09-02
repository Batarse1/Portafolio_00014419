#include <iostream>

using namespace std;

void funcionRecursiva(int n,int cont);

int main() {
    int num=0;
    cout<< "Digite un numero: ";cin>>num;
    cout<< "LA TABLA DE MULTIPLICAR DEL "<<num<<endl;
    funcionRecursiva(num,1);
    return 0;
}

void funcionRecursiva(int n,int cont){
    if(cont==10){
        cout<<n<<"x"<<cont<<"="<<n*cont;
        return;
    }
    else{
        cout<<n<<"x"<<cont<<"="<<n*cont<<endl;
        return funcionRecursiva(n,++cont);
    }
}