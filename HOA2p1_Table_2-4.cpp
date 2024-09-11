#include <iostream>
#include <string>
#include <memory>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    // Constructor
    Student(std::string newName = "John Doe", int newAge = 18)
        : studentName(std::move(newName)), studentAge(newAge) {
        std::cout << "Constructor Called." << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    // Copy Constructor
    Student(const Student &copyStudent)
        : studentName(copyStudent.studentName), studentAge(copyStudent.studentAge) {
        std::cout << "Copy Constructor Called." << std::endl;
    }

    // Copy Assignment Operator
    Student& operator=(const Student &copyStudent) {
        if (this == &copyStudent) return *this; // self-assignment check
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
        std::cout << "Copy Assignment Operator Called." << std::endl;
        return *this;
    }

    // Display Attributes
    void printDetails() const {
        std::cout << studentName << " " << studentAge << std::endl;
    }
};

int main() {
    const size_t j = 5;

    Student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for (size_t i = 0; i < j; i++) { // loop A
        std::unique_ptr<Student> ptr = std::make_unique<Student>(namesList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    for (size_t i = 0; i < j; i++) { // loop B
        studentList[i].printDetails();
    }

    return 0;
}
