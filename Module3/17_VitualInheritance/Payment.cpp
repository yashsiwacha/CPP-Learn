#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Abstract base class (interface): defines a contract for all payment types.
// Benefit: callers depend on Payment, not concrete classes (decoupling/extensibility).
class Payment
{
public:
    // Pure virtual function enforces runtime-polymorphic behavior in derived classes.
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() {}
};

// Concrete implementation 1.
class CreditCardPayment : public Payment
{
public:
    void processPayment(double amount) override
    {
        cout << "Processing Credit card payment of $" << amount << endl;
    }
};

// Concrete implementation 2.
class PayPalPayment : public Payment
{
public:
    void processPayment(double amount) override
    {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

int main()
{
    // Store different payment types behind the same Payment interface.
    vector<unique_ptr<Payment>> payments;
    payments.push_back(make_unique<CreditCardPayment>());
    payments.push_back(make_unique<PayPalPayment>());

    // Amounts aligned with each payment object.
    vector<double> amounts = {100.50, 250.75};

    // Runtime polymorphism: the correct override is selected at runtime in this loop.
    for (size_t i = 0; i < payments.size() && i < amounts.size(); ++i)
    {
        cout << "Payment " << i + 1 << ": ";
        payments[i]->processPayment(amounts[i]);
    }

    return 0;
}