#include <iostream>
using namespace std;

int main()
{
    int t = 0, a = 0, b = 0, i = 0;
    int x, y;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cin >> a >> b;
        if ((2 * a - b) < 0 || (2 * b - a) < 0 || (2 * a - b) % 3 != 0)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }

    return 0;
}