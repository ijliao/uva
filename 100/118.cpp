#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/* NESW */

int     dx[] = {  0,  1,  0, -1 };
int     dy[] = {  1,  0, -1,  0 };
string  dS("NESW");

int main(void)
{
    int     Xsize, Ysize;
    string  buf;

    cin >> Xsize >> Ysize;
    getline(cin, buf);

    vector < vector < bool > >      map(Xsize + 1, vector < bool > (Ysize + 1));

    for (int i = 0; i <= Xsize; i++)
        for (int j = 0; j <= Ysize; j++)
            map[i][j] = false;

    while (1)
    {
        getline(cin, buf);

        if (cin.eof())
            break;

        istringstream   ori(buf);
        int             X, Y, dir;
        char            tmp;

        ori >> X >> Y >> tmp;

        switch (tmp)
        {
            case 'N' : dir = 0; break;
            case 'E' : dir = 1; break;
            case 'S' : dir = 2; break;
            case 'W' : dir = 3; break;
        }

        getline(cin, buf);

        bool    dead = false;

        for (int i = 0; i < buf.length(); i++)
        {
            char        step = buf[i];

            switch (step)
            {
                case 'L' : dir = (dir + 3) % 4; break;
                case 'R' : dir = (dir + 1) % 4; break;
                case 'F' :
                    int      Xt = X + dx[dir], Yt = Y + dy[dir];

                    if ((Xt > Xsize) || (Xt < 0) || (Yt > Ysize) || (Yt < 0))
                    {
                        if (false == map[X][Y])
                        {
                            map[X][Y] = true;
                            cout << X << ' ' << Y << ' ' << dS[dir] << " LOST" << endl;
                            dead = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        X = Xt;
                        Y = Yt;
                    }

                    break;
            }

            if (dead)
                break;
        }

        if (!dead)
        {
            cout << X << ' ' << Y << ' ' << dS[dir] << endl;
        }
    }

    return 0;
}
