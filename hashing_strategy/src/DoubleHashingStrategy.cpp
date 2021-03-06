//
// Created by saso on 30/01/2022.
//

#include <vector>
#include <iostream>
#include "../include//DoubleHashingStrategy.h"

template
class DoubleHashingStrategy<int>;

template<typename T>
DoubleHashingStrategy<T>::DoubleHashingStrategy(int tableSize) : HashingStrategy<T>(tableSize) {
    setSieve();
}

template<typename T>
void DoubleHashingStrategy<T>::setSieve() {
    // Create a boolean array "prime[0..tableSize-1]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    std::vector<bool> prime(this->tableSize - 1, true);

    for (int p = 2; p * p <= this->tableSize; p++) {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p]) {
            for (int i = p * p; i <= prime.size(); i += p)
                prime[i] = false;
        }
    }

    for (int i = prime.size(); i >= 2; i--)
        if (prime[i]) {
            primeNumber = i;
            std::cout << "Max prime number: " << primeNumber << std::endl;
            break;
        }
}


template<typename T>
int DoubleHashingStrategy<T>::hashCode(T key) {
    return firstHashCode(key);
}

template<typename T>
int DoubleHashingStrategy<T>::firstHashCode(T key) {
    return (key % this->tableSize);
}

template<typename T>
int DoubleHashingStrategy<T>::rehash(T key, int iterationNo) {
    return (firstHashCode(key) + iterationNo * secondHashCode(key)) % this->tableSize;
}

template<typename T>
int DoubleHashingStrategy<T>::secondHashCode(T key) {
    return primeNumber - (key % primeNumber);
}




