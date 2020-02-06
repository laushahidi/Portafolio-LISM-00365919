#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct actividades{
    string titulo, hora;
    int minutos;
};

typedef struct actividades Act;

struct agenda{
    queue <Act> colaAgenda;
    int totalAct;
};

typedef struct agenda Agenda;

Agenda miAgenda;

void insertar();
void borrarUna();
void borrarTodas();
void ver();

int main()
{
    miAgenda.totalAct = 0;
    bool continuar = true;
    do{
        int opcion = 0;
        
        cout << "\n1. Insertar una actividad" << endl;
        cout << "2. Borrar una actividad" << endl;
        cout << "3. Borrar todas las activdades" << endl;
        cout << "4. Ver todas las actividades del dia" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: insertar(); break;
            case 2: borrarUna(); break;
            case 3: borrarTodas(); break;
            case 4: ver(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida\n"; break; 
        }
    }while(continuar);

    return 0;
}


void insertar(){
    Act unaAct;
    cout << endl << "Insertar una actividad" << endl;
    cout << "Titulo de la actividad: "; getline(cin, unaAct.titulo);
    cout << "Hora de inicio: "; getline(cin, unaAct.hora);
    cout << "Duracion en minutos: "; cin >> unaAct.minutos;
    cin.ignore();
    
    miAgenda.colaAgenda.push(unaAct);

}
void borrarUna(){
    
}
void borrarTodas(){
    cout << endl << "Borrando todas las actividades" << endl;
    while(!miAgenda.colaAgenda.empty()){
        Act actBorrada = miAgenda.colaAgenda.front();
        cout << endl << "Borrando actividad: " << actBorrada.titulo << endl;
        cout << "Hora de inicio: " << actBorrada.hora << endl;
        cout << "Duracion en minutos: " << actBorrada.minutos << endl;
        
        miAgenda.colaAgenda.pop();
    }
    cout << "Cola de actividades vacia!" << endl;
    
}
void ver(){
    cout << endl << "Actividades guardadas" << endl;
    cout << "Actividades actuales guardades en agenda: " << miAgenda.colaAgenda.size() << endl;
    Agenda otraAgenda;
    otraAgenda.colaAgenda = miAgenda.colaAgenda; 
    while(!miAgenda.colaAgenda.empty()){
        Act mostrarAct;
        Act actBorrada = miAgenda.colaAgenda.front();
        cout << endl << "Actividad: " << mostrarAct.titulo << endl;
        cout << "Hora de inicio: " << mostrarAct.hora << endl;
        cout << "Duracion en minutos: " << mostrarAct.minutos << endl;
        
        miAgenda.colaAgenda.pop();
    }
    cout << "Ya no hay mas actividades" << endl;
    
}
