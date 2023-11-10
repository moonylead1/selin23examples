#include <iostream>

using namespace std;

void bubbleSort(int[], int);

int main(int argc, char const *argv[])
{
    int arraySize = 1000; //size of array
    int array[arraySize];

    for(int i=0; i<arraySize; i++){
        array[i] = rand()%1001; // 0 -> 1000 random numbers
    }

    cout << "Generated array: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    bubbleSort(array, arraySize);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

void bubbleSort(int array[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        bool swappedAlready = false;
        for (int j = 0; j < arraySize-i-1; j++){ //need to limit those checks
            if (array[j] > array[j+1]){ // if current bigger than next
                int temp = array[j+1]; // save j+1
                array[j+1] = array[j];
                array[j] = temp;
                swappedAlready = true;
            }

        }
        if (!swappedAlready){ //no swap in pass -> array sorted
            break;
        }
    }
}

