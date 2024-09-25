#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 3; //indicates max size of stack

void display(stack<string>& pl) {
    if (!pl.empty()) {
        cout << pl.top() << endl;
        pl.pop();
    } else {
        cout << "Stack is empty" << endl;
    }
    cout << endl;
}

bool isFull(stack<string>& pl) {
    return pl.size() >= MAX_SIZE;
}

void pushToStack(stack<string>& pl, const string& item) {
    if (!isFull(pl)) {
        pl.push(item);
        cout << "Added: " << item << endl;
    } else {
        cout << "Stack is full. Cannot add: " << item << endl;
    }
}

int main() {
    stack<string> pl;
    cout << "Push elements into stack:" << endl;

    //Add items to the stack
    pushToStack(pl, "C++");
    pushToStack(pl, "Java");
    pushToStack(pl, "Python");
    pushToStack(pl, "JavaScript");

    display(pl);

    return 0;
}