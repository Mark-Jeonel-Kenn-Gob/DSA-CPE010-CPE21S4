#include <iostream>
#include <stack>
using namespace std;

void display(stack<string>& pl) {
    while (!pl.empty()) {
        cout << pl.top() << endl;
        pl.pop();
    }
    cout << "Stack is empty" << endl;
}

void pullContinuously(stack<string>& pl) {
    while (!pl.empty()) {
        cout << "Pulling: " << pl.top() << endl;
        pl.pop();
    }
    cout << "Stack is empty. Cannot pull anymore." << endl;
}

int main() {
    stack<string> pl;
    cout << "Push elements into stack:" << endl;
    //Add items to the stack
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    display(pl);
    pullContinuously(pl);

    return 0;
}