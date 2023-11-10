#include <bits/stdc++.h>

using namespace std;

void quicksort(int[],int, int);
int partition(int[], int, int);

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

    quicksort(array, 0, arraySize-1);


    cout << "Sorted array: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}



void quicksort(int a[], int p, int r)
{
    if (p < r)
    {
            int q = partition(a, p, r);
            quicksort(a, p, q - 1);
            quicksort(a, q + 1, r);
   }
}

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = (p - 1);
    for (int j = p; j <= r-1; j++)
    {
        if (a[j] <= x)
        {
                i++;
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
        }
     }
     int tmp = a[i+1];
     a[i+1] = a[r];
     a[r] = tmp;
     return (i + 1);
}