#include <iostream>
using namespace std;

int main()
{
    cout << "====================================\n";
    cout << "== Calculate Your Age Application ==\n";
    cout << "====================================\n\n";

    int age;
    cout << "Enter Your Age: ";
    cin >> age;

    int ageInDays = age * 365;
    int ageInHours = ageInDays * 24;

    cout << "Age In Days Is: " << ageInDays << " Days\n";
    cout << "Age In Hours Is: " << ageInHours << " Hours\n";

    return 0;
}