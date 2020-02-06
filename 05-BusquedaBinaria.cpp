#include <iostream>
using namespace std;

int array[8] = {1, 3, 4, 5, 17, 18, 31, 33};

int busquedaBinaria(int number, int ini, int fin);

int main(void){
    int number;
    cout << "Ingrese un numero: "; cin >> number; cin.ignore();

    int result = busquedaBinaria(number, 0, 7);

    if(result == -1){
        cout << endl << "Numero no encontrado" << endl;
    }
    else{
        cout << endl << "Numero encontrado en la posicion " << result << endl;
    }

    return 0;
}

int busquedaBinaria(int number, int i, int j){
    if(i > j)
        return -1;
    
    else{
        int k = (i+j)/2;
        if(number == array[k])
            return k;
        else if(number < array[k]){
            return busquedaBinaria(number, i, k-1);
        }
        else{
            return busquedaBinaria(number, k+1, j);
        }
    }
}