//https://cses.fi/problemset/task/1644
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
    const int MAXN = 2e5 + 5;
    ll arr[MAXN];
    multiset<ll> mset;
    ll ans = LONG_LONG_MIN;
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = a; i <= n; i++)
    {
        mset.insert(arr[i - a]);
        if (i > b + 1)
            mset.erase(mset.find(arr[i - b - 1]));
        ans = max(ans, arr[i] - *mset.begin());
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
