#include <iostream>

using namespace std;

string strchar(char ch, int k)
{
    string r;
    r = "";
    for (int i = 0; i < k; i++)
        r += ch;

    return r;
}

int main()
{
    string s, beg, end, s0;
    int i = 0, k1 = 0;
    int a[26]{0};

    cin >> s;

    for (char c : s)
        a[c - 'A']++;

    for (i = 0; i < 26 && k1 <= 1; i++)
    {
        if (a[i] == 0)
            continue;

        if (a[i] % 2 == 0)
        {
            beg += strchar('A' + i, a[i] / 2);
            end = strchar('A' + i, a[i] / 2) + end;
        }
        else
        {
            k1++;
            s0 = 'A' + i;
            beg += strchar('A' + i, (a[i] - 1) / 2);
            end = strchar('A' + i, (a[i] - 1) / 2) + end;
        }
    }
    if (k1 > 1)
        cout << "NO SOLUTION";
    else
        cout << beg << s0 << end << endl;
    return 0;
}