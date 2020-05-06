//https://cses.fi/problemset/task/1668
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const ll MAX = 1e5 + 5;
vector<int> ss[MAX];
int color[MAX];

bool dfs(int u, int par)
{
    for (int v : ss[u])
    {
        if (u == par)
            continue;
        if (color[v] == (3 - color[u]))
            continue;
        if (color[v])
            return false;

        color[v] = 3 - color[u];
        if (!dfs(v, u))
            return false;
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        ss[a].push_back(b);
        ss[b].push_back(a);
    }

    bool ok = true;
    for (int i = 1; i <= n && ok; i++)
    {
        if (color[i])
            continue;
        color[i] = 1;
        ok &= dfs(i, 0);
    }

    if (ok)
        for (int i = 1; i <= n; i++)
            cout << color[i] << " ";
    else
        cout << "IMPOSSIBLE" << endl;
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
