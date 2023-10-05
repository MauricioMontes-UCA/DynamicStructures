#include "LinkedListStructures.hpp"

//Insertion functions
void Add(int data){
    //función para ingresar datos al principio de la lista enlazada
    Node *newNode = new Node;

    newNode->element = data;

    if (list == nullptr){
        newNode->next = nullptr;
        list = newNode;
    }
    else{
        newNode->next = list; //dirección del primer elemento de la lista
        list = newNode; //actualización de primer elemento de la lista (no altera a newNode->next)
    }
}

void Append(int data){
    //función para ingresar datos al final de la lista enlazada
    Node *newNode = new Node;
    Node *temp = list;

    newNode->element = data;
    newNode->next = nullptr;

    if (list == nullptr){
        list = newNode;
    }
    else{
        while (temp->next != nullptr){
            temp = temp->next; //al final, temp->next apunta a nullptr
        }
        temp->next = newNode; //ahora, ya no apunta a nullptr, sino que apunta a la dirección de newNode
    }
}

void Index(int data, int position){
    //función para ingresar datos en medio de la lista dada una posición
    Node *newNode = new Node;
    Node *temp = list; //list es el principio de la lista

    newNode->element = data;
    newNode->next = nullptr;


    //el nuevo nodo se introduce al lado del nodo de posición menor para que el nodo esté en la posición 5
    //(si el modo de contar es con el primer elemento siendo 1).
    position--;

    while (position != 1){ //Se usa 1 en vez de 0 para que temp apunte al cuarto elemento, ya que solo
                           //debe desplazarse 3 veces si apunta al elemento con posición 1 en primer lugar.
        temp = temp->next;
        position--;
    }
    newNode->next = temp->next; //al llegar a la posición, el nuevo nodo apunta al siguiente del temporal
    temp->next = newNode; //el siguiente del temporal se sustituye por la dirección de nuevo nodo,
                          //desplazando la ubicación del nodo al que apunta temp
}

void DeleteHead(){
    Node *temp = list; //dos punteros apuntan a la dirección del primer elemento

    if (list != nullptr){ //si la lista no está vacía...
        list = temp->next; //lista apunta al siguiente nodo, de actual posición 2
        delete temp; //se borra la memoria de la dirección a la que apuntaba temp
    }
    else{
        std::cout << "Empty list";
    }
}

void DeleteTail(){ //se requieren de dos punteros auxiliares
    Node *temp = list;
    Node *aux;

    if (list != nullptr){ //si la lista no está vacía...

        if (temp->next != nullptr){ //si el nodo no resulta ser el primero y el último...

            while (temp->next != nullptr){ //itera hasta que sea el último nodo de la lista

                aux = temp; //aux apunta al nodo al que apunta temp...
                temp = temp->next; //para que luego, temp apunte al nodo siguiente
            }
            //Una vez el nodo al que apunta temp sea el último, se desenlaza el nodo
            aux->next = nullptr;
            delete temp;
            temp = nullptr; //i don't get why we use this here...
        }
        else{ //si el nodo resulta ser el único de la lista...
            delete list;
            list = nullptr; //nor here...
        }
    }
    else{
        std::cout << "Empty list";
    }
}