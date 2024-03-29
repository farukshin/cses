#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int mod = 1000000007;

ll mypow2(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= (a % mod);
        a %= mod;
        b >>= 1;
    }
    return res % mod;
}

void solve()
{
    ll n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        cout << mypow2(a, b) << endl;
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
