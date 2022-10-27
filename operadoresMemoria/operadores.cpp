//  Created by Alan Alfredo Onofre Chavez on 19/01/21.
#include "operadores.hpp"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
//* operador de referencia
//& operador de dirección

//Paso de parametros por valor copia
void funcionUno(int param){
    param = 34;
    cout<<"Dentro de la función: "<<param<<endl;
}

//Paso de parametros por referencia
void funcionDos(int &param){
    param = 34;
    cout<<"Dentro de la función: "<<param<<endl;
}

//Paso de parametros por apuntador
void funcionTres(int *param){
    *param = 40;
    cout<<"Dentro de la función: "<<*param<<endl;
}

template<class T>
ostream& operator<<(ostream&stream, const vector <T> &valores){
    stream<<"[ ";
    copy(begin(valores),end(valores),ostream_iterator<T>(stream, " "));
    stream<<"]";
    return stream;
}

//Paso de parametro por valor (copia)
void funcionCuatro(vector <int> param){
    param = {1,1};
    cout<<param<<endl;
}

//Paso de parametro por referencia
void funcionCinco(vector <int> &param){
    param = {4,4};
    cout<<param<<endl;
}

//Paso de parametro por apuntador
void funcionSeis(vector <int> *param){
    *param = {3,3};
    cout<<*param<<endl;
}

class ejemplo{
    int valor;
public:
    int getValor() {return this -> valor;}
    void setValor(int valor) {this -> valor = valor;}
    ejemplo(int valor){
        this -> valor = valor;
    }
    ejemplo(){
        this -> valor = 45;
    }
};

int main(){
    int var = 48; //Crea una variable var en el stack con el valor 48
    int varDos = var; //Crea una variavle varDos en el stack con el valor de var
    int * varTres = &var; //Crea un apuntador a int que almacena la dirección del espacio de memoria donde esta var
    int &varCuatro = var;
    
    cout<<"var: "<<var<<'\n';
    cout<<"var direccion: "<<&var<<'\n';
    cout<<"varDos: "<<varDos<<'\n';
    cout<<"varDos de dirección:  "<<&varDos<<'\n';
    cout<<"varTres: "<<*varTres<<'\n';
    cout<<"varTres dirección: "<<varTres<<'\n';
    cout<<"varCuatro: "<<varCuatro<<endl;
    cout<<"varCuatro dirección: "<<&varCuatro<<endl;
    
    cout<<"------------Apuntador---------------"<<endl;
    varTres = &varDos;
    cout<<"varTres: "<<*varTres<<endl;
    cout<<"varTres dirección: "<<varTres<<endl;
    
    cout<<"------------FuncionUno--------------"<<endl;
    cout<<"var: "<<var<<endl;
    funcionUno(var);
    cout<<"var: "<<var<<endl;
    
    cout<<"------------FuncionDos--------------"<<endl;
    cout<<"var: "<<var<<endl;
    funcionDos(var);
    cout<<"var: "<<var<<endl;
    
    cout<<"------------FuncionTres-------------"<<endl;
    cout<<"var: "<<var<<endl;
    funcionTres(&var);
    cout<<"var: "<<var<<endl;
    
    cout<<"------------Vectores----------------"<<endl;
    vector <int> a {5,5}; //Crea un vector a con los valores {5,5}
    vector <int> b {a}; //Crea un vector b con la copia de los valores del vector a {5,5}
    vector <int> *c = nullptr; //Crea un apuntador a vector que apunta a nullptr
    c = &a;
    vector <int> &d = a; //Crea una referencia al vector a
    
    cout<<"a: "<<a<<endl;
    cout<<"a direccion: "<<&a<<endl;
    
    cout<<"b: "<<b<<endl;
    cout<<"b direccion: "<<&b<<endl;
    
    cout<<"c: "<<*c<<endl;
    cout<<"c direccion: "<<c<<endl;
    
    cout<<"d: "<<d<<endl;
    cout<<"d direccion: "<<&d<<endl;
    
    funcionCuatro(a); //valor
    cout<<"a: "<<a<<endl;
    funcionCinco(a); //Referencia
    cout<<"a: "<<a<<endl;
    funcionSeis(&a); //Apuntador
    cout<<"a: "<<a<<endl;
    
    //Stack allocation
    int i = 0;
    int arreglo1 [5];
    vector <string> vec = {"Alan"};
    ejemplo obj1; //Se crea el objeto en el stack llamando ejemplo()
    ejemplo obj2(22); //Se crea el objeto en el stack llamando a ejemplo(int valor)
    
    cout<<obj1.getValor()<<endl;
    cout<<obj2.getValor()<<endl;
    vector <ejemplo> vec2 = {obj1, obj2};
    
    //Heap allocation
    int * arreglo2 = new int [6]; //Arreglo dinamico dentro del heap
    ejemplo * obj3 = new ejemplo(); //Crea objeto en el heap llamando ejemplo()
    ejemplo * obj4 = new ejemplo(97); //Crea objeto en el heap
    
    cout<<obj3 -> getValor()<<endl;
    cout<<obj4 -> getValor()<<endl;
    vector <ejemplo*> vec3 = {obj3, obj4};
    
    //Liberan espacio del heap
    delete [] arreglo2;
    delete obj3;
    return 0;
}
