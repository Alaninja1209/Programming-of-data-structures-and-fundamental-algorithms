//Alan Alfredo Onofre Chávez A01632858
#include <iostream> //input y output
#include <stdlib.h> //números aleatorios
#include <time.h> //hora de la computadora
using namespace std;

//Generar un arreglo aleatorio
void generarArreglo(int arreglo [], int tam){
    srand((unsigned)time(0)); //Inicializar la semilla de generación de numeros aleatorios
    for(int i = 0; i < tam; i++){
        arreglo[i] = rand()%100;
    }
}

//Imprimir un arreglo
void imprimirArreglo(int arreglo[], int tam){
    for(int i = 0; i < tam; i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}

void metodoIntercambio(int arreglo[], int n){
    int auxiliar;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arreglo[j] < arreglo[i]){
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[i];
                arreglo[i] = auxiliar;
            }
        }
    }
}

void metodoBurbuja(int arreglo[], int n){
    //Declaración individual de variables
    bool flag = true;
    int auxiliar;
    for(int i = 0; i < n && flag; i++){
        flag = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arreglo[j + 1] < arreglo[j]){
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
                flag = true;
            }
        }
    }
}

void metodoSeleccion(int arreglo[], int n){
    int pasada, indiceMenor, aux;
    for(pasada = 0; pasada < n - 1; pasada ++){
        indiceMenor = pasada;
        //Busqueda del menor
        for(int j = indiceMenor + 1; j < n; j++){
            if(arreglo[j] < arreglo[indiceMenor]){
                indiceMenor = j;
            }
        }
        aux = arreglo[pasada];
        arreglo[pasada] = arreglo[indiceMenor];
        arreglo[indiceMenor] = aux;
    }
}

int main() {
    int tam;
    cout<<"Ingrese tamaño del arreglo ";
    cin>>tam;
    int arreglo[tam];
    //Metodo intercambio
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    metodoIntercambio(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    //Metodo burbuja
    cout<<"Ingrese el tamaño del arreglo: ";
    cin>> tam;
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    metodoBurbuja(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    //Metodo selección
    cout<<"Ingrese el tamaño del arreglo: ";
    cin>> tam;
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    metodoSeleccion(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    return 0;
}
