
#include <iostream>
using namespace std;

class MathError {
};

class DivideByZero : public MathError {
};

int main() {
    try {
        throw DivideByZero();
    }
    catch (MathError &e) {
        cout << "MathError caught!" << endl;
    }
    catch (DivideByZero &e) {
        cout << "DivideByZero caught!" << endl;
    }

    return 0;
}
