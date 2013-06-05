#include <iostream>

using namespace std;

int main(void)
{
    while (1)
    {
        long long int   N;

        cin >> N;

        if (N < 0)
            break;

        long long int   i;

        for (i = 2; i <= 1000000LL; i++)
        {
            while ((N % i) == 0)
            {
                cout << "    " << i << endl;
                N /= i;
            }

            if (N == 1)
                break;
        }

        if (i > 1000000LL)
            cout << "    " << N << endl;

        cout << endl;
    }

    return 0;
}
