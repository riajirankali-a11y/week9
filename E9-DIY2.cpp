
#include <iostream>
using namespace std;

class Overflow {
};

class Underflow {
};

class Stack {
private:
    int arr[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 2) {
            throw Overflow();
        }

        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    void pop() {
        if (top == -1) {
            throw Underflow();
        }

        cout << arr[top--] << " popped from stack" << endl;
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        s.push(40);
    }
    catch (Overflow &e) {
        cout << "Stack Overflow!" << endl;
    }

    try {
        s.pop();
        s.pop();
        s.pop();

        s.pop();
    }
    catch (Underflow &e) {
        cout << "Stack Underflow!" << endl;
    }

    return 0;
}
