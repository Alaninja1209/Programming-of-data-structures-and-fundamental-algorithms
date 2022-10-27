#include "listasDL.hpp"

int main(){
    listaDL <string> * lista = new listaDL <string>();
    lista -> agregarInicio("Alan");
    lista -> agregarInicio("Alfredo");
    lista -> agregarInicio("Onofre");
    lista -> agregarFinal("Chavez");
    lista -> imprimirLista();
    lista -> imprimirListaReversa();
    
    //Lista CDL en el stack que almacene objetos de la clase ejemplo en stack
    listaCDL <Ejemplo> lista3;
    Ejemplo a(13,14);
    Ejemplo b;
    lista3.agregarInicio(a);
    lista3.agregarInicio(b);
    lista3.imprimirLista();
    
    listaCDL <Ejemplo *> lista4;
    listaCDL<Ejemplo> * lista5 = new listaCDL<Ejemplo>();
    listaCDL<Ejemplo *> * lista6 = new listaCDL<Ejemplo*>();
    return 0;
}
