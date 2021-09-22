//https://cses.fi/problemset/task/1662
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
    int x = n, cur;
    ll ans = 0, prefixSum = 0;
    map<ll, int> mp;

    mp[prefixSum] += 1;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        prefixSum = (prefixSum + cur) % x;
        if (prefixSum < 0)
            prefixSum += x;

        ans += mp[prefixSum];
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
