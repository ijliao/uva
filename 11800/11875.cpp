#include <iostream>

using namespace std;

int main(void)
{
    int     T;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int     N;

        cin >> N;

        int     tmp;

        for (int t = 0; t < N / 2; t++)
            cin >> tmp;

        cin >> tmp;

        cout << "Case " << i << ": " << tmp << endl;

        for (int t = 0; t < N / 2; t++)
            cin >> tmp;
    }

    return 0;
}
