#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct libros{
    string titulo;
    string autor;
    string genero;
};

typedef struct libros Libros;

int main(){

    stack<Libros> piladeLibros;
    
    
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de libros actual: " << piladeLibros.size();
        cout << "\nDesea agregar otro libro? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Libros unLibro;
            cout << "Titulo: ";   getline(cin, unLibro.titulo);
            cout << "Autor: ";   getline(cin, unLibro.autor);
            cout << "Genero: ";       getline(cin, unLibro.genero);
            piladeLibros.push(unLibro); 
        }
        
        else if(opcion == 'n')
            continuar = false;
            
        else
            cout << "La opcion ingresada no es valida." << endl;
            
    }while(continuar);
    
    cout << "\nDesapilando libros:" << endl;
    
    while(!piladeLibros.empty()){
        
        Libros librodeEncima = piladeLibros.top();
        cout << "Libro [" << librodeEncima.titulo;
        cout << ", " << librodeEncima.autor;
        cout << ", " << librodeEncima.genero << "]\n";
        

        piladeLibros.pop();
    }
    cout << "Pila de libros vacia." << endl;

    return 0;
}
