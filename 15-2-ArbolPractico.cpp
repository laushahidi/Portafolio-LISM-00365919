#include <iostream>
using namespace std;

struct node{
    int n;
    node *left, *right;
};

//Declaracion 1
void preOrder(node* pTree);
void postOrder(node* pTree);
void inOrder(node* pTree);
int AlturaArbol(node* Tree, int *altura);
void auxAltura(node* tree, int a, int *altura);
int EsHoja(node* r);

//Declaracion 2
node* createLeaf(int);
void insertInTree(node**, int);

int main(void){
    node* pTree = NULL;
    int continuar = 0, number = 0, altura;
    do{
        cout << endl << "Menu principal" << endl;
        cout << "1. Ingresar dato" << endl;
        cout << "2. Ver recorridos" << endl;
        cout << "3. Profundidad" << endl;
        cout << "4. Salir" << endl;
        cout << "Su opcion: ";
        cin >> continuar; cin.ignore();
        switch(continuar){
            case 1:
                cout << endl << "Ingresar dato:"; cin >> number; cin.ignore();
                insertInTree(&pTree, number);
            break;

            case 2:
                cout << "Imprimiendo en preOrder" << endl;
                preOrder(pTree); cout << endl << endl;

                cout << "Imprimiendo en inOrder" << endl;
                inOrder(pTree); cout << endl << endl;

                cout << "Imprimiendo en postOrder" << endl;
                postOrder(pTree); cout << endl << endl;
            break;

            case 3:
                cout << endl << "Profundidad: " << AlturaArbol(pTree, &altura);
            break;
            
            case 4:
                cout << endl << "Salida exitosa" << endl;
            break;

            default:
                cout << endl << "Opcion invalida!" << endl;
            break;
        }       

    }while(continuar != 4);

    return 0;
}

int AlturaArbol(node* Tree, int *altura)
{
   *altura = 0;

   auxAltura(Tree, 0, altura); 
   return *altura;
}

void auxAltura(node* tree, int a, int *altura)
{

   if(tree->left) auxAltura(tree->left, a+1, altura);
   if(tree->right)   auxAltura(tree->right, a+1, altura);
   
   if(EsHoja(tree) && a > *altura) *altura = a;
}

int EsHoja(node* r)
{
   return !r->right && !r->left;
}

node* createLeaf(int n){
    node* leaf = new node;
    leaf->n = n;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

void insertInTree(node** tree, int n){
    if(!(*tree)){
        *tree = createLeaf(n);
    }
    else{
        if(n <= (*(*tree)).n)
            insertInTree(&(*(*tree)).left, n);
        else
            insertInTree(&(*(*tree)).right, n);
    }
}

void preOrder(node* pTree){
    if(!pTree)
        return;
    else{
        cout << pTree->n << "\t";
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}

void postOrder(node* pTree){
    if(!pTree)
        return;
    else{
        postOrder(pTree->left);
        postOrder(pTree->right);
        cout << pTree->n << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree)
        return;
    else{
        inOrder(pTree->left);
        cout << pTree->n << "\t";
        inOrder(pTree->right);
    }
}