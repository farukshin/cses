//https://cses.fi/problemset/task/1732
// #tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

void solve()
{
    string s;
    cin >> s;
    int n, a;
    n = s.size();
    for (int i = 1; i < n; i++)
    {
        a = i;
        bool fl = true;
        while (a--)
        {
            if (s[a] != s[n - i + a])
            {
                fl = false;
                break;
            }
        }
        if (fl)
            cout << i << " ";
    }
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
