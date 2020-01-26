#include <iostream>
#include <string>
using namespace std;

struct libros{
    string titulo;
    string autor;
    string genero;
};

typedef struct libros Libros;

struct nodo{
    Libros elemento;
    struct nodo *siguiente;
};

typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Libros e);
Libros pop(Pila *s);
Libros top(Pila *s);


int main(){

    Pila piladeLibros;
    initialize(&piladeLibros);
    
    bool continuar = true;
    do{
        char opcion = 's';

        cout << "\nDesea agregar otro libro? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Libros unLibro;
            cout << "Titulo: ";   getline(cin, unLibro.titulo);
            cout << "Autor: ";   getline(cin, unLibro.autor);
            cout << "Genero: ";       getline(cin, unLibro.genero);
            push(&piladeLibros, unLibro);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "La opcion ingresada no es valida." << endl;
    }while(continuar);

    cout << "\nDesapilando libros..." << endl;
    while(!empty(&piladeLibros)){

        Libros librodeEncima = top(&piladeLibros);
        cout << "Libro [" << librodeEncima.titulo;
        cout << ", " << librodeEncima.autor;
        cout << ", " << librodeEncima.genero << "]\n";
        
        pop(&piladeLibros);
    }
    cout << "Pila de libros vacia." << endl;

    return 0;
}

void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, Libros e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

Libros pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Libros e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else 
        return {{" "},{" "},{" "}};
}

Libros top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else 
        return {{" "},{" "},{" "}};
}

