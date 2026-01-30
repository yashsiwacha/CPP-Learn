#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

namespace fs = std::filesystem;

/**
 * RECURSIVE FUNCTION: recursiveDirectoryTraversal()
 * 
 * Purpose: Traverses a directory tree recursively, printing all folders and files
 * 
 * How Recursion Works Here:
 * 1. The function explores the current directory
 * 2. When it finds a subdirectory, it CALLS ITSELF with that subdirectory path
 * 3. This creates a "call stack" - each nested folder gets its own function call
 * 4. After exploring a subdirectory completely, control returns to the parent call
 * 5. This continues until all directories and files are explored
 * 
 * Parameters:
 * @param path: Character pointer to the directory path to traverse
 * @param depth: Current depth level in the directory tree (0 = root, 1 = first level, etc.)
 *               Used to calculate proper indentation for visual hierarchy
 */
void recursiveDirectoryTraversal(const char* path, int depth = 0) {
    try {
        // Validate that the path exists on the file system
        if (!fs::exists(path)) {
            cout << "Path does not exist: " << path << endl;
            return;  // Exit this recursive call
        }

        // Validate that the path is actually a directory, not a file
        if (!fs::is_directory(path)) {
            cout << "Path is not a directory: " << path << endl;
            return;  // Exit this recursive call
        }

        // Create indentation string based on current depth
        // Each level gets 2 spaces for better visual hierarchy
        string indent = "";
        for (int i = 0; i < depth; i++) {
            indent += "  ";  // Using 2 spaces per depth level
        }

        // Iterate through all entries (files and folders) in the current directory
        for (const auto& entry : fs::directory_iterator(path)) {
            // Extract just the filename/folder name (without full path)
            string filename = entry.path().filename().string();

            if (entry.is_directory()) {
                // FOLDER FOUND: Print with colon and proper indentation
                cout << indent << filename << ":" << endl;
                
                // RECURSIVE CALL: Explore this subdirectory by calling this function again
                // Pass increased depth (depth + 1) to indent nested items further
                // This is where the "recursion" happens - the function calls itself!
                recursiveDirectoryTraversal(entry.path().string().c_str(), depth + 1);
                
                // After the recursive call returns, execution continues here
                // Moving to the next item in the current directory
            } else {
                // FILE FOUND: Print with proper indentation (no colon)
                cout << indent << filename << endl;
            }
        }
        
        // When loop completes, this recursive call finishes
        // Control returns to the previous (parent) call in the call stack
        
    } catch (const fs::filesystem_error& e) {
        // Handle file system specific errors (permission denied, etc.)
        cerr << "Filesystem error: " << e.what() << endl;
    } catch (const exception& e) {
        // Handle any other unexpected errors
        cerr << "Error: " << e.what() << endl;
    }
}

/**
 * MAIN FUNCTION: Entry point of the program
 * 
 * Handles command line arguments and initiates the recursive directory traversal
 */
int main(int argc, char* argv[]) {
    // Validate command line arguments
    // argc = argument count (includes program name)
    // argv = argument vector (array of argument strings)
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <directory_path>" << endl;
        cout << "Example: " << argv[0] << " C:\\Users\\YourName\\Documents" << endl;
        cout << "\nNote: Provide a valid directory path as an argument." << endl;
        return 1;  // Return error code
    }

    // Get the directory path from command line argument
    const char* rootPath = argv[1];

    // Print root header with visual separator
    cout << "========================================" << endl;
    cout << "Directory Structure:" << endl;
    cout << "========================================" << endl;
    cout << "Root:" << endl;
    
    // Start recursive traversal with depth 1 (first level indentation)
    // This initiates the FIRST recursive call
    // All subsequent calls happen inside recursiveDirectoryTraversal()
    recursiveDirectoryTraversal(rootPath, 1);
    
    cout << "========================================" << endl;
    cout << "Traversal Complete!" << endl;

    return 0;  // Return success code
}
