#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time() to prevent same seeds

using namespace std;

struct SortStats { //class to save values of comps and ctrc
    int comparisons;
    int copies;
};

void arrayOutput(int[], int);
void bubbleSort(int[], int, SortStats&);

int main(int argc, char const *argv[])
{
    const int arraySize = 1000; // size of array
    int bestCase[arraySize];
    int averageCase[arraySize];
    int worstCase[arraySize];

    srand(time(0)); // change seed random number generation

    // Best Case: Already sorted array
    for (int i = 0; i < arraySize; i++)
    {
        bestCase[i] = i; // filling the array with sorted values
    }

    // Average Case: Randomly generated array
    for (int i = 0; i < arraySize; i++)
    {
        averageCase[i] = rand() % 1001; // 0 -> 1000 random numbers
    }

    // Worst Case: Array sorted in reverse order
    for (int i = 0; i < arraySize; i++)
    {
        worstCase[i] = arraySize - i; // filling the array in reverse order
    }

    SortStats bestStats, averageStats, worstStats;

    // Best Case
    bubbleSort(bestCase, arraySize, bestStats);
    arrayOutput(bestCase, arraySize); //as a func
    cout << endl;
    cout << "Comparisons for best case: " << bestStats.comparisons << endl;
    cout << "Copies for best case: " << bestStats.copies << endl;

    // Average Case
    bubbleSort(averageCase, arraySize, averageStats);
    arrayOutput(averageCase, arraySize);
    cout << "Comparisons for average case: " << averageStats.comparisons << endl;
    cout << "Copies for average case: " << averageStats.copies << endl;

    // Worst Case
    bubbleSort(worstCase, arraySize, worstStats);
    arrayOutput(worstCase, arraySize);
    cout << "Comparisons for worst case: " << worstStats.comparisons << endl;
    cout << "Copies for worst case: " << worstStats.copies << endl;

    return 0;
}

void bubbleSort(int array[], int arraySize, SortStats &stats)
{
    stats.comparisons = 1; // update to 0
    stats.copies = 1; // update to 0

    for (int i = 0; i < arraySize; i++)
    {
        bool swappedAlready = false;
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            stats.comparisons++; // incr comparison counter
            if (array[j] > array[j + 1])
            {
                stats.copies += 3; // incr copy counter for swap
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                swappedAlready = true;
            }
        }
        if (!swappedAlready)
        {
            break;
        }
    }
}

void arrayOutput(int array[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

