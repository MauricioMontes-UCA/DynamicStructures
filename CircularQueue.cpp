#include "CircularQueueMethods.hpp"

int main(){
    struct Node newNode;

    CreateQueue(&newNode);

    Push(&newNode, {5, 'a'});
    Push(&newNode, {93, 'i'});
    Push(&newNode, {29, 'o'});

    Pop(&newNode);
    
    Push(&newNode, {80, 'u'});

    cout << newNode.info[newNode.head].id << endl;
    cout << newNode.info[newNode.head].character << endl;

    cout << "---------------------------------" << endl;

    cout << newNode.info[newNode.tail].id << endl;
    cout << newNode.info[newNode.tail].character << endl;

    return 0;
}