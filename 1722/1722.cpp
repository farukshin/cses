//https://cses.fi/problemset/task/1722
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ull fib(ull n)
{
    ull a = 1, ta,
        b = 1, tb,
        c = 1, rc = 0, tc,
        d = 0, rd = 1;

    int mod = 1e9 + 7;

    while (n)
    {
        if (n & 1)
        {
            tc = rc;
            rc = (rc * a + rd * c) % mod;
            rd = (tc * b + rd * d) % mod;
        }
        ta = a;
        tb = b;
        tc = c;
        a = (a * a + b * c) % mod;
        b = (ta * b + b * d) % mod;
        c = (c * ta + d * c) % mod;
        d = (tc * tb + d * d) % mod;
        n >>= 1;
    }
    return rc;
}

void solve()
{
    ull n;
    cin >> n;
    cout << fib(n) << endl;
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
