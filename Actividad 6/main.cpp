//Fernando Daniel González Batarsé 00014419
#include <iostream>

using namespace std;

int mostrar(int x,int low,int high,int a[]);

int main(){
    int arreglo[8]={1,3,4,5,17,18,31,33};
    int x=0;
    cout<<"Digite un número: ";
    cin>>x;
    cout<<"El número esta en la posición: "<<mostrar(x,0,7,arreglo);

    return 0;
}

int mostrar(int x,int low,int high,int a[]){
    int mid;
    if(low>high){
        return -1;
    }
    mid=(low+high)/2;
    if(x==a[mid]){
        return mid;
    }
    else if(x<a[mid]){
        mid--;
        return mostrar(x,low,mid,a);
    }
    else{
        mid++;
        return mostrar(x,mid,high,a);
    }
}