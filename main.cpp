#include <iostream>
using namespace std;


class Account {
protected:
    int balance;

public:
    Account(int bal) : balance(bal) {}

    virtual void calculateInterest() = 0; 
    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int bal) : Account(bal) {}

    void calculateInterest() override {
        float rate;
        int time;
        cout << "Enter Interest Rate (as percentage): ";
        cin >> rate;
        cout << "Enter Time (in years): ";
        cin >> time;

        float interest = (balance * rate * time) / 100;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(int bal) : Account(bal) {}

    void calculateInterest() override {
        int fee;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> fee;

        balance -= fee;
        cout << "Balance after fee deduction: " << balance << endl;
    }
};

int main() {
    int accountType, balance;
    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;
    cout << "Enter Balance: ";
    cin >> balance;

    if (accountType == 1) {
        SavingsAccount savings(balance);
        savings.calculateInterest();
    } else if (accountType == 2) {
        CurrentAccount current(balance);
        current.calculateInterest();
    } else {
        cout << "Invalid account type." << endl;
    }

    return 0;
}