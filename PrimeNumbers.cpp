//Yeah, we are brute forcing the number of primes using a silly program in a silly computer
#include "StackMethods.hpp"
#include <cmath>

bool Comparison(Node *, int);

int main(){
    int range;
    Node *primeNumbers = nullptr;

    Push(primeNumbers, 2);

    std::cout << "Enter the range in which you yant to find the prime numbers:";
    std::cin >> range;

    int givenNumbers[range];

    int iterations = range-3;

    for (int i = 0; i < iterations; i++){
        givenNumbers[i] = i+3; //Para empezar a contar desde 3
    }

    for (int i = 0; i < iterations; i++){
        if(Comparison(primeNumbers, givenNumbers[i])){
            Push(primeNumbers, givenNumbers[i]);
        }
    }

    Print(primeNumbers);
}

bool Comparison(Node *stack, int number){
    Node *temp = stack;
    while (temp->next != nullptr){
        if (temp->element <= sqrt(number)){
            return true;
        }
        else{
            temp = temp->next;
        }
    }
    return false;
}