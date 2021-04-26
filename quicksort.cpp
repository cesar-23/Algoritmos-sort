#include<iostream>
#include<stdio.h>
#include<iomanip>

#define T 100

using namespace std;

void mostrarOrden(int [T],int);
void quicksort(int [T],int,int);

int main(){
	
	int num, A[T];
	cout<<"Numero de elementos: ";
	cin>>num;
		
	cout<<"Ingrese elementos del array"<<endl;
	for(int i=0;i<num;i++){
		cout<<"A["<<i<<"] = ";
		cin>>A[i];
	}

	cout<<"Elementos ingresados del array:"<<endl;
	for(int i=0;i<num;i++){
		cout<<A[i]<<setw(5);
	}
	
	quicksort(A,0,num-1);
	mostrarOrden(A,num);
	
}

//Funcion para mostrar el array	
void mostrarOrden(int A[T],int num){
	cout<<"\nElementos del array ordenados:"<<endl;
	for(int i=0;i<num;i++){
	cout<<A[i]<<setw(5);
	}
	cout<<endl;	
}

//Funcion para ordenar lista de elementos 	
void quicksort(int A[T], int primero, int ultimo){
	int central,i,j,pivote;
	central=(primero+ultimo)/2;//posición central del array
	
	pivote=A[central];
	i=primero;
	j=ultimo;
	
	do{
		//separar en dos partes el array
		while(A[i]<pivote) i++; //menores del pivote
		while(A[j]>pivote) j--; //mayores del pivote
		//intercambio de valores
		if(i<=j){
			int aux;
			aux=A[i];
			A[i]=A[j];
			A[j]=aux;
			i++;
			j--;
		}
		
	}while(i<=j);
	
	if(primero<j)
		quicksort(A,primero,j);
	if(i<ultimo)
		quicksort(A,i,ultimo);

}
