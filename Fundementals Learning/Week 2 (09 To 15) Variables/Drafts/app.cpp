#include <iostream>
using namespace std;
// #define days 9; Another way to declare constatns but not advised to use

int a = 100; // Global Variable

int second()
{
    cout << a << "Coming From Second Function\n";
    /*
    cout << b << "Coming From Second Function\n"; error! => Can't access local variable outside its scope
    */
    return 0;
}

int main()
{
    int b = 200; // Local Variable
    cout << a << "Coming From Main Function\n";
    cout << b << "Coming From Main Function\n";
    second();

    cout << "============ Constants ============\n";

    const int num = 100;
    // num = 20; error! => Can't reassign a read only variable
    // const int x; error! => Can't declare a const variable without intialization

    return 0;
}