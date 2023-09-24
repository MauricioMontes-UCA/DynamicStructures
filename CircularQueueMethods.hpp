#include "CircularQueueStructures.hpp"


void CreateQueue(CircularQueue *temp){
    //Inicializa head y tail con -1
    temp->head = -1;
    temp->tail = -1;
}

bool IsEmpty(CircularQueue *temp){
    //Verifica si el nodo está vacío
    if (temp->head == -1){
        return true; //Indeed, it is empty
    }
    else{
        return false; //It is not
    }
}

int CountElements(CircularQueue *temp){
    if(IsEmpty(temp)){
        return 0;
    }
    else{
        if(temp->head <= temp->tail){
            return temp->tail - temp->head + 1; // n - m + 1
        }
        else{
            return size - temp->tail - temp->head + 1; // size - (n - m + 1)
        }
    }
}

bool IsFull(CircularQueue *temp){
    if(CountElements(temp) == size){
        return true;
    }
    else{
        return false;
    }
}

void Push(CircularQueue *temp, Information data){
    if (!IsFull(temp)){
        if (IsEmpty(temp)){
            temp->head = 0;
        }

        if (temp->tail == size - 1){
            temp->tail = 0;
        }
        else{
            temp->tail++;
        }

        temp->info[temp->tail].character = data.character;
        temp->info[temp->tail].id = data.id;
    }
    else{
        cout << "Full queue" << endl;
    }
}

void Pop(CircularQueue *temp){
    if (!IsEmpty(temp)){
        if (CountElements(temp) == 1){
            CreateQueue(temp);
        }
        else{
            temp->head++;
        }
    }
    else{
        cout << "Empty queue" << endl;
    }
}