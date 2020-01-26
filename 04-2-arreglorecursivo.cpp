#include <iostream>
using namespace std;

int mostrar(int *a, int n){
    if(n == 1){
        cout << a[n-1] << " ";
        return 0;
    }

    else{
        mostrar(a, n-1);
        cout << a[n-1] << " ";
    }

}

int main(){

    int tamano;

    cout << "Ingrese el tamano del arreglo: "; cin >> tamano;
    while(tamano < 1){
        cout << "Ingrese un numero mayor o igual a uno: "; cin >> tamano;
    }

    int array[tamano];

    cout << "Ingrese los numeros de menor a mayor: " << endl;

    for(int i = 0; i < tamano; i++){
        cout << "Valor " << i+1 << ": "; cin >> array[i];
    }
    
    cout << "Arreglo con recursion: " << endl;

    mostrar(array, tamano);

    cout << endl;

    return 0;
}