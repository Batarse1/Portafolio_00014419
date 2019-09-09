#include <iostream>

using namespace std;

int main() {
    int n=0;

    cout<<"Digite el numero final de la sumatoria que empieza en 0: ";cin>>n;

    for(int i=n;i>0;i--){
        n=n+(i-1);
    }

    cout<<"La sumatoria es: "<<n;

    return 0;
}