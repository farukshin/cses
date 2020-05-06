//https://cses.fi/problemset/task/1091
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
    int n, m;
    cin >> n >> m;

    int tick[n];
    int cust[m];
    for (int i = 0; i < n; ++i)
    {
        cin >> tick[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> cust[i];
    }

    sort(tick, tick + n);

    int done[n] = {0};
    for (int i = 0; i < m; ++i)
    {
        int ans = -1;
        int opos = upper_bound(tick, tick + n, cust[i]) - tick - 1;
        int pos = opos;
        while (done[pos] && pos >= 0)
        {
            pos -= done[pos];
        }
        if (pos >= 0)
        {
            ans = tick[pos];
            done[opos] = opos - pos;
            done[pos] = 1;
        }
        cout << ans << endl;
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
