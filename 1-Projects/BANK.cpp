#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Account
{
private:
    string accountNumber;
    string name;
    double balance;
    int pin;
    vector<string> transactions;

public:
    Account() {}

    Account(string accNo, string n, int p)
    {
        accountNumber = accNo;
        name = n;
        pin = p;
        balance = 0.0;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }

    int getPin() const
    {
        return pin;
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        transactions.push_back("Deposited: " + to_string(amount));
        cout << "Amount deposited successfully.\n";
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        transactions.push_back("Withdrawn: " + to_string(amount));
        cout << "Amount withdrawn successfully.\n";
        return true;
    }

    void showTransactions() const
    {
        cout << "\nTransaction History:\n";
        for (const auto &t : transactions)
        {
            cout << t << endl;
        }
    }

    void showDetails() const
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    string serialize() const
    {
        string data = accountNumber + "," + name + "," +
                      to_string(pin) + "," + to_string(balance);
        return data;
    }

    void setBalance(double b)
    {
        balance = b;
    }
};

class Bank
{
private:
    unordered_map<string, Account> accounts;

public:
    void loadFromFile()
    {
        ifstream file("accounts.txt");
        if (!file)
            return;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string accNo, name, pinStr, balStr;

            getline(ss, accNo, ',');
            getline(ss, name, ',');
            getline(ss, pinStr, ',');
            getline(ss, balStr, ',');

            Account acc(accNo, name, stoi(pinStr));
            acc.setBalance(stod(balStr));
            accounts[accNo] = acc;
        }
        file.close();
    }

    void saveToFile()
    {
        ofstream file("accounts.txt");
        for (auto &pair : accounts)
        {
            file << pair.second.serialize() << endl;
        }
        file.close();
    }

    void createAccount()
    {
        string accNo, name;
        int pin;

        cout << "Enter Account Number: ";
        cin >> accNo;

        if (accounts.find(accNo) != accounts.end())
        {
            cout << "Account already exists!\n";
            return;
        }

        cout << "Enter Name: ";
        cin >> name;

        cout << "Set 4-digit PIN: ";
        cin >> pin;

        accounts[accNo] = Account(accNo, name, pin);
        saveToFile();

        cout << "Account created successfully!\n";
    }

    void login()
    {
        string accNo;
        int enteredPin;

        cout << "Enter Account Number: ";
        cin >> accNo;

        if (accounts.find(accNo) == accounts.end())
        {
            cout << "Account not found!\n";
            return;
        }

        int attempts = 3;
        while (attempts--)
        {
            cout << "Enter PIN: ";
            cin >> enteredPin;

            if (enteredPin == accounts[accNo].getPin())
            {
                cout << "Login successful!\n";
                accountMenu(accounts[accNo]);
                return;
            }
            else
            {
                cout << "Wrong PIN! Attempts left: " << attempts << endl;
            }
        }

        cout << "Too many failed attempts.\n";
    }

    void accountMenu(Account &acc)
    {
        int choice;
        do
        {
            cout << "\n1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Check Balance\n";
            cout << "4. Transaction History\n";
            cout << "5. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            double amount;

            switch (choice)
            {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                acc.deposit(amount);
                saveToFile();
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                if (acc.withdraw(amount))
                    saveToFile();
                break;

            case 3:
                cout << "Current Balance: " << acc.getBalance() << endl;
                break;

            case 4:
                acc.showTransactions();
                break;

            case 5:
                cout << "Logged out.\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 5);
    }
};

int main()
{
    Bank bank;
    bank.loadFromFile();

    int choice;
    do
    {
        cout << "\n===== MINI BANKING SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.login();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}