#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    int     N;

    cin >> N;

    string      ccn;

    getline(cin, ccn);

    int     dbl[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

    while (N-- > 0)
    {
        getline(cin, ccn);

        int     d = 0;
        int     r = 0;

        for (int i = 0; i < ccn.length(); i++)
        {
            char    c = ccn[i];

            if (isdigit(c))
            {
                r += (d % 2) ? c - '0' : dbl[c - '0'];
                d++;
            }
        }

        cout << string((r % 10) ? "Invalid" : "Valid") << endl;
    }

    return 0;
}
