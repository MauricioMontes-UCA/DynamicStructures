#include <iostream>

struct Node{
    int element;
    Node *next;
};

Node *circularList = nullptr; //circularList marca el "comienzo" de la lista circular

void InsertarInicio (int elemento){
    Node *nuevoNodo = new Node;
    Node *temp;

    nuevoNodo->element = elemento;

    if (circularList == nullptr){
        circularList = nuevoNodo;
        circularList->next = circularList;
        temp = nuevoNodo;
    }
}

void InsertarFinal (int elemento){
    Node *nuevoNodo = new Node; 
    Node *temp; //temporal marca al "final" de la lista

    nuevoNodo->element = elemento;

    if (circularList == nullptr){
        circularList = nuevoNodo;
        //por circularidad
        circularList->next = circularList; //el siguiente de la lista es el mismo nodo, pues es una lista circular
        temp = circularList; //el último elemento es igual al primer nodo
    }
    else{
        temp->next = nuevoNodo; //el último nodo apunta al nuevo nodo
        nuevoNodo->next = circularList; //el nuevo nodo apunta al siguiente nodo, por circularidad, al primero
        temp = nuevoNodo; //se actualiza cuál es el "último elemento" de la lista
    }
}

void InsertarEnMedio (int elemento, int posicion){

    Node *nuevoNodo = new Node;
    Node *temp = circularList;

    nuevoNodo->element = elemento;
    nuevoNodo->next = nullptr;

    //Al ingresarse en medio de los elementos que conectan por circularidad... realmente no hay que tomar en cuenta
    //la circularidad para esto.
    //Es el mismo proceso que con una lista enlazada normal

    posicion--;

    while(posicion != 1){
        temp = temp->next;
        posicion--;
    }
    nuevoNodo->next = temp->next;
    temp->next = nuevoNodo;
}

void BorrarEnMedio (int posicion){
    Node *temp = circularList;
    Node *aux;

    while (posicion != 1){
        aux = temp; //aux será el nodo anterior al que se va a borrar
        temp = temp->next; //temp es el elemento que será enviado a la dimension sombra
        posicion--;
    }
    aux->next = temp->next; //se conecta el nodo anterior con el siguiente del que se va a eliminar
    delete temp; //got shunned lol
}

void BorrarInicio(){
    Node *temp = circularList;

    if (circularList != nullptr){
        while(temp->next != circularList){ //ya no es a nullptr, sino que, como el último elemento apunta al primero que es "circularList"
            temp = temp->next;
        }

        temp->next = circularList->next; //el último elemento apunta ahora al elemento siguiente del primero
        delete circularList; //borras el primer elemento de la lista
        circularList = temp->next; //recuperamos el primer nodo como al que apunta el siguiente del último elemento, por circularidad
    }
    else if (circularList->next == circularList){ //si solo hay un nodo
        delete circularList;
        circularList = nullptr;
    }
    else{
        std::cout << "Empty list.";
    }
}

void BorrarFinal(){
    Node *temp = circularList;
    Node *aux;

    if (circularList != nullptr){
        while(temp->next != circularList){
            aux = temp;
            temp = temp->next;
        }
        aux->next = circularList; //Como temp->next es igual a circularList, el penúltimo apunta al principio
        delete temp; //got shunned lol
    }
    else if (circularList->next == circularList){
        delete circularList;
        circularList = nullptr;
    }
    else{
        std::cout << "Empty list.";
    }
}