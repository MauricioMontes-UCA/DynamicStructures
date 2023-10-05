#include "StackStructure.hpp"

//Métodos principales: Push() y Pop()
void Push(Node *stack, int data){
    struct Node *temp = new Node;

    temp->element = data;
    temp->next = stack;

    stack = temp;
}

void Pop(Node *stack){
    if (stack != nullptr){
        struct Node *temp = stack;
        stack = temp->next;
        delete temp;
    }
}

void Print(Node *stack){
    struct Node* temp = stack;

    while (temp != nullptr){
        std::cout << temp->element << std::endl;
        temp = temp->next;
    }
}

bool Empty(Node *stack){
    return stack == nullptr;
}

int LastElement(Node *stack){
    if (Empty(stack)){
        return -1;
    }
    else{
        return stack->element;
    }
}