//https://cses.fi/problemset/task/1688
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const int MAXARR = 2e5 + 5;
const int LOGMAXARR = 20;

vector<int> ss[MAXARR];
int depth[MAXARR];
int parents[MAXARR][LOGMAXARR];

int lca(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);

    int diff = depth[b] - depth[a];
    for (int i = 0; i < LOGMAXARR; i++)
        if (diff & (1 << i))
            b = parents[b][i];

    if (a == b)
        return a;

    for (int i = LOGMAXARR - 1; i >= 0; i--)
        if (parents[b][i] != parents[a][i])
            b = parents[b][i], a = parents[a][i];

    return parents[a][0];
}

void dfs(int node, int parent, int r)
{
    depth[node] = r;
    parents[node][0] = parent;
    int cur = parent;

    for (int i = 1; i < LOGMAXARR && (1 << i) <= r; i++)
    {
        parents[node][i] = parents[cur][i - 1];
        cur = parents[cur][i - 1];
    }

    for (auto child : ss[node])
        if (child != parent)
            dfs(child, node, r + 1);
}

void solve()
{
    int n, q, a, b;
    cin >> n >> q;

    for (int i = 1; i < n; i++)
    {
        cin >> a;
        ss[a - 1].push_back(i);
        ss[i].push_back(a - 1);
    }

    dfs(0, -1, 0);

    while (q--)
    {
        cin >> a >> b;
        cout << lca(a - 1, b - 1) + 1 << endl;
    }
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
