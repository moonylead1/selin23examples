#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(int argc, char const *argv[])
{
    int n = 6;
    double arr[n][n];

    for (int i = 0; i < n; i++){
        for ( int j= 0; j < n; j++){
            arr[i][j] = rand()%10;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    double minElement = arr[0][0];

    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            if (arr[i][j] < minElement){
                minElement = arr[i][j];
            }
        }
    }

    cout << minElement << endl;

    return 0;
}
