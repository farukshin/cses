#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const ll MAX = 2e5 + 5;
vector<int> ss[MAX];
int ans[MAX];

void dfs(int u)
{
    ans[u] = 1;
    for (int v : ss[u])
    {
        dfs(v);
        ans[u] += ans[v];
    }
}

void solve()
{
    int n, p;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        ss[p].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] - 1 << " ";
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
