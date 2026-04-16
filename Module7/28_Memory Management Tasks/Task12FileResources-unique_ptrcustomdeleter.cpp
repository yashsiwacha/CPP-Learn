#include <cstdio>
#include <iostream>
#include <memory>

int main()
{
    // Custom deleter for FILE* so unique_ptr can close files automatically.
    auto fileDeleter = [](FILE *f)
    {
        if (f)
        {
            fclose(f);
            std::cout << "File closed by custom deleter." << std::endl;
        }
    };

    // Open file in write mode. Handle failure immediately.
    FILE *file = fopen("log.txt", "w");
    if (file == nullptr)
    {
        std::cout << "Error: Failed to open log.txt" << std::endl;
        return 1;
    }

    // unique_ptr now owns FILE* and will call fileDeleter on scope exit.
    std::unique_ptr<FILE, decltype(fileDeleter)> filePtr(file, fileDeleter);

    fprintf(filePtr.get(), "Log started\n");
    std::cout << "Wrote: Log started" << std::endl;

    // Early-return style point can be added here safely; deleter still runs.
    std::cout << "Leaving scope. File will be closed automatically." << std::endl;
    return 0;
}
