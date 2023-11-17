#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void printArray(vector<vector <double>>);
vector<double> selectionSort(vector<double>);
//Задано матрицю, відсортувати кожний із рядків за зростанням методом вибору.
int main(int argc, char const *argv[])
{
    vector <vector <double>> arr = {
        {4, 3, 2, 3},
        {5, 4, 1, 2},
        {4, 3, 2, 1},
        {2, 1, 4, 0}
    };

    for(int i = 0; i < arr.size(); i++){
        arr[i] = selectionSort(arr[i]);
    }

    printArray(arr);
    return 0;
}

void printArray(vector<vector <double>> arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<double> selectionSort(vector<double> v){
    for (int i = 0; i< v.size(); i++){
        int coordinate = i;
        double temp = v[i];
        double currentPositon = v[i];
        for (int j = i+1; j < v.size(); j++){
            if (v[j] < currentPositon){
                coordinate = j;
                currentPositon = v[j];
            }
        }
        v[i] = v[coordinate];
        v[coordinate] = temp;
    }
    return v;
}

//myvector.insert(myvector.begin(), value);