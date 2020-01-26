#include <iostream>
using namespace std;

struct continente{
    string nombre;
    string capital;
    double habitantes;
    int promedioedad;
};

typedef struct continente cont;

void registro(cont *p){

    for(int i = 0; i < 5; i++){
        cout << "\nPaís: ";
        getline(cin, p->nombre);
        cout << "Capital: ";
        getline(cin, p->capital);
        cout << "Número de habitantes: ";
        cin >> p->habitantes;
        cout << "Promedio de edad: ";
        cin >> p->promedioedad;
        cin.ignore();
        
    }
}

void poblacionTotal(cont *p){
    
    int suma = 0;
    for(int i = 0; i < 5; i++){
        suma += p->habitantes;
    }
    
    cout << "\nLa poblacion total del continente es de: " << suma << endl;
}

void capitalMayorPoblacion(cont *p){
    
    for(int i = 0; i < 5; i++){
        if(p->habitantes > );
    }
}

void promedioEdadCont(cont *p){
    
}

int main()
{
    cont paises[5];
    registro(paises);
    poblacionTotal(paises);
    capitalMayorPoblacion(paises);

    return 0;
}

