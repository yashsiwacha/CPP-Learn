#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class InsufficientFundsException : public runtime_error
{
private:
    string accountNumber;
    double currentBalance;
    double requestedAmount;
    string detailedMessage;

public:
    InsufficientFundsException(const string &account, double balance, double amount)
        : runtime_error("Insufficient funds"),
          accountNumber(account),
          currentBalance(balance),
          requestedAmount(amount)
    {
        ostringstream output;
        output << "InsufficientFundsException: Account " << accountNumber
               << " has balance Rs. " << fixed << setprecision(2) << currentBalance
               << ", but requested Rs. " << requestedAmount << ".";
        detailedMessage = output.str();
    }

    const char *what() const noexcept override
    {
        return detailedMessage.c_str();
    }
};

class InvalidAmountException : public invalid_argument
{
private:
    double amount;
    string operation;
    string detailedMessage;

public:
    InvalidAmountException(double amount, const string &operation)
        : invalid_argument("Invalid amount"), amount(amount), operation(operation)
    {
        ostringstream output;
        output << "InvalidAmountException: Operation '" << this->operation
               << "' received invalid amount: " << fixed << setprecision(2) << this->amount << ".";
        detailedMessage = output.str();
    }

    const char *what() const noexcept override
    {
        return detailedMessage.c_str();
    }
};

class AccountNotFoundException : public out_of_range
{
private:
    string accountNumber;
    string detailedMessage;

public:
    AccountNotFoundException(const string &accountNumber)
        : out_of_range("Account not found"), accountNumber(accountNumber)
    {
        detailedMessage = "AccountNotFoundException: Account '" + this->accountNumber + "' was not found.";
    }

    const char *what() const noexcept override
    {
        return detailedMessage.c_str();
    }
};

class TransactionLimitExceededException : public logic_error
{
private:
    double amount;
    double limit;
    string detailedMessage;

public:
    TransactionLimitExceededException(double amount, double limit)
        : logic_error("Transaction limit exceeded"), amount(amount), limit(limit)
    {
        ostringstream output;
        output << "TransactionLimitExceededException: Attempted Rs. "
               << fixed << setprecision(2) << this->amount
               << ", daily limit is Rs. " << this->limit << ".";
        detailedMessage = output.str();
    }

    const char *what() const noexcept override
    {
        return detailedMessage.c_str();
    }
};

class BankSystemException : public runtime_error
{
private:
    string component;
    string error;
    string detailedMessage;

public:
    BankSystemException(const string &component, const string &error)
        : runtime_error("Bank system error"), component(component), error(error)
    {
        detailedMessage = "BankSystemException: [" + this->component + "] " + this->error;
    }

    const char *what() const noexcept override
    {
        return detailedMessage.c_str();
    }
};

class BankAccount
{
private:
    string accountNumber;
    string holderName;
    double balance;
    double dailyWithdrawalLimit;
    double dailyWithdrawn;

    void validateAmount(double amount, const string &operation) const
    {
        if (amount <= 0.0)
        {
            throw InvalidAmountException(amount, operation);
        }

        if (isnan(amount) || isinf(amount))
        {
            throw invalid_argument("Invalid numeric value for operation: " + operation);
        }
    }

public:
    BankAccount(const string &accountNumber,
                const string &holderName,
                double initialBalance,
                double dailyLimit = 50000.0)
        : accountNumber(accountNumber),
          holderName(holderName),
          balance(initialBalance),
          dailyWithdrawalLimit(dailyLimit),
          dailyWithdrawn(0.0)
    {
        if (this->accountNumber.empty() || this->holderName.empty())
        {
            throw invalid_argument("Account number and holder name cannot be empty.");
        }

        if (initialBalance < 0.0)
        {
            throw InvalidAmountException(initialBalance, "initial balance");
        }

        if (dailyLimit <= 0.0)
        {
            throw invalid_argument("Daily withdrawal limit must be positive.");
        }
    }

    void deposit(double amount)
    {
        validateAmount(amount, "deposit");

        if (amount > 1000000.0)
        {
            throw BankSystemException("Deposit Verification", "Large deposit requires manual verification.");
        }

        balance += amount;
    }

    void withdraw(double amount)
    {
        validateAmount(amount, "withdraw");

        if (amount > balance)
        {
            throw InsufficientFundsException(accountNumber, balance, amount);
        }

        if (dailyWithdrawn + amount > dailyWithdrawalLimit)
        {
            throw TransactionLimitExceededException(dailyWithdrawn + amount, dailyWithdrawalLimit);
        }

        if (amount > 100000.0)
        {
            throw BankSystemException("Fraud Detection", "Large withdrawal flagged for additional verification.");
        }

        balance -= amount;
        dailyWithdrawn += amount;
    }

    void transferTo(BankAccount &recipient, double amount)
    {
        validateAmount(amount, "transfer");

        if (accountNumber == recipient.accountNumber)
        {
            throw logic_error("Self transfer is not allowed.");
        }

        if (amount > balance)
        {
            throw InsufficientFundsException(accountNumber, balance, amount);
        }

        withdraw(amount);
        recipient.deposit(amount);
    }

    string getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }
    double getDailyWithdrawalLimit() const { return dailyWithdrawalLimit; }
    double getDailyWithdrawn() const { return dailyWithdrawn; }

    void printAccountInfo() const
    {
        const double remaining = max(0.0, dailyWithdrawalLimit - dailyWithdrawn);
        cout << "Account Number: " << accountNumber << '\n'
             << "Holder Name: " << holderName << '\n'
             << "Balance: Rs. " << fixed << setprecision(2) << balance << '\n'
             << "Daily Withdrawal Limit: Rs. " << dailyWithdrawalLimit << '\n'
             << "Already Withdrawn Today: Rs. " << dailyWithdrawn << '\n'
             << "Available Withdrawable Amount Today: Rs. " << remaining << "\n\n";
    }
};

BankAccount &findAccountByNumber(vector<BankAccount> &accounts, const string &accountNumber)
{
    for (BankAccount &account : accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            return account;
        }
    }

    throw AccountNotFoundException(accountNumber);
}

void registerAccountOrThrow(const BankAccount &account, unordered_set<string> &registry)
{
    const auto insertion = registry.insert(account.getAccountNumber());
    if (!insertion.second)
    {
        throw logic_error("Duplicate account creation attempted for account: " + account.getAccountNumber());
    }
}

void executeScenario(const string &title, const function<void()> &scenario)
{
    cout << "---- " << title << " ----\n";

    try
    {
        scenario();
        cout << "Scenario completed successfully.\n\n";
    }
    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << "\n\n";
    }
    catch (const InvalidAmountException &e)
    {
        cout << e.what() << "\n\n";
    }
    catch (const AccountNotFoundException &e)
    {
        cout << e.what() << "\n\n";
    }
    catch (const TransactionLimitExceededException &e)
    {
        cout << e.what() << "\n\n";
    }
    catch (const BankSystemException &e)
    {
        cout << e.what() << "\n\n";
    }
    catch (const out_of_range &e)
    {
        cout << "std::out_of_range: " << e.what() << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cout << "std::invalid_argument: " << e.what() << "\n\n";
    }
    catch (const logic_error &e)
    {
        cout << "std::logic_error: " << e.what() << "\n\n";
    }
    catch (const runtime_error &e)
    {
        cout << "std::runtime_error: " << e.what() << "\n\n";
    }
    catch (const exception &e)
    {
        cout << "std::exception: " << e.what() << "\n\n";
    }
    catch (...)
    {
        cout << "Unknown non-standard exception caught.\n\n";
    }
}

int main()
{
    cout << "========================================\n";
    cout << "Bank System - Custom Exception Handling\n";
    cout << "========================================\n\n";

    executeScenario("1) Successful operations (deposit, withdraw, transfer)", []()
                    {
						BankAccount accountA("ACC1001", "Yash", 120000.0);
						BankAccount accountB("ACC1002", "Aarav", 45000.0);

						accountA.deposit(10000.0);
						accountA.withdraw(20000.0);
						accountA.transferTo(accountB, 15000.0);

						accountA.printAccountInfo();
						accountB.printAccountInfo(); });

    executeScenario("2) Duplicate account creation (logic_error)", []()
                    {
						unordered_set<string> registry;
						BankAccount first("ACC2001", "Riya", 1000.0);
						BankAccount duplicate("ACC2001", "Riya Duplicate", 1500.0);

						registerAccountOrThrow(first, registry);
						registerAccountOrThrow(duplicate, registry); });

    executeScenario("3) Insufficient funds (InsufficientFundsException)", []()
                    {
						BankAccount account("ACC3001", "Mohan", 2000.0);
						account.withdraw(5000.0); });

    executeScenario("4) Invalid amount (InvalidAmountException)", []()
                    {
						BankAccount account("ACC4001", "Siya", 5000.0);
						account.deposit(-100.0); });

    executeScenario("5) Account not found (AccountNotFoundException)", []()
                    {
						vector<BankAccount> accounts;
						accounts.emplace_back("ACC5001", "Kabir", 7000.0);
						(void)findAccountByNumber(accounts, "ACC9999"); });

    executeScenario("6) Transaction limit exceeded (TransactionLimitExceededException)", []()
                    {
						BankAccount account("ACC6001", "Anaya", 100000.0);
						account.withdraw(30000.0);
						account.withdraw(25000.0); });

    executeScenario("7) System errors (BankSystemException for large transactions)", []()
                    {
						BankAccount account("ACC7001", "Arjun", 2000000.0);
						account.deposit(1500000.0); });

    executeScenario("8) Generic unknown exception (catch-all scenario)", []()
                    { throw 404; });

    cout << "All scenarios demonstrated.\n";
    return 0;
}
