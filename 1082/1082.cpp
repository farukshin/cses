//https://cses.fi/problemset/task/1082
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
    ll mod = 1e9 + 7;

    ll n;
    cin >> n;
    ll e, b, d = 2, ans = 0;
    do
    {
        e = n / (d - 1);
        b = n / d + 1;
        ll x = e - b + 1;
        ll y = b + e;
        if (x % 2)
            y /= 2;
        else
            x /= 2;
        x %= mod;
        y %= mod;
        x = x * y % mod;
        x = x * (d - 1) % mod;
        ans = (ans + x) % mod;
        d++;
    } while (b > d);
    for (int i = 1; i < b; i++)
        ans = (ans + n / i * i) % mod;
    if (ans < 0)
        ans += mod;
    cout << ans << endl;
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
