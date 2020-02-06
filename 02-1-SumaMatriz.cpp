#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Ingrese el tamano de las matrices: ";
    cin >> a;
    int mat1[a][a], mat2[a][a], mat3[a][a];
    
    cout << "Matriz 1: " << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << "Valor: ";
            cin >> *(*(mat1+i)+j);
        }
    }
    
    cout << "Matriz 2: " << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << "Valor: ";
            cin >> *(*(mat2+i)+j);
        }
    }
    
    cout << endl  << "Matriz 1: " << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << "\t" << *(*(mat1+i)+j) << " ";
        }
        cout << endl;
    }
    
    cout << "Matriz 2: " << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << "\t" << *(*(mat2+i)+j) << " ";
        }
        cout << endl;
    }
    
    cout << "Suma de matrices" << endl;
    
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            *(*(mat3+i)+j) = *(*(mat1+i)+j) +(*(*(mat2+i)+j));
            cout << "\t" << *(*(mat3+i)+j) << " ";
        }
        cout << endl;
    }

    return 0;
}
