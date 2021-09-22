#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const ll MAX = 1e5 + 5;
ll MOD = 1e9 + 7;
vector<vector<int>> ss(MAX, vector<int>());
queue<int> st;
ll ans = 0;
int n, m;
int dp[MAX];

int get(int a)
{
    if (dp[a] != -1)
        return dp[a];

    dp[a] = 0;
    for (auto b : ss[a])
        dp[a] = (dp[a] + get(b)) % MOD;

    return dp[a];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ss[a].push_back(b);
    }
    dp[n] = 1;

    cout << get(1) << endl;
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
