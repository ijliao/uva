#include <iostream>

using namespace std;

int main(void)
{
    while (1)
    {
        int     N;

        cin >> N;

        if (N == 0)
            break;

        int     result = 0;

        for ( ; N > 0; N--)
            result += N * N;

        cout << result << endl;
    }

    return 0;
}
