#include "listaSimpleTemplate.hpp"

int main(){
    ListaSimpleTemplate <int>* lista = new ListaSimpleTemplate <int>(); //Crea lista en el heap con head = nullptr y tam = 0
    lista -> agregarInicio(3);
    lista -> agregarInicio(10);
    lista -> agregarInicio(19);
    lista -> imprimirLista();
    lista -> agregarFinal(100);
    lista -> imprimirLista();
    
    ListaSimpleTemplate <int> lista2;
    lista2.agregarInicio(4);
    lista2.agregarInicio(7);
    lista2.agregarFinal(45);
    lista2.imprimirLista();
    
    ListaSimpleTemplate <string> lista3;
    lista3.agregarInicio("Alan");
    lista3.agregarInicio("Alfredo");
    lista3.imprimirLista();
    
    listaCircular <float> lista4;
    lista4.agregarInicio(3.1);
    lista4.agregarInicio(5.5);
    lista4.agregarInicio(4.2);
    lista4.agregarFinal(9.8);
    lista4.imprimirLista();
    
    return 0;
}
