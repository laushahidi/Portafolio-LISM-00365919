#include <iostream>
#include <string>
using namespace std;

struct continente{
    string nombre;
    string capital;
    double habitantes;
};

typedef struct continente cont;

void registro(cont *p){

    for(int i = 0; i < 5; i++){
        cout << "\nPaís: ";
        getline(cin, (p+i)->nombre);
        cout << "Capital: ";
        getline(cin, (p+i)->capital);
        cout << "Número de habitantes: ";
        cin >> (p+i)->habitantes;
        //cout << "Promedio de edad: ";
        //cin >> p->promedioedad;
        cin.ignore();
        
    }
}

void poblacionTotal(cont *p){
    
    int suma = 0;
    for(int i = 0; i < 5; i++){
        suma += (p+i)->habitantes;
    }
    
    cout << "\nLa poblacion total del continente es de: " << suma << endl;
}

void capitalMayorPoblacion(cont *p){
    
    int r = (p+0)->habitantes;
    string h = (p+0)->capital;
    for (int i = 0; i < 5; i++){  
        if (r < (p+i)->habitantes){
            
            r = (p+i)->habitantes;
            h = (p+i)->capital;
        }
    }
    cout << "\nLa capital con mayor poblacion es: " << h << endl;
}

int main()
{
    cont paises[5];
    registro(paises);
    poblacionTotal(paises);
    capitalMayorPoblacion(paises);

    return 0;
}
