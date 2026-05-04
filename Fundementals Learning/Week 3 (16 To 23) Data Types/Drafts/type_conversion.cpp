#include <iostream>
using namespace std;

int main()
{

    int a;
    double b = 20.5;
    a = b;
    cout << a << endl; // 20 Implicit type casting (double -> int)

    char c = 'C';
    int d = 20;
    cout << c + d << endl; // 87 Implicit type casting (char -> int{ASCII})

    int e = 20;
    double f = 20.5;
    cout << e + f << endl; // 40.5 Implicit type casting (int -> double)

    int g = 20;
    double h = 20.5;
    cout << g + (int)h << endl; // 40 Explicit type casting
    cout << g + int(h) << endl; // 40 Explicit type casting

    return 0;
}