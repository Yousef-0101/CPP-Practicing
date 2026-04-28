#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    cout << "======== Task 2 ========\n";

    double salary = 5000.98;
    cout << sizeof(salary) << " Bytes" << endl; // 8 Bytes
    cout << sizeof(salary) * 8 << " Bits\n";    // 64 Bits

    cout << "======== Task 4 ========\n";

    // Edit Line To Make 8 Become 4
    cout << sizeof(10.5 + 5 + 20.5 + 10) << "\n";   // 8
    cout << sizeof(10.5f + 5 + 20.5f + 10) << "\n"; // 4

    cout << "======== Task 7 ========\n";

    int a = 1;
    int b = 13;
    int c = 17;
    int d = 70;

    cout << char(d - a) << char(c + d) << char(b + d) << endl; // Output Needed "EWS"

    cout << "======== Task 10 ========\n";

    using lli = long long int;
    typedef long long int lli;
    // #define lli long long int // Not Recommended

    lli num = 150050005; // This Is Long Long Int
    cout << num << "\n"; // 150050005

    cout << "======== Task 11 ========\n";

    short int e = 100;
    float f = 98.5f;
    double g = 1.7;

    // Edit This Line And Use Type Casting To Get The Output
    cout << e + (int)f + (int)g * 2 << "\n"; // 200

    cout << "======== Task 12 ========\n";

    short a12 = 1000;
    int b12 = 10000;
    long double c12 = 5.560000505012;

    // Change ??? To Something Else To Get The Output
    cout << sizeof(c12) - sizeof(b12) << "\n";    // 12
    cout << sizeof(c12) + sizeof(b12) << "\n";    // 20
    cout << sizeof(c12) * sizeof(a12) << "\n";    // 32
    cout << a12 * int(c12) << "\n";               // 5000
    cout << char(int(c12) * sizeof(c12)) << "\n"; // P

    return 0;
}