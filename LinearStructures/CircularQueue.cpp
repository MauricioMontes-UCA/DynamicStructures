#include "CircularQueueMethods.hpp"

int main(){
    //Se inicializa "intChar" para poder trabajar con ella como un arreglo circular
    struct CircularQueue intChar;

    //Se declaran los valores de "head" y "tail" para la cola ciruclar
    CreateQueue(&intChar);

    //Ingreso de datos aleatorios, de manera que trabaje con la estructura "Information",
    //anidada a la estructura "CircularQueue"
    Enqueue(&intChar, {5, 'a'});
    Enqueue(&intChar, {93, 'i'});
    Enqueue(&intChar, {29, 'o'});

    //Se borra el primer elemento que entró: {5, 'a'}, por concepto de cola
    Dequeue(&intChar);
    
    //Se ingresa un nuevo elemento, que será el último en la cola
    Enqueue(&intChar, {80, 'u'});

    //Salida de datos
    cout << intChar.info[intChar.head].id << endl;
    cout << intChar.info[intChar.head].character << endl;

    cout << "---------------------------------" << endl;

    cout << intChar.info[intChar.tail].id << endl;
    cout << intChar.info[intChar.tail].character << endl;

    return 0;
}