// Recursive directory traversal program
#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;

// Recursively traverse directory tree
void recursiveDirectoryTraversal(const char *path, int depth = 0)
{
    try
    {
        if (!fs::exists(path))
        {
            cout << "Path does not exist: " << path << "\n";
            return;
        }

        if (!fs::is_directory(path))
        {
            cout << "Not a directory: " << path << "\n";
            return;
        }

        string indent(depth * 2, ' ');

        for (const auto &entry : fs::directory_iterator(path))
        {
            string filename = entry.path().filename().string();

            if (entry.is_directory())
            {
                cout << indent << filename << ":\n";
                recursiveDirectoryTraversal(entry.path().string().c_str(), depth + 1);
            }
            else
                cout << indent << filename << "\n";
        }
    }
    catch (const fs::filesystem_error &e)
    {
        cerr << "Filesystem error: " << e.what() << "\n";
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <directory_path>\n";
        return 1;
    }

    const char *rootPath = argv[1];
    cout << "Directory Structure:\n";
    recursiveDirectoryTraversal(rootPath, 1);
    cout << "\nTraversal complete\n";

    return 0;
}
