#include <iostream>
using namespace std;

int main()
{
    using bignumber = long long; // Type Alias
    typedef long long bignum;    // Type Alias

    int num_one = 100000000000000000; // problem (integer overflows)
    long long num_two = 100000000000000000;
    bignumber num_three = 100000000000000000;
    bignum num_four = 100000000000000000;

    cout << num_one << endl;
    cout << num_two << endl;
    cout << num_three << endl;
    cout << num_four << endl;

    cout << sizeof(short) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;

    return 0;
}