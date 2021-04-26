#include <iostream>
using namespace std;

void insertionSort(int* &ptr, int tam){
    for (int i=0; i<tam; i++) {
        int aux = ptr[i];
        for(int j=i; j>=0; j--){
            if (aux < ptr[j]) {
                ptr[j+1] = ptr[j];
                ptr[j] = aux;
            }
        }
    }
    return;
}

void printList(int* ptr, int tam){
    for (int i=0; i<tam; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int tam = 20;
    int* ptr = new int[tam];
    for (int i=0; i<tam; i++) {
        ptr[i] = rand()%9;
    }
    printList(ptr, tam);
    insertionSort(ptr, tam);
    printList(ptr, tam);
    return 0;
}
