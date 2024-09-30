/* 
Gob, Mark Jeonel Kenn E. Gob / CPE21S4 / OOP2
Sept. 30, 2024

Expected output
10 pushed into stack
20 pushed into stack
30 pushed into stack
30 popped from the stack
Stack elements are
20 10
*/

#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 3;

/*void display(stack<string>& pl) {
    if (!pl.empty()) {
        cout << pl.top() << " pushed into stack" << endl;
        pl.pop();
    } else {
        cout << "stack is empty" << endl;
    }
    cout << endl;
}*/

bool Full(stack<string>& pl) {
    return pl.size() >= MAX_SIZE;
}

void pushToStack(stack<string>& pl, const string& item) {
    if (!Full(pl)) {
        pl.push(item);
        cout << item << " pushed into stack" << endl;
    } else {
        cout << "full" << endl;
    }
}

void popFromStack(stack<string>& pl, const string& item) {
    if (!Full(pl)) {
        pl.push(item);
        cout << item << " pushed into stack" << endl;
    } else {
        cout << item << " popped from the stack" << endl;
        pl.pop();
    }
}


int main() {
    stack<string> pl;
    cout << "Expected output" << endl;
    pushToStack(pl, "10");
    pushToStack(pl, "20");
    pushToStack(pl, "30");
    popFromStack(pl, "30");
    
    cout << "Stack elements are " << endl << "20 10" << endl;

    return 0;
}
