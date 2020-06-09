//https://cses.fi/problemset/task/1750
//#tech_debt
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
    int n, q;
    cin >> n >> q;
    vector<int> parrent(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        parrent[i] = t;
    }

    while (q--)
    {
        ll x, k;
        cin >> x >> k;
        int ans = 0;
        while (k--)
            x = parrent[x];
        cout << x << endl;
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
