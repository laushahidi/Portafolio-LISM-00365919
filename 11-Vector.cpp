#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Articulo{
    string nombre;
    int peso;
    float precio;
    bool perecedero;
};
vector<Articulo> bodega;

bool compNombre(Articulo a, Articulo b){
    return a.nombre < b.nombre;
}
bool compPeso(Articulo a, Articulo b){
    return a.peso < b.peso;
}
bool compPrecio(Articulo a, Articulo b){
    return a.precio < b.precio;
}

void agregar(), buscar(), eliminar(), mostrar(), mostrarPerecederos(), mostrarMasDe300G(), mostrarMasDe50(), ordenar();

int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar articulos a la bodega.\n";
        cout << "2) Buscar articulos.\n";
        cout << "3) Eliminar articulos.\n";
        cout << "4) Mostrar todo lo que contenga la bodega.\n";
        cout << "5) Mostrar articulos perecederos.\n";
        cout << "6) Mostrar articulos que pesan mas de 300 gramos.\n";
        cout << "7) Mostrar articulos que valen mas de %50.\n";
        cout << "8) Ordenar.\n";
        cout << "9) Salir.\n";
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: mostrarPerecederos(); break;
            case 6: mostrarMasDe300G(); break;
            case 7: mostrarMasDe50(); break;
            case 8: ordenar(); break;
            case 9: continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregar(){
    Articulo unArticulo;
    int aux;
    cout << "Nombre: "; getline(cin, unArticulo.nombre);
    cout << "Peso: "; cin >> unArticulo.peso; cin.ignore();
    cout << "Precio: "; cin >> unArticulo.precio; cin.ignore();
    cout << "Es perecedero? \n1. Si\n2. No\nSu opcion: "; cin >> aux; cin.ignore();
    if(aux != 1 && aux != 2){
        cout << "Opcion incorrecta, 1 - Si / 2 - No";
        cin >> aux; cin.ignore();
    }
    if(aux == 1)
        unArticulo.perecedero = true;
    else
        unArticulo.perecedero = false;
    
    bodega.insert(bodega.end(), unArticulo);
    cout << "Articulo ingresado exitosamente!\n";
}
void buscar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    bool encontrado = false;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == unNombre){
            encontrado = true;
            break;
        }
    }
    
    if(encontrado)
        cout << "Articulo si se encuentra en la bodega.\n";
    else
        cout << "Articulo no se encuentra en la bodega.\n";
}
void eliminar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
}
void mostrar(){
    for (int i = 0; i < bodega.size(); i++) {
        cout << endl << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
        cout << "Perecedero: " << bodega[i].perecedero << endl << endl;
    }
}

void mostrarPerecederos(){
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].perecedero){
            cout << endl << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos y vale $" << bodega[i].precio << "\n";
            cout << "Perecedero: " << bodega[i].perecedero  << endl << endl;
        }
    }
}

void mostrarMasDe300G(){
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].peso >= 300){
            cout << endl << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos y vale $" << bodega[i].precio << "\n";
            cout << "Perecedero: " << bodega[i].perecedero << endl << endl;
        }
    }
}

void mostrarMasDe50(){
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].precio >= 50){
            cout << endl << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos y vale $" << bodega[i].precio << "\n";
            cout << "Perecedero: " << bodega[i].perecedero << endl << endl;
        }
    }
}
void ordenar(){
    int opcion = 0;
    cout << "Criterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}

