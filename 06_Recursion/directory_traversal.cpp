// Recursive directory traversal program - lists all files and folders
#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

namespace fs = std::filesystem;

// Recursively traverses directory tree, printing folders and files
// depth parameter tracks how deep we are in the directory structure
void recursiveDirectoryTraversal(const char *path, int depth = 0)
{
    try
    {
        // Check if path exists
        if (!fs::exists(path))
        {
            cout << "Path does not exist: " << path << endl;
            return;
        }

        // Verify it's a directory
        if (!fs::is_directory(path))
        {
            cout << "Path is not a directory: " << path << endl;
            return;
        }

        // Create indentation based on depth for visual hierarchy
        string indent = "";
        for (int i = 0; i < depth; i++)
        {
            indent += "  ";
        }

        // Iterate through all entries in current directory
        for (const auto &entry : fs::directory_iterator(path))
        {
            string filename = entry.path().filename().string();

            if (entry.is_directory())
            {
                cout << indent << filename << ":" << endl;

                // Recursive call: explore subdirectory with increased depth
                recursiveDirectoryTraversal(entry.path().string().c_str(), depth + 1);
            }
            else
            {
                // Print file name
                cout << indent << filename << endl;
            }
        }
    }
    catch (const fs::filesystem_error &e)
    {
        cerr << "Filesystem error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <directory_path>" << endl;
        cout << "Example: " << argv[0] << " C:\\Users\\YourName\\Documents" << endl;
        cout << "\nNote: Provide a valid directory path as an argument." << endl;
        return 1;
    }

    const char *rootPath = argv[1];

    cout << "========================================" << endl;
    cout << "Directory Structure:" << endl;
    cout << "========================================" << endl;
    cout << "Root:" << endl;

    recursiveDirectoryTraversal(rootPath, 1);

    cout << "========================================" << endl;
    cout << "Traversal Complete!" << endl;

    return 0;
}
