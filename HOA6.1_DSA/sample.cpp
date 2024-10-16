#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function

const int max_size = 50; //define the capacity of data elements in our dataset

int main() {
    //generate random values
    int dataset[max_size];
    srand(time(0)); //seed the random number generator
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand(); //generate random integers
    }

    //show your dataset's content
    std::cout << "Dataset contents: ";
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}