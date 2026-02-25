#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename;

    // Read target filename from user.
    std::cout << "Enter the file name: ";
    std::getline(std::cin, filename);

    // Collect multi-line text (type END on a new line to stop).
    std::cout << "Enter text to save (type END on a new line to finish):" << std::endl;
    std::string textToSave;
    std::string line;
    while (true)
    {
        std::getline(std::cin, line);
        if (line == "END")
        {
            break;
        }
        textToSave += line + '\n';
    }

    std::cout << "\nWriting to file..." << std::endl;

    // std::ofstream opens file for writing.
    std::ofstream outputfile(filename);
    if (!outputfile)
    {
        std::cout << "Error in opening file." << std::endl;
        return 1;
    }
    outputfile << textToSave;
    outputfile.close();

    std::cout << "Reading from file..." << std::endl;

    // std::ifstream opens file for reading.
    std::ifstream inputfile(filename);
    if (!inputfile)
    {
        std::cout << "Error in opening file." << std::endl;
        return 1;
    }

    std::cout << "\nFile contents:" << std::endl;
    while (std::getline(inputfile, line))
    {
        std::cout << line << std::endl;
    }

    return 0;
}