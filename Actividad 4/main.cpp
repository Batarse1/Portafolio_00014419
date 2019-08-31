//Ricardo Adrián Aparicio Lemus 00032219
//Fernando Daniel González Batarsé 00014419

#include <iostream>
#include <string>

using namespace std;

float suma=0;
float pro=0;
float y=0;
float aux=0;
int a=0;
int b=0;

struct nacion{
    string nombre;
    string capital;
    int habitantes;
    float promedio_edad;
};

struct continente{
    string nombre;
    nacion pais[5];
};

int main(){
    continente continentes[5];


    for(int i=0;i<5;i++){
        suma=0;
        cout<<"Digite el nombre del continente "<<i+1<<" ";getline(cin,continentes[i].nombre);
        for(int j=0;j<5;j++){
            cout<<"Digite el nombre del pais "<<j+1<<" ";cin>>continentes[i].pais[j].nombre;
            cout<<"Digite la capital del pais "<<j+1<<" ";cin>>continentes[i].pais[j].capital;
            cout<<"Digite el numero de habitantes del pais "<<j+1<<" ";cin>>continentes[i].pais[j].habitantes;
            cout<<"Digite el promedio de la edad de los habitantes del pais "<<j+1<<" ";cin>>continentes[i].pais[j].promedio_edad;
            suma+=continentes[i].pais[j].habitantes;
        }
        cin.clear();cin.ignore(1000,'\n');
        cout<<"La suma de población del continente "<<continentes[i].nombre<< " es de "<<suma<<endl<<endl;


    }

    for(int i=0;i<5;i++){
        cout<<continentes[i].nombre<<endl;
        for(int j=0;j<5;j++){
            cout<<continentes[i].pais[j].nombre<<endl;
            cout<<continentes[i].pais[j].capital<<endl;
            cout<<continentes[i].pais[j].habitantes<<endl;
            cout<<continentes[i].pais[j].promedio_edad<<endl;
            y+=continentes[i].pais[j].promedio_edad;
        }
    }

    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++)
            if (continentes[i].pais[j].habitantes>aux){
                aux=continentes[i].pais[j].habitantes;
                a=i;
                b=j;
            }
    }
    pro=y/25;
    cout<<"La capital con más habitantes es "<<continentes[a].pais[b].capital<<" con "<<aux<<" Habitantes"<<endl;
    cout<<endl<<"El promedio de edad mundial es "<<pro<<endl;
    return 0;
}