#include <iostream>
using namespace std;

int buscar(int *a, int n, int num){
    
    if(n < 1){
        cout << "El valor no se encuentra en el arreglo" << endl;
        return 0;
    }
    
    else if(a[n-1] == num){
        cout << "El valor se encuentra en la posicion: " << n-1 << endl;
    }

    else{
        buscar(a, n-1, num);
    }

}

int main(){

    int array[10] = {45, 22, 88, 93, 50, 65, 77, 12, 44, 6};
    int num;

    cout << "Ingrese un numero entero: "; cin >> num;

    buscar(array, 10, num);

    return 0;
}