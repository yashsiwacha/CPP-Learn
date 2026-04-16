// Task10RAIIPIMPLNetworkConnection.cpp
// Single-file submission version with clear header/source/main sections.
// Note: In a real project, these sections are separate physical files.

// ===== networkconnection.h (public interface) =====
#include <memory>
#include <string>

class NetworkConnection
{
public:
    explicit NetworkConnection(const std::string &endpoint);
    ~NetworkConnection();

    NetworkConnection(const NetworkConnection &) = delete;
    NetworkConnection &operator=(const NetworkConnection &) = delete;
    NetworkConnection(NetworkConnection &&) noexcept;
    NetworkConnection &operator=(NetworkConnection &&) noexcept;

    bool isConnected() const;
    void sendData(const std::string &data);

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

// ===== networkconnection.cpp (implementation) =====
#include <iostream>
#include <utility>

// Simulated platform-specific/network details are hidden in Impl.
struct NetworkConnection::Impl
{
    std::string endpoint;
    bool connected;

    explicit Impl(const std::string &ep) : endpoint(ep), connected(false)
    {
        // RAII acquire: open connection in constructor.
        connected = true;
        std::cout << "[Impl] Connected to " << endpoint << std::endl;
    }

    ~Impl()
    {
        // RAII release: close connection in destructor.
        if (connected)
        {
            std::cout << "[Impl] Connection to " << endpoint << " closed" << std::endl;
        }
    }

    void sendData(const std::string &data)
    {
        if (!connected)
        {
            std::cerr << "[Impl] Not connected!" << std::endl;
            return;
        }

        std::cout << "[Impl] Sending data to " << endpoint << ": " << data << std::endl;
    }
};

NetworkConnection::NetworkConnection(const std::string &endpoint)
    : impl(std::make_unique<Impl>(endpoint))
{
}

NetworkConnection::~NetworkConnection() = default;

NetworkConnection::NetworkConnection(NetworkConnection &&other) noexcept
    : impl(std::move(other.impl))
{
}

NetworkConnection &NetworkConnection::operator=(NetworkConnection &&other) noexcept
{
    if (this != &other)
    {
        impl = std::move(other.impl);
    }
    return *this;
}

bool NetworkConnection::isConnected() const
{
    return impl && impl->connected;
}

void NetworkConnection::sendData(const std::string &data)
{
    if (!impl)
    {
        std::cerr << "[Impl] Not connected!" << std::endl;
        return;
    }

    impl->sendData(data);
}

// ===== main.cpp (demo) =====
int main()
{
    {
        NetworkConnection conn1("127.0.0.1:8080");
        conn1.sendData("Hello, server!");

        NetworkConnection conn2("192.168.1.5:7000");
        conn2.sendData("Quick check");

        std::cout << "conn1 connected? " << (conn1.isConnected() ? "yes" : "no") << std::endl;
        std::cout << "conn2 connected? " << (conn2.isConnected() ? "yes" : "no") << std::endl;
    } // Connections are closed automatically at scope exit.

    std::cout << "All connections closed (destructor)." << std::endl;
    return 0;
}
