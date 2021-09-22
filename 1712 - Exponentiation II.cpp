//https://cses.fi/problemset/task/1712
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

ll mypow2(ll a, ll b, int mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= mod;

        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    const int MOD = 1e9 + 7;
    ll n, a, b, c;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        cout << mypow2(a, mypow2(b, c, MOD - 1), MOD) << endl;
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
