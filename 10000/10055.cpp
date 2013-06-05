#include <iostream>

using namespace std;

int main(void)
{
    while (!cin.eof())
    {
        unsigned long long int      a, b;

        cin >> a >> b;

        if (cin.eof())
            break;

        cout << (unsigned long long int)((a > b) ? a - b : b - a) << endl;
    }

    return 0;
}
