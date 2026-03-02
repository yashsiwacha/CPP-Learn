#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
    // Ask user for the input file that contains mixed tokens.
    string inputfile;
    cout << "Enter file name: ";
    getline(cin, inputfile);

    // Open file stream for reading.
    ifstream ifs(inputfile);
    if (!ifs)
    {
        cerr << "Error: could not open file.\n";
        return 1;
    }

    int value;
    while (true)
    {
        ifs >> value;

        // bad() means a serious I/O error (for example, device failure).
        // This state is usually not recoverable, so we stop immediately.
        if (ifs.bad())
        {
            cerr << "Error: unrecoverable stream error.\n";
            break;
        }

        // eof() means we reached the end of file after successful reads.
        // This is a normal termination condition.
        if (ifs.eof())
        {
            break;
        }

        // fail() means formatted extraction failed (e.g., token is not an int).
        // We recover by clearing the fail state and skipping the bad token.
        if (ifs.fail())
        {
            ifs.clear();

            string invalidToken;
            if (ifs >> invalidToken)
            {
                cout << "Skipping invalid token: \"" << invalidToken << "\"\n";
            }
            else
            {
                ifs.clear();
                ifs.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Skipping invalid input segment.\n";
            }
            continue;
        }

        // If stream is good and extraction succeeded, print the integer.
        cout << "Read value: " << value << '\n';
    }

    cout << "Done reading file.\n";
    return 0;
}