// Task1RAIIBasics_FileWrapper.cpp
// Demonstrates RAII for file handling: resource is acquired in constructor and released in destructor.
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

class FileWrapper
{
    std::ofstream file;

public:
    FileWrapper(const std::string &filename)
    {
        file.open(filename);
        if (!file)
            throw std::runtime_error("Failed to open file");
        std::cout << "File opened: " << filename << "\n"; // Notify when the file is opened
    }
    ~FileWrapper()
    {
        if (file.is_open())
        {
            file.close();
            std::cout << "File closed automatically.\n"; // Notify when the file is closed
        }
    }
    std::ofstream &get() { return file; }
    // Write a line to the file. This avoids exposing the internal ofstream.
    void writeLine(const std::string &line)
    {
        if (!file)
            throw std::runtime_error("File not open for writing");
        file << line << std::endl;
    }
};

int main()
{
    try
    {
        FileWrapper fw("example.txt");
        fw.writeLine("First line.");
        fw.writeLine("Second line.");
        // Simulate an error to test exception safety:
        throw std::runtime_error("Simulated crash!");
        fw.get() << "Third line." << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    std::cout << "Back in main, after FileWrapper goes out of scope.\n";
    return 0;
}