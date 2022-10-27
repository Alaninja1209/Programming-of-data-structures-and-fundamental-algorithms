//  Created by Alan Alfredo Onofre Chavez on 25/01/21.

#include "queue.hpp"
#include <string>

int main(){
    Queue <string> * queueUno = new Queue <string> ();
    queueUno -> push("Lulu");
    queueUno -> push("Julian");
    queueUno -> push("Esther");
    queueUno -> push("Ricardo");
    
    queueUno -> imprimirQueue1();
    
    cout<<queueUno -> front() -> getValor()<<endl;
    queueUno -> imprimirQueue1();
    
    cout<<queueUno -> pop() -> getValor()<<endl;
    queueUno -> imprimirQueue1();
    cout<<queueUno -> pop() -> getValor()<<endl;
    
    Nodo <string> * nodo = queueUno -> pop();
    queueUno -> imprimirQueue1();
    cout<<nodo -> getValor()<<endl;
}
