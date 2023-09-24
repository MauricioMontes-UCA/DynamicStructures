#include "CircularQueueMethods.hpp"

int main(){
    struct CircularQueue intChar;

    CreateQueue(&intChar);

    Push(&intChar, {5, 'a'});
    Push(&intChar, {93, 'i'});
    Push(&intChar, {29, 'o'});

    Pop(&intChar);
    
    Push(&intChar, {80, 'u'});

    cout << intChar.info[intChar.head].id << endl;
    cout << intChar.info[intChar.head].character << endl;

    cout << "---------------------------------" << endl;

    cout << intChar.info[intChar.tail].id << endl;
    cout << intChar.info[intChar.tail].character << endl;

    return 0;
}