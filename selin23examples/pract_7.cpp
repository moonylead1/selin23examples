#include <iostream>
#include <cmath>
#define ld long double
using namespace std;

ld givenFunction(ld);
ld trapezoidSolveIntegral(ld, ld, ld, ld (*)(ld));

int main(int argc, char const *argv[]) {
    ld n, a, b;
    cout << "Enter a, b, n: " << endl;
    // cin >> a >> b >> n;
    a = 1, b = 2;
    n = 10000; //like 10000 steps or even higher for increased accuracy
    ld answer = trapezoidSolveIntegral(a, b, n, &givenFunction);
    cout << "Solved answer is: " << answer << endl;
    return 0;
}

ld givenFunction(ld x){
    return (1.0 / (x * x));
}

ld trapezoidSolveIntegral(ld a, ld b, ld n, ld (*func)(ld)) {
    ld S = 0.0;
    ld h = (b - a) / n;
    ld x = a;

    // Add the first and last function evaluations
    S = func(a) + func(b);

    for (int i = 1; i < n; ++i) {
        x += h;
        S += 2.0 * func(x); // Multiplying by 2 for every intermediate value
    }

    S *= h / 2.0; // Multiply by h/2 outside the loop

    return S;
}