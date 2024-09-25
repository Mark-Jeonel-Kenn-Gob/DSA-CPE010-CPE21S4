#include <iostream>
#include <queue>
using namespace std;

void display(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<string> q;
    cout << "Push elements into queue:" << endl;
    //Add items to the queue
    q.push("C++");
    q.push("Java");
    q.push("Python");

    display(q);

    return 0;
}