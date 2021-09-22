//https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const int MAXARR = 1e5 + 5;
vector<int> h;
vector<int> s;
vector<int> dp(MAXARR, 0);

void solve()
{
    int n, x;
    cin >> n >> x;
    h.resize(n);
    s.resize(n);

    for (auto &cur : h)
        cin >> cur;

    for (auto &cur : s)
        cin >> cur;

    for (int i = 0; i < n; i++)
        for (int j = x; j >= 1; j--)
            if (h[i] <= j)
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

    cout << dp[x] << endl;
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
