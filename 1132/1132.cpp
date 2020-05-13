//https://cses.fi/problemset/task/1132
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
vector<int> ans(MAXARR, 0);
vector<vector<int>> v(MAXARR);

void dfs(int startNode, bool repeat = false)
{
    bool used[MAXARR];

    queue<int> q;
    q.push(startNode);

    int maxStep = 0;
    int farthestNode = 0;

    used[startNode] = true;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto child : v[u])
        {
            if (!used[child])
            {
                used[child] = true;
                q.push(child);

                ans[child] += ans[u] + 1;
                if (ans[child] > maxStep)
                {
                    maxStep = ans[child];
                    farthestNode = child;
                }
            }
        }
    }

    if (!repeat)
        dfs(farthestNode, true);
}

void solve()
{
    int n;
    cin >> n;

    int a, b;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
