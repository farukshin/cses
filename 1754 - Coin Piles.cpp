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
