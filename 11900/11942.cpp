#include <iostream>

using namespace std;

int main(void)
{
    int     N;

    cin >> N;

    cout << "Lumberjacks:" << endl;

    while (N-- > 0)
    {
        int     last, tmp;
        bool    diff;

        cin >> last >> tmp;
        diff = (tmp - last) > 0;
        last = tmp;

        bool    skip = false;

        for (int i = 2; i < 10; i++)
        {
            cin >> tmp;

            if ((!skip) && (diff != ((tmp - last) > 0)))
            {
                cout << "Unordered" << endl;
                skip = true;
            }

            last = tmp;
        }

        if (!skip)
            cout << "Ordered" << endl;
    }

    return 0;
}
