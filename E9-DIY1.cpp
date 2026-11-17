
#include <iostream>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance! Withdrawal not allowed.";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    double amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        account.withdraw(amount);
    }
    catch (InsufficientFunds &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
