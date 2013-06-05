#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    while (true)
    {
        unsigned long int   a, b;

        cin >> a >> b;

        if ((0 == a) && (0 == b))
            break;

        unsigned long int   x = ceil(sqrt(double(a)));
        unsigned long int   y = floor(sqrt(double(b)));

        cout << y - x + 1 << endl;
    }

    return 0;
}
