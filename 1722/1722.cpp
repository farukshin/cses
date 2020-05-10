//https://cses.fi/problemset/task/1722
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

int fib(int n)
{
    int mod = 1e9 + 7;
    if (n < 2)
        return (n >= 0 ? n : 0);

    return (fib(n - 1) + fib(n - 2)) % mod;
}

void solve()
{
    int n;
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
