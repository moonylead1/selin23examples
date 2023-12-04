#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

#define ld long double
using namespace std;

struct SortStats {
    ld comparisons = 0;
    ld copies = 0;
};

void quicksort(int[], int, int, SortStats&);
void insertionSort(int[], int, int, SortStats&);
void writeArrayToFile(int[], int, const string&);

int main() {
    const int arraySize = 100000; // Size of array
    int bestCase[arraySize];
    int averageCase[arraySize];
    int worstCase[arraySize];

    srand(time(0)); // Seed for random number generation

    // Best Case: Already sorted array
    for (int i = 0; i < arraySize; i++)
        bestCase[i] = i; // filling the array with sorted values

    // Average Case: Randomly generated array
    for (int i = 0; i < arraySize; i++)
        averageCase[i] = rand() % 1001; // 0 -> 1000 random numbers

    // Worst Case: Array sorted in reverse order
    for (int i = 0; i < arraySize; i++)
        worstCase[i] = arraySize - i; // filling the array in reverse order

    SortStats bestStats, averageStats, worstStats;

    // Best case
    quicksort(bestCase, 0, arraySize - 1, bestStats);
    writeArrayToFile(bestCase, arraySize, "bestCase_sorted.txt");
    cout << fixed << setprecision(0) << "Comparisons for best case: " << bestStats.comparisons << endl;
    cout << fixed << setprecision(0) << "Copies for best case: " << bestStats.copies << endl;

    // Average case
    quicksort(averageCase, 0, arraySize - 1, averageStats);
    writeArrayToFile(averageCase, arraySize, "averageCase_sorted.txt");
    cout << fixed << setprecision(0) << "Comparisons for average case: " << averageStats.comparisons << endl;
    cout << fixed << setprecision(0) << "Copies for average case: " << averageStats.copies << endl;

    // Worst case
    quicksort(worstCase, 0, arraySize - 1, worstStats);
    writeArrayToFile(worstCase, arraySize, "worstCase_sorted.txt");
    cout << fixed << setprecision(0) << "Comparisons for worst case: " << worstStats.comparisons << endl;
    cout << fixed << setprecision(0) << "Copies for worst case: " << worstStats.copies << endl;

    return 0;
}

void quicksort(int arr[], int left, int right, SortStats &stats) {
    if (left < right) {
        int pivot = arr[(left + right) / 2]; // Choose pivot element

        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) {
                stats.comparisons++;
                i++;
            }
            while (arr[j] > pivot) {
                stats.comparisons++;
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                stats.copies += 3;
                i++;
                j--;
            }
        }

        if (left < j) quicksort(arr, left, j, stats); // Sort left subarray
        if (i < right) quicksort(arr, i, right, stats); // Sort right subarray
    }
}

void writeArrayToFile(int array[], int arraySize, const string &filename) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (int i = 0; i < arraySize; i++)
            outfile << array[i] << " ";
        outfile.close();
        cout << "Sorted array written to " << filename << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}