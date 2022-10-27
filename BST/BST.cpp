//  Created by Alan Alfredo Onofre Chavez on 26/01/21.
#include "BST.hpp"

int main(){
    BST <int> * arbol = new BST <int> ();
    arbol -> agregaNodoIterativo(50);
    arbol -> agregaNodoIterativo(30);
    arbol -> agregaNodoIterativo(20);
    arbol -> agregaNodoIterativo(40);
    arbol -> agregaNodoIterativo(70);
    arbol -> agregaNodoIterativo(60);
    arbol -> agregaNodoIterativo(80);
    arbol -> agregaNodoIterativo(100);
    arbol -> agregaNodoIterativo(1);
    
    cout<<arbol -> buscarNodo(20) -> getValor()<<endl;
    
    //Llamada de un metodo de clase
    nodoArbolBinario <int> ::imprimirInOrder(arbol -> getRoot());
    nodoArbolBinario <int> ::imprimirInOrder(nullptr);
    
    arbol -> eliminarNodo(20);
    arbol -> imprimirArbolInOrder();
    arbol -> eliminarNodo(80);
    arbol -> imprimirArbolInOrder();
    arbol -> eliminarNodo(100);
    arbol -> imprimirArbolInOrder();
    arbol -> eliminarNodo(40);
    arbol -> imprimirArbolInOrder();
    
    return 0;
}
