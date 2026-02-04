#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Abstract Class
class Payment
{
public:
    // Virtual Function and destrutor
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() {}
};

// Inherting the Payment class in CreditCardPayment Class
class CreditCardPayment : public Payment
{
public:
    // Overriding the processPayment Function
    void processPayment(double amount) override
    {
        cout << "Processing Credit card payment of $" << amount << endl;
    }
};

// Inheriting the Payment Class in PayPalPayment Class.
class PayPalPayment : public Payment
{
public:
    // Overriding the processPayment Function
    void processPayment(double amount) override
    {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

int main()
{
    // Using vector to store the pointers
    vector<unique_ptr<Payment>> payments; // Using smart pointer to prevent memory leak
    // Pushing the Pointer to Vector
    payments.push_back(make_unique<CreditCardPayment>());
    payments.push_back(make_unique<PayPalPayment>());

    // Process payments
    payments[0]->processPayment(100.50);
    payments[1]->processPayment(250.75);

    return 0;
}