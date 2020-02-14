// Mediana
#include <iostream>
using namespace std;

float mediana(float *a, int n){

    int b; 
    float med;

    if(n % 2 == 0){
        b = n / 2;
        med = (a[b-1] + a[b]) / 2;    
    }

    else{
        b = (n / 2) + 1;
        med = a[b - 1];
    }

    cout << "La mediana es: " << med << endl;

    return 0;

}

int main(){

    int tamano;

    cout << "Ingrese el tamano del arreglo: "; cin >> tamano;
    while(tamano < 2){
        cout << "Ingrese un numero mayor o igual a dos: "; cin >> tamano;
    }

    float array[tamano];

    cout << "Ingrese los numeros de menor a mayor: " << endl;

    for(int i = 0; i < tamano; i++){
        cout << "Valor " << i+1 << ": "; cin >> array[i];
    }

    mediana(array, tamano);

    return 0;
}