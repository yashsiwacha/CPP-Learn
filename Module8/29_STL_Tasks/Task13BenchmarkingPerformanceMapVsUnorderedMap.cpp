#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

// --- Configuration Constants ---
constexpr int NUM_WORDS = 100000;
constexpr int NUM_LOOKUP_TESTS = 10000;
constexpr int NUM_NONEXISTENT_WORDS = 10000;

// --- Type Aliases for Readability ---
using WordVector = std::vector<std::string>;
using MilliSeconds = std::chrono::duration<double, std::milli>;

// Measure how long a callable takes to execute and print the elapsed time.
template <typename Func>
double measureTime(const std::string &description, Func func)
{
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    MilliSeconds duration = end - start;
    std::cout << std::fixed << std::setprecision(3)
              << "  " << std::left << std::setw(30) << description << ": "
              << duration.count() << " ms\n";

    return duration.count();
}

// Generate unique words using a prefix plus sequential numbers.
WordVector generateWords(int count, const std::string &prefix)
{
    WordVector words;
    words.reserve(static_cast<std::size_t>(count));

    for (int i = 0; i < count; ++i)
    {
        words.push_back(prefix + std::to_string(i));
    }

    return words;
}

// Reserve capacity only for unordered_map; std::map does not support reserve().
template <typename MapType>
void conditionallyReserve(MapType &mapContainer, std::size_t count)
{
    if constexpr (std::is_same_v<MapType, std::unordered_map<std::string, int>>)
    {
        mapContainer.reserve(count);
    }
}

// Generic benchmark for map-like containers with string keys and int values.
template <typename MapType>
void benchmarkContainer(const std::string &containerName,
                        const WordVector &words_to_insert,
                        const WordVector &non_existent_words)
{
    std::cout << "\n=== Benchmarking " << containerName << " ===\n";

    MapType my_container;
    conditionallyReserve(my_container, words_to_insert.size());

    std::cout << "Insertion / lookup results:\n";

    measureTime("Insertion", [&]()
                {
        for (std::size_t i = 0; i < words_to_insert.size(); ++i)
        {
            my_container[words_to_insert[i]] = static_cast<int>(i);
        } });

    volatile int found_count = 0;
    measureTime("Lookup (Existing Keys)", [&]()
                {
        for (int i = 0; i < NUM_LOOKUP_TESTS; ++i)
        {
            auto it = my_container.find(words_to_insert[static_cast<std::size_t>(i)]);
            if (it != my_container.end())
            {
                ++found_count;
            }
        } });

    volatile int not_found_count = 0;
    measureTime("Lookup (Non-Existing Keys)", [&]()
                {
        for (int i = 0; i < NUM_NONEXISTENT_WORDS; ++i)
        {
            auto it = my_container.find(non_existent_words[static_cast<std::size_t>(i)]);
            if (it == my_container.end())
            {
                ++not_found_count;
            }
        } });

    std::cout << "  " << std::left << std::setw(30) << "Final Size"
              << ": " << my_container.size() << "\n";

    // Copy volatile counters to normal integers for clean output.
    const int found_total = found_count;
    const int not_found_total = not_found_count;
    std::cout << "  " << std::left << std::setw(30) << "Existing lookups counted"
              << ": " << found_total << "\n";
    std::cout << "  " << std::left << std::setw(30) << "Missing lookups counted"
              << ": " << not_found_total << "\n";
}

int main()
{
    std::cout << "==============================================\n";
    std::cout << "Benchmarking Performance: std::map vs std::unordered_map\n";
    std::cout << "==============================================\n";

    std::cout << "Generating " << NUM_WORDS << " unique words...\n";
    WordVector words_to_insert = generateWords(NUM_WORDS, "word_");

    std::cout << "Generating " << NUM_NONEXISTENT_WORDS << " non-existent words for lookup tests...\n";
    WordVector non_existent_words = generateWords(NUM_NONEXISTENT_WORDS, "nonexistent_word_");
    std::cout << "Data generation complete.\n";

    benchmarkContainer<std::map<std::string, int>>("std::map<std::string, int>",
                                                   words_to_insert,
                                                   non_existent_words);

    benchmarkContainer<std::unordered_map<std::string, int>>("std::unordered_map<std::string, int>",
                                                             words_to_insert,
                                                             non_existent_words);

    std::cout << "\nBenchmarking complete.\n";
    return 0;
}
