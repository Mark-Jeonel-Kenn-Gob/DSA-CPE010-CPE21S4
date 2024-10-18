#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const int arraySize = 100;
    int randomArray[arraySize];

    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    //Generate random numbers & store in the array
    for (int i = 0; i < arraySize; ++i) {
        randomArray[i] = rand() % 100; //Generate random number between 0 and 99
    }

    //Print array
    for (int i = 0; i < arraySize; ++i) {
        std::cout << randomArray[i] << " ";
    }

    return 0;
}