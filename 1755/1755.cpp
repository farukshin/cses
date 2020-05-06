//https://cses.fi/problemset/task/1755
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

string strchar(char ch, int k)
{
    string r;
    r = "";
    for (int i = 0; i < k; i++)
        r += ch;

    return r;
}

void solve()
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
}

int main()
{
    ios_b;
#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif
    solve();
    return 0;
}
