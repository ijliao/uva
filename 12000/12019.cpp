#include <iostream>

using namespace std;

int main(void)
{
    int     N;

    cin >> N;

    string  day[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int     dday[] = { 3, 28, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12 };

    while (N-- > 0)
    {
        int     m, d;

        cin >> m >> d;

        int     diff = (d - dday[m - 1] + 28) % 7;

        cout << day[diff] << endl;
    }

    return 0;
}
