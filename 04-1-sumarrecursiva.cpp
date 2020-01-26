#include <iostream>
using namespace std;

int suma(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n + suma(n-1);
    }

}

int main(){

    int n;
    cout << "Ingrese un numero natural: "; cin >> n;
    
    cout << "Resultado: " << suma(n) << endl;

    return 0;
}