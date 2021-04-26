/*El counting sort es un metodo de ordenamiento que funciona con numero positivos enteros, es
de su complejidad computacional es O(n+k), siendo n el número de elementos a ordenar y k el tamaño del vector auxiliar
PROCESO
    El algoritmo resive un array con elementos desordenados
    busca cual es el numero mayor y genera un array de ese tamaño
    ese algoritmo alamcena el numero de repeticiones de un numero en su indice:
        si hay 3 veces un 4, se alacenara 3 en el index[i=4]
    luego de "contar" hace una suma acumulativa para encontrar el maximo de numeros menores:
        si el array del conteo fuese: array[]={0,2,1,1,3,0,4}, el nuevo array seria: array[]={0,2,3,4,7,7,11}
        luego de izquierda a derecha asigna el valor que almacena al index de un nuevo array de salida, donde se alamacena la informacion ordenada
        importante, el valor de cuenta tiene que reducir en una unidad por cada numero que se asigne al array
*/
/////IMPORTANTE//////
/* Este codigo fue extraido de internet:
    https://www.tutorialspoint.com/cplusplus-program-to-implement-counting-sort#:~:text=Counting%20sort%20is%20a%20stable,can%20increase%20the%20space%20complexity.
*/

#include<iostream>
#include<algorithm>
using namespace std;
void display(int *array, int size) {                                        //Funcion para imprimir el array
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int getMax(int array[], int size) {                                         //Obtiene el valor maximo de todo el array
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max;
}
void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];                                                        //Crea el array cuenta, con la misma cantidad de elementos
   for(int i = 0; i<=max; i++)
      count[i] = 0;                                                         //Los inicializa en 0
   for(int i = 1; i <=size; i++)
      count[array[i]]++;                                                    //Cuenta la cantidad de incidencia de un valor
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];                                               //se transforma a el contador acumulado
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];                                   //Empieza desde el final y por cada valor que encuentre añade al output el valor de la posicion que dicta el count
      count[array[i]] -= 1;                                                 //Cambia el valor de cuenta reduciendolo en uno en caso de incidencias muy util
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i];                                                 //cambia los valores del array original por los ya ordenados
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n+1];                                                              //crea un array y destabelece sus valores
   cout << "Enter elements:" << endl;
   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   countSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}