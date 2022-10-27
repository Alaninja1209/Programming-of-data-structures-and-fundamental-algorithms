#ifndef grafos_hpp
#define grafos_hpp
#include <stdio.h>
#include <vector>
#include "queue.hpp"
//Listas

//Clase que representa los arcos de un grafo asociado a un nodo especifico
template <typename T>
class Arco{
    T valor;  //valor que almacena el valor del nodo destino
    int peso; //atributo para almacenar el peso asociado al arco si es un grafo no ponderado colocar 1

    public:
        T getValor(){return this->valor;}
        int getPeso(){return this->peso;}
        void setValor(T valor){this->valor=valor;}
        void setPeso(int peso){this->peso=peso;}
        Arco(T valor, int peso){
            this->valor=valor;
            this->peso=peso;
        }
};

//Clase que representa los nodos que pertenecen al grafo
template <typename T>
class NodoGrafo{
    T valor;
    Lista<Arco<T> *> * arcos;
    public:
        T getValor(){return this->valor;}
        Lista<Arco<T> *> * getArcos(){return this->arcos;}
        void setValor(T valor){this->valor=valor;}
        void setArcos(Lista<Arco<T> *> * arcos){this->arcos=arcos;}
        NodoGrafo(T valor){
            this->valor=valor;
            this->arcos=new Lista<Arco<T>*>();
        }
};

template <typename T>
class Grafo{
    int numNodos;
    Lista<NodoGrafo<T> *> * nodos;

    public:
        Grafo(){
            this->numNodos=0;
            this->nodos=new Lista<NodoGrafo<T>*>();
        }

        void insertarNodoGrafo(T valor){
            //Si el nodo no existe
            if(!this->buscarNodo(valor)){
                this->nodos->agregarInicio(new NodoGrafo<T>(valor));
                this->numNodos++;
            }else //Si el nodo existe
                cout<<"Nodo ya existente"<<endl;
        }

        NodoGrafo<T> * buscarNodo(T valor){
            Nodo<NodoGrafo<T> *> * actual=this->nodos->getHead();
            while(actual){
                if(actual->getValor()->getValor()==valor) //NodoGrafo->getValor)
                    return actual->getValor();
                actual=actual->getSiguiente();
            }
            return nullptr;
        }

        //Método para agregar arcos
        void agregarArco(T valorNodoOrigen, T valorNodoDestino,int peso){
            //Validar que tanto el nodo origen como destino se encuentre en la lista de nodos del grafo
            NodoGrafo<T> * origen= this->buscarNodo(valorNodoOrigen);
            NodoGrafo<T> * destino= this->buscarNodo(valorNodoDestino);
            if(origen&&destino)
                //Agregar a la lista de conexiones del nodo origen el nodo destino
                origen->getArcos()->agregarInicio(new Arco<T>(destino->getValor(),peso));
            else
                cout<<"Ambos nodos tanto origen como destino deben existir dentro de lista"<<endl;
        }
    
    //Método para imprimir la lista de adyacencias
    void imprimirGrafo(){
        Nodo <NodoGrafo<T>*> * actual = this -> nodos -> getHead();
        while(actual){
            cout<<"Nodo: "<<actual -> getValor() -> getValor();
            Nodo<Arco<T>*> * auxiliar = actual -> getValor() -> getArcos() -> getHead();
            while(auxiliar){
                cout<<" -> "<<auxiliar -> getValor() -> getValor()<<" : "<<auxiliar -> getValor() -> getPeso();
                auxiliar = auxiliar -> getSiguiente();
            }
            cout<<endl;
            actual = actual -> getSiguiente();
        }
        cout<<endl;
    }
    
    NodoGrafo <T> * buscarId(int id){
        if(id >= 0 && this -> numNodos > id){
            int aux = 0;
            Nodo<NodoGrafo<T> * > * actual = this -> nodos -> getHead();
            while(aux != id){
                actual = actual -> getSiguiente();
                aux ++;
            }
            return actual -> getValor();
        }
        return nullptr;
    }
    
    int buscarPosicion(T valor){
        int pos = 0;
        Nodo<NodoGrafo<T>*> * actual = this -> nodos -> getHead();
        while(actual){
            if(actual -> getValor() -> getValor() == valor){
                return pos;
            }
            actual = actual -> getSiguiente();
            pos ++;
        }
        return -1;
    }
    
    void BreadthFirst(int id){
        vector <bool> estados(this -> numNodos, false);
        Queue <NodoGrafo<T> *> * queue = new Queue<NodoGrafo<T>*> ();
        estados[id] = true;
        queue -> push(this -> buscarId(id));
        while(queue -> front()){
            NodoGrafo <T> * nodografo = queue -> pop() -> getValor();
            cout<<nodografo -> getValor()<<" ";
            Nodo<Arco<T>*> * actual = nodografo -> getArcos() -> getHead();
            while(actual){
                int id_aux = this -> buscarPosicion(actual -> getValor() -> getValor());
                if(!estados[id_aux]){
                    estados[id_aux] = true;
                    queue -> push(this -> buscarId(id_aux));
                }
                actual = actual -> getSiguiente();
            }
        }
        cout<<endl;
    }
    
    void depthFirst(int id){
        vector <bool> visit(this -> numNodos, false);
        Pila <NodoGrafo<T>*> * queue = new Pila<NodoGrafo<T>*>();
        visit[id] = false;
        queue -> push(this -> buscarId(id));
        
        while(queue -> front()){
            vector <NodoGrafo<T>*>* nodoAnterior;
            
        }
    }
};

#endif /* grafos_hpp */
