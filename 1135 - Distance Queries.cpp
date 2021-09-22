//https://cses.fi/problemset/task/1135
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

vector<int> v[MAXARR];
int ans[MAXARR][LOGMAXARR];
int mas[MAXARR];

int lca(int a, int b)
{
    if (mas[a] > mas[b])
        swap(a, b);

    int diff = mas[b] - mas[a];
    for (int i = 0; i < LOGMAXARR; i++)
        if (diff & (1 << i))
            b = ans[b][i];

    if (a == b)
        return a;

    for (int i = LOGMAXARR - 1; i >= 0; i--)
        if (ans[b][i] != ans[a][i])
            b = ans[b][i], a = ans[a][i];

    return ans[a][0];
}

void dfs(int node, int parent, int d)
{
    mas[node] = d;
    ans[node][0] = parent;
    int curr = parent;

    for (int i = 1; i < LOGMAXARR && (1 << i) <= d; i++)
    {
        ans[node][i] = ans[curr][i - 1];
        curr = ans[curr][i - 1];
    }

    for (auto child : v[node])
        if (child != parent)
            dfs(child, node, d + 1);
}

ll dist(int a, int b)
{
    return mas[a] + mas[b] - 2 * mas[lca(a, b)];
}

void solve()
{
    int n, q;
    cin >> n >> q;

    int a, b;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    dfs(0, -1, 0);

    while (q--)
    {
        cin >> a >> b;
        cout << dist(a - 1, b - 1) << endl;
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
