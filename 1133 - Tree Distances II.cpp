//https://cses.fi/problemset/task/1133
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const int MAXARR = 2e5 + 5;
int n;
vector<ll> ans(MAXARR, 0);
vector<int> counts(MAXARR, 1);
vector<vector<int>> v(MAXARR);

void dfs(int node = 1, int parent = 0)
{
    for (auto child : v[node])
        if (child != parent)
        {
            dfs(child, node);
            counts[node] += counts[child];
            ans[node] += ans[child] + counts[child];
        }
}

void dfs2(int node = 1, int parent = 0)
{
    for (auto child : v[node])
        if (child != parent)
        {
            ans[child] = ans[node] - counts[child] + n - counts[child];
            dfs2(child, node);
        }
}

void solve()
{
    cin >> n;

    int a, b;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs();
    dfs2();

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
