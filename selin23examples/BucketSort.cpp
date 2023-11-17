#include <bits/stdc++.h>

using namespace std;

int getMax(int a[], int n) // maximum element (find)
{
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}
void bucketSort(int a[], int n) // function to implement bucket sort
{
  int max = getMax(a, n); //max elem
  int bucket[max], i;
  for (int i = 0; i <= max; i++)
  {
    bucket[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    bucket[a[i]]++;
  }
  for (int i = 0, j = 0; i <= max; i++)
  {
    while (bucket[i] > 0)
    {
      a[j++] = i;
      bucket[i]--;
    }
  }
}

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

    bucketSort(array, arraySize);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

