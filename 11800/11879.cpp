#include <iostream>

using namespace std;

int main(void)
{
    while (1)
    {
        string      n;

        getline(cin, n);

        int     r = n[0] - '0';

        if (r == 0)
            break;

        for (int i = 1; i < n.length(); i++)
        {
            r = ((r * 10) + (n[i] - '0')) % 17;
        }

        cout << !r << endl;
    }

    return 0;
}
