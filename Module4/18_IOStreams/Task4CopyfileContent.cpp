#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Step 1: Read source file name from user.
    // Source file path (file to read).
    string inputfile;
    cout << "Enter the input file name: " << endl;
    getline(cin, inputfile);

    // Open source file using ifstream (input/read stream).
    ifstream inputstream(inputfile);
    if (!inputstream)
    {
        cout << "Error: could not open input file '" << inputfile << "'" << endl;
        return 1;
    }

    // Step 2: Read destination file name from user.
    // Destination file path (file to write).
    string outputfile;
    cout << "Enter the output file name: " << endl;
    getline(cin, outputfile);

    // Open/create destination file using ofstream (output/write stream).
    ofstream outputstream(outputfile);
    if (!outputstream)
    {
        cout << "Error: could not open output file '" << outputfile << "'" << endl;
        return 1;
    }

    cout << "Copying from '" << inputfile << "' to '" << outputfile << "'..." << endl;

    // Step 3: Copy all text from source to destination.
    string line;
    // getline reads one full line at a time (without '\n').
    // We write that line, then add '\n' so original line breaks are preserved.
    while (getline(inputstream, line))
    {
        outputstream << line << '\n';
    }

    // Close write stream before reopening the same file for reading.
    outputstream.close();

    // Step 4: Reopen destination file and display copied result.
    ifstream print(outputfile);
    if (!print)
    {
        cout << "Error: could not open output file '" << outputfile << "' for reading" << endl;
        return 1;
    }

    cout << "Copied content:" << endl;
    while (getline(print, line))
    {
        cout << line << '\n';
    }

    return 0;
}
