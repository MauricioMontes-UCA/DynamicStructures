#include <iostream>
using namespace std;

struct Information{
    int id;
    char character;
};

#define size 3

struct CircularQueue{
    int head;
    int tail;
    Information info[size];
};