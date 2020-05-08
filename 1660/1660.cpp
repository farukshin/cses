//https://cses.fi/problemset/task/1660
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
    int n, x, cur;
    cin >> n >> x;
    ll ans = 0, prefixSum = 0;
    map<ll, int> mp;

    mp[prefixSum] += 1;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        prefixSum += cur;
        auto it = mp.find(prefixSum - x);
        if (it != mp.end())
            ans += it->second;
        mp[prefixSum] += 1;
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
