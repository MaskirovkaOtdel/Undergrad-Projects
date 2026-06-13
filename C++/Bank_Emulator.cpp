#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif

class Balance {
private:
    double current_balance;
public:
    Balance() : current_balance(0.0) {}

    double getBalance() const {
        return current_balance;
    }

    void updateBalance(double amount) {
        current_balance += amount;
    }
};

class DepositWithdraw {
public:
    static bool validateAmount(const std::string& amountStr) {
        std::regex pattern(R"(^\d+(\.\d{1,2})?$)");
        if (std::regex_match(amountStr, pattern)) {
            try {
                double amount = std::stod(amountStr);
                return amount > 0;
            } catch (...) {
                return false;
            }
        }
        return false;
    }
};

class BankAccount {
private:
    std::string owner;
    Balance balance;
    std::vector<std::string> transactions;

public:
    BankAccount(const std::string& ownerName) : owner(ownerName) {}

    void deposit(const std::string& amountStr) {
        if (DepositWithdraw::validateAmount(amountStr)) {
            double amount = std::stod(amountStr);
            balance.updateBalance(amount);
            transactions.push_back("Deposit: €" + formatAmount(amount));
            std::cout << "Deposit successful: €" << formatAmount(amount) << std::endl;
        } else {
            std::cout << "Invalid deposit amount. Please enter a valid euro amount." << std::endl;
        }
    }

    void withdraw(const std::string& amountStr) {
        if (DepositWithdraw::validateAmount(amountStr)) {
            double amount = std::stod(amountStr);
            if (balance.getBalance() >= amount) {
                balance.updateBalance(-amount);
                transactions.push_back("Withdrawal: €" + formatAmount(amount));
                std::cout << "Withdrawal successful: €" << formatAmount(amount) << std::endl;
            } else {
                std::cout << "Insufficient funds for this withdrawal." << std::endl;
            }
        } else {
            std::cout << "Invalid withdrawal amount. Please enter a valid euro amount." << std::endl;
        }
    }

    void showTransactions() const {
        std::cout << "\nTransaction history for " << owner << ":" << std::endl;
        if (transactions.empty()) {
            std::cout << "No transactions yet." << std::endl;
        } else {
            for (const auto& t : transactions) {
                std::cout << t << std::endl;
            }
        }
        std::cout << "Current balance: €" << formatAmount(balance.getBalance()) << std::endl << std::endl;
    }

private:
    std::string formatAmount(double amount) const {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << amount;
        return stream.str();
    }
};

int main() {
#ifdef _WIN32
    
    SetConsoleOutputCP(CP_UTF8);
#endif
    std::locale::global(std::locale(""));  

    std::string name;
    std::cout << "Enter account owner name: ";
    std::getline(std::cin, name);

    BankAccount account(name);

    while (true) {
        std::cout << "Choose an option:\n1. Deposit\n2. Withdraw\n3. Show Transactions\n4. Exit\n> ";
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::cout << "Enter deposit amount in euros: ";
            std::string amount;
            std::getline(std::cin, amount);
            account.deposit(amount);
        } else if (choice == "2") {
            std::cout << "Enter withdrawal amount in euros: ";
            std::string amount;
            std::getline(std::cin, amount);
            account.withdraw(amount);
        } else if (choice == "3") {
            account.showTransactions();
        } else if (choice == "4") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
