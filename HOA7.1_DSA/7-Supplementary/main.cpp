#include <iostream>
#include <cstdlib> //For rand() and srand()
#include <ctime>   //For time()

//Function to perform Bubble Sort
void bubbleSort(int arr[], const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Function to count votes and determine the winning candidate
void countVotes(int votes[], const int size, const std::string candidates[]) {
    int voteCount[5] = {0}; //Array to count votes for candidates 1 to 5

    //Count votes
    for (int i = 0; i < size; i++) {
        if (votes[i] >= 1 && votes[i] <= 5) {
            voteCount[votes[i] - 1]++;
        }
    }

    //Find the winning candidate
    int maxVotes = 0;
    int winningCandidate = -1;
    for (int i = 0; i < 5; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winningCandidate = i; //Candidate numbers are 0 to 4
        }
    }

    //Print results
    std::cout << "Vote counts:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << " (" << candidates[i] << "): " << voteCount[i] << " votes\n";
    }
    std::cout << "Winning Candidate: " << candidates[winningCandidate] << " with " << maxVotes << " votes\n";
}

int main() {
    const int size = 100;
    int votes[size];

    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    //Generate random votes between 1 and 5
    for (int i = 0; i < size; i++) {
        votes[i] = rand() % 5 + 1; //Random number between 1 and 5
    }

    //Candidate names
    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    //Sort the votes using Bubble Sort
    bubbleSort(votes, size);

    //Count votes and determine the winning candidate
    countVotes(votes, size, candidates);

    return 0;
}