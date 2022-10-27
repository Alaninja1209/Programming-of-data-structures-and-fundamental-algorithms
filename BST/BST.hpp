#ifndef BST_hpp
#define BST_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class nodoArbolBinario{
    T valor;
    nodoArbolBinario <T> * izq;
    nodoArbolBinario <T> * der;
    nodoArbolBinario <T> * padre;
public:
    int getValor(){return this -> valor;}
    nodoArbolBinario * getIzq(){return this -> izq;}
    nodoArbolBinario * getDer(){return this -> der;}
    nodoArbolBinario * getPadre(){return this -> padre;}
    
    //Métodos set
    void setValor(int valor){this -> valor = valor;}
    void setIzq(nodoArbolBinario * izq){this -> izq = izq;}
    void setDer(nodoArbolBinario * der){this -> der = der;}
    void setPadre(nodoArbolBinario * padre){this -> padre = padre;}
    
    //Constructor
    nodoArbolBinario(nodoArbolBinario <T> * padre, T valor){
        this -> valor = valor;
        this -> izq = nullptr;
        this -> der = nullptr;
        this -> padre = padre;
    }
    
    //Destructores
    ~nodoArbolBinario(){
        delete this -> valor;
    }
    
    static void imprimirInOrder(nodoArbolBinario <T> * actual){
        if(!actual){
            return;
        }else{
            imprimirInOrder(actual -> izq);
            cout<<actual -> getValor()<<" ";
            imprimirInOrder(actual -> der);
        }
    }
    
    static nodoArbolBinario <T> * valorMenor(nodoArbolBinario <T> * actual){
        if(actual){
            while(actual -> getIzq()){
                actual = actual -> getIzq();
            }
            return actual;
        }
        return actual;
    }
    
    static nodoArbolBinario <T> * valorMayor(nodoArbolBinario <T> * actual){
        if(actual){
            while(actual -> getDer()){
                actual = actual -> getDer();
            }
            return actual;
        }
        return actual;
    }
    
    static int suma(int a, int b){
        return a + b;
    }
};

template <typename T>
class BST{
    nodoArbolBinario<T> * root;
    public:
        //Métodos get
        nodoArbolBinario<T> * getRoot(){return this->root;}
        //Métodos set
        void setRoot(nodoArbolBinario<T> * root){this->root=root;}
        //Método constructor
        BST(){
            this->root=nullptr;
        }

        ~BST(){

        }

    void agregaNodoIterativo(T valor){
        nodoArbolBinario<T> * actual= this->root;
        nodoArbolBinario<T> * padre;
        //Arbol vacío
        if(!this->root){
            this->root= new nodoArbolBinario<T>(nullptr,valor);
            return;
        }
        if(!this->buscarNodo(valor)){
            //Árbol con valores
            //Encontrar al nodo padre
            while(actual){
                padre=actual;
                if(valor<actual->getValor()) //Determina la relación de orden
                    actual=actual->getIzq();
                else
                    actual=actual->getDer();
            }
            if(valor<padre->getValor())//El elemento es menor que el padre
                padre->setIzq(new nodoArbolBinario<T>(padre,valor));
            else
                padre->setDer(new nodoArbolBinario<T>(padre,valor));
            }else
                cout<<"Valor repetido"<<endl;
        }

    nodoArbolBinario<T> * buscarNodo(T valor){
        nodoArbolBinario<T> * actual=this->root;
        while(actual){
            if(actual->getValor()==valor){
                return actual;
            }
            else{
                actual=actual->getValor()>valor?actual->getIzq():actual->getDer();
            }
        }
        return nullptr;
    }
    
    void imprimirArbolInOrder(){
        nodoArbolBinario<T>::imprimirInOrder(this->root);
        cout<<endl;
    }
    
    void eliminarNodo(T valor){
        nodoArbolBinario <T> * eliminar = this -> buscarNodo(valor);
        nodoArbolBinario <T> * padre = nullptr;
        
        if(eliminar){
            //Establecer el nodo padre
            padre = eliminar -> getPadre();
            //Caso de eliminar un nodo hoja
            if(!eliminar -> getIzq() && !eliminar -> getDer()){
                //Actualizar referencia
                if(padre -> getValor() > eliminar -> getValor()){
                    padre -> setIzq(nullptr); //Si el nodo hoja a eliminar es el nodo izquierdo
                }
                else{
                    padre -> setDer(nullptr);
                }
                delete eliminar; //Liberar nodo
            }
            else if(!eliminar -> getIzq() && eliminar -> getDer()){ //Caso de eliminar un nodo
                //Actualizar los apuntadores
                if(padre -> getValor() < eliminar -> getValor()){
                    padre -> setIzq(eliminar -> getIzq());
                }
                else{
                    padre -> setDer(eliminar -> getIzq());
                }
                eliminar -> getIzq() -> setPadre(padre);
                delete eliminar;
            }
            else{
                nodoArbolBinario <T> * sucesor = nodoArbolBinario <T> ::valorMenor(eliminar -> getDer());
                //Copiar el valor del sucesor al nodo a eliminar
                eliminar -> setValor(sucesor -> getValor());
                if(sucesor -> getPadre() -> getValor() > sucesor -> getValor()){
                    if(sucesor -> getDer()){
                        sucesor -> getPadre() -> setIzq(sucesor -> getDer());
                        sucesor -> getPadre() -> setDer(sucesor -> getIzq());
                    }
                    sucesor -> getPadre() -> setIzq(nullptr);
                }
                else{
                    sucesor -> getPadre() -> setDer(nullptr);
                }
                delete sucesor;
            }
        }
        else{
            cout<<"El elemento no existe"<<endl;
        }
    }
};

#endif /* BST_hpp */
