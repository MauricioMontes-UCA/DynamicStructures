#include <iostream>

struct Node{
    int element;
    struct Node *next;
};

struct Node *stack = nullptr;