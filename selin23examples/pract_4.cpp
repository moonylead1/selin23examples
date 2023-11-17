#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

//Надано масив A(N). Якщо N – парне, знайти максимальний елемент,
//інакше – мінімальний.
int main(int argc, char const *argv[])
{
    int n = 4;
    double arr[n] = {2, 8, -2, 10};

    if (n%2==0){
        double maxElement = arr[0];
        for(int i = 1; i < n; i++){
            if (arr[i] > maxElement){
                maxElement = arr[i];
            }
        }
        cout << maxElement << endl;
    }else{
        double minElement = arr[0];
        for(int i = 1; i < n; i++){
            if (arr[i] < minElement){
                minElement = arr[i];
            }
        }
        cout << minElement << endl;
    }

    return 0;
}
