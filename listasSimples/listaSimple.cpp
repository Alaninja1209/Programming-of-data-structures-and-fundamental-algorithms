#include "listaSimple.hpp"

int main(){
    ListaSimple* lista = new ListaSimple(); //Crea lista en el heap con head = nullptr y tam = 0
    lista -> agregarInicio(3);
    lista ->agregarInicio(10);
    lista -> agregarInicio(19);
    lista -> imprimirLista();
    lista -> agregarFin(100);
    lista -> imprimirLista();
    ListaSimple lista2;
    lista2.agregarInicio(4);
    lista2.agregarInicio(7);
    lista2.agregarFin(45);
    lista2.imprimirLista();
    
    return 0;
}
