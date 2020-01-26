#include <iostream>
using namespace std;

struct Pedido{
    string apellido;
    int mesa;
    int burger;
    int cheeseburger;
    int tiempo;
};

typedef struct Pedido P;
const P noValido = {{" "},-1,-1,-1,-1};

struct Nodo{
    P elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

void initialize(Cola *p);
bool empty(Cola *p);
P front(Cola *p);
P back(Cola *p);
void enqueue(Cola *p, P x);
P dequeue(Cola *p);
int size(Cola *p);

struct Hamburgueseria{
    Cola colaBurgers;
    int burgersHechas;
};

Hamburgueseria inandout;

void agregar();
void consultar();
void servir();
void vertodos();

 
int main()
{
    initialize(&inandout.colaBurgers);
    inandout.burgersHechas = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << endl << "La opcion ingresada no es valida.\n"; break;
        }
        
    }while(continuar);


    return 0;
}

void initialize(Cola *p){
    p->frente = NULL;
    p->final = NULL;
}

bool empty(Cola *p){
    return (p->frente == NULL) ? true : false;
}

P front(Cola *p){
    if(empty(p)){
        cout << "Cola vacia" << endl;
        return noValido;
    }
    else{
        return (p->frente)->elemento;
    }
}

P back(Cola *p){
    if(empty(p)){
        cout << "Cola vacia" << endl;
        return noValido;
    }
    else{
        return (p->final)->elemento;
    }
}

void enqueue(Cola *p, P x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(p->final == NULL){
        p->frente = unNodo;
    }
    else{
        (p->final)->siguiente = unNodo;
    }
    p->final = unNodo;
}

P dequeue(Cola *p){
    if(empty(p)){
        cout << "Cola vacia" << endl;
        return noValido;
    }
    Nodo *unNodo = p->frente;
    P x = unNodo->elemento;
    p->frente = unNodo->siguiente;
    if(p->frente==NULL)
        p->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *p){
    Cola colaTemp;
    initialize(&colaTemp);
    
    int contador = 0;

    while(!empty(p)){
        P elemento = dequeue(p);
        enqueue(&colaTemp, elemento);
        contador++;
    }

    while(!empty(&colaTemp)){
        P elemento = dequeue(&colaTemp);
        enqueue(p, elemento);
    }
    return contador;
    
}

//FUNCIONES

void agregar(){
    Pedido unPedido;
    cout << endl << "Apellido: "; getline(cin, unPedido.apellido);
    cout << "Numero de mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Cantidad de hamburguesas normales: "; cin >> unPedido.burger; cin.ignore();
    cout << "Cantidad de hamburguesas con queso: "; cin >> unPedido.cheeseburger; cin.ignore();
    unPedido.tiempo = (unPedido.burger+unPedido.cheeseburger) * 7;
    
    enqueue(&inandout.colaBurgers, unPedido);
    inandout.burgersHechas += (unPedido.burger+unPedido.cheeseburger);
}

void consultar(){
    if(empty(&inandout.colaBurgers)){
        cout << endl << "No hay pedidos en espera" << endl;
        cout << "Total de hamburguesas hechas: " << inandout.burgersHechas << endl;
    }
    else{
        cout << endl << "Pedidos en espera: " << size(&inandout.colaBurgers) << endl;
        cout << "Total de hamburguesas hechas: " << inandout.burgersHechas << endl;
    }
}

void servir(){
    
    if(empty(&inandout.colaBurgers)){
        cout << endl << "No hay pedidos en espera" << endl;
    }
    Pedido ordenLista = dequeue(&inandout.colaBurgers);
    cout << endl << "Orden lista para familia: " << ordenLista.apellido << endl;
    cout << "Mesa: " << ordenLista.mesa << endl;

}

void vertodos(){
    Cola colaTemp;
    initialize(&colaTemp);
    
    if(empty(&inandout.colaBurgers)){
        cout << endl << "No hay pedidos en espera" << endl;
    }
    
    while(!empty(&inandout.colaBurgers)){
        Pedido unPedido = dequeue(&inandout.colaBurgers);
        enqueue(&colaTemp, unPedido);
        
        cout << endl << endl << "Informacion del pedido" << endl << "Familia: " << unPedido.apellido << endl;
        cout << "Hamburguesas normales: " << unPedido.burger << endl;
        cout << "Hamburguesas con queso: " << unPedido.cheeseburger << endl;
        cout << "No. de mesa: " << unPedido.mesa << endl;
        cout << "Tiempo de espera en minutos: " << unPedido.tiempo << endl << endl;
    }
    
    while(!empty(&colaTemp)){
        P elemento = dequeue(&colaTemp);
        enqueue(&inandout.colaBurgers, elemento);
    }
}
