//https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = max(0, i - 6); j < i; j++)
            dp[i] = (dp[i] + dp[j]) % MOD;

    cout << dp[n] << endl;
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
