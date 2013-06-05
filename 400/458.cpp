#include <iostream>

using namespace std;

int main(void)
{
    while (!cin.eof())
    {
        string      s;

        cin >> s;

        if (cin.eof())
            break;

        for (int i = 0; i < s.length(); i++)
            s[i] -= 7;

        cout << s << endl;
    }

    return 0;
}
