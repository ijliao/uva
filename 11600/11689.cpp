#include <iostream>

using namespace std;

int main(void)
{
    int     N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int     e, f, c;

        cin >> e >> f >> c;

        int     sum = e + f;
        int     total = 0;

        while (sum >= c)
        {
            int     r = sum / c;
            sum %= c;

            total += r;
            sum += r;
        }

        cout << total << endl;
    }

    return 0;
}
