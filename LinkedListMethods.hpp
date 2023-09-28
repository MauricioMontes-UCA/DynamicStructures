#include "LinkedListStructures.hpp"

//Insertion functions
void add(int data){
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

void append(int data){
    //función para ingresar datos al final de la lista enlazada
    Node *newNode = new Node;
    Node *temp = list;

    newNode->element = data;

    if (list == nullptr){
        newNode->next = nullptr;
        list = newNode;
    }
    else{
        while (temp->next != nullptr){
            temp = temp->next; //al final, temp->next apunta a nullptr
        }
        temp->next = newNode; //ahora, ya no apunta a nullptr, sino que apunta a la dirección de newNode
    }
}

void index(int data, int position){
    //This shit needs to be updated
}
