#include "StackStructure.hpp"

//Métodos principales: Push() y Pop()
void Push(int data){
    struct Node *temp = new Node;

    temp->element = data;
    temp->next = stack;

    stack = temp;
}

void Pop(){
    if (stack != nullptr){
        struct Node *temp = stack;
        stack = temp->next;
        delete temp;
    }
}

void Print(){
    struct Node* temp = stack;

    while (temp != nullptr){
        std::cout << temp->element << std::endl;
        temp = temp->next;
    }
}

bool Empty(){
    return stack == nullptr;
}

int LastElement(){
    if (Empty()){
        return -1;
    }
    else{
        return stack->element;
    }
}