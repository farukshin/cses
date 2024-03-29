//https://cses.fi/problemset/task/1643
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
    int n;
    cin >> n;
    vector<ll> v(n);
    ll ans = -1e9-5, cur = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cur = max(cur + v[i], v[i]);
        ans = max(ans, cur);
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
