//https://cses.fi/problemset/task/1637
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
    int n, ans = 0, cur, m;
    cin >> n;
    while (n)
    {
        cur = n;
        m = 0;
        while (cur)
        {
            m = max(m, cur % 10);
            cur = cur / 10;
        }
        n -= m;
        ans++;
    }
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
