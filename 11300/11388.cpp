#include <iostream>

using namespace std;

int main(void)
{
    int     T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        long long int       G, L;

        cin >> G >> L;

        if ((L % G) != 0)
            cout << -1 << endl;
        else
            cout << G << ' ' << L << endl;
    }

    return 0;
}
