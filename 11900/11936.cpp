#include <iostream>

using namespace std;

int main(void)
{
    int     N;

    cin >> N;

    while (N-- > 0)
    {
        unsigned long   a, b, c;

        cin >> a >> b >> c;

        if (((a + b) > c) && ((b + c) > a) && ((a + c) > b))
            cout << "OK" << endl;
        else
            cout << "Wrong!!" << endl;
    }

    return 0;
}
