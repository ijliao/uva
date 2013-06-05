#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int     n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int     N;

        cin >> N;

        double  len = (N - 1) * 4 + (((N - 2) > 0) ? (N - 2) * (N - 2) * sqrt(2.0) : 0);

        cout.precision(3);
        cout << fixed << len << endl;

        if (i != n - 1)
            cout << endl;
    }

    return 0;
}
