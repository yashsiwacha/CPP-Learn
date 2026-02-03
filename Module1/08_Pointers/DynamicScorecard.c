/* Dynamic Scorecard Analyzer - Cricket coach tool for batsman score analysis */

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void inputScores(int *scoresPtr, int size);
double calculateAverage(const int *scoresPtr, int size);
int findHighest(const int *scoresPtr, int size);

// Input scores with validation (0-100)
void inputScores(int *scoresPtr, int size)
{
    int score;

    printf("\n=== Entering Scores ===\n");

    for (int i = 0; i < size; i++)
    {
        while (1)
        {
            printf("Enter score for Game #%d (0-100): ", i + 1);

            if (scanf("%d", &score) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }

            if (score < 0 || score > 100)
            {
                printf("Invalid score. Must be between 0 and 100. Please re-enter.\n");
                continue;
            }

            *(scoresPtr + i) = score;
            break;
        }
    }
    printf("\n");
}

// Calculate average score using pointer arithmetic
double calculateAverage(const int *scoresPtr, int size)
{
    if (size == 0)
        return 0.0;

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(scoresPtr + i);
    }

    return (double)sum / size;
}

// Find highest score using pointer dereferencing
int findHighest(const int *scoresPtr, int size)
{
    int highest = *scoresPtr;

    for (int i = 1; i < size; i++)
    {
        if (*(scoresPtr + i) > highest)
            highest = *(scoresPtr + i);
    }

    return highest;
}

int main()
{
    int numGames;
    int *inningsScores = NULL;

    printf("╔════════════════════════════════════════════╗\n");
    printf("║   Dynamic Scorecard Analyzer - Cricket    ║\n");
    printf("╚════════════════════════════════════════════╝\n\n");

    // Input validation for number of innings
    while (1)
    {
        printf("Enter the total number of innings played (must be positive): ");

        if (scanf("%d", &numGames) != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (numGames <= 0)
        {
            printf("Number of games must be positive. Please re-enter.\n");
            continue;
        }

        break;
    }

    // Dynamic memory allocation
    inningsScores = (int *)malloc(numGames * sizeof(int));

    if (inningsScores == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    printf("\nMemory successfully allocated for %d innings.\n", numGames);

    inputScores(inningsScores, numGames);

    double average = calculateAverage(inningsScores, numGames);
    int highest = findHighest(inningsScores, numGames);
    printf("╔════════════════════════════════════════════╗\n");
    printf("║           ANALYSIS RESULTS                 ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║ Total Innings:       %2d                    ║\n", numGames);
    printf("║ Average Score:       %.2lf                 ║\n", average);
    printf("║ Highest Score:       %d                    ║\n", highest);
    printf("╚════════════════════════════════════════════╝\n\n");

    printf("Score Summary:\n");
    printf("─────────────────────\n");
    for (int i = 0; i < numGames; i++)
    {
        printf("Game #%d: %d\n", i + 1, *(inningsScores + i));
    }
    printf("─────────────────────\n");

    // Memory deallocation
    free(inningsScores);
    inningsScores = NULL;

    printf("\nMemory deallocated successfully. Program ending.\n");

    return 0;
}
