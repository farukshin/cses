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
    int t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        ll m = max(x, y);
        ll base = (m - 1) * (m - 1) + 1;
        ll baseX = m % 2 == 1 ? m : 1;
        ll baseY = m % 2 == 1 ? 1 : m;
        ll road = abs(y - baseY) + abs(x - baseX);
        cout << base + road << endl;
    }
}

int main()
{
    ios_b;
    solve();
    return 0;
}