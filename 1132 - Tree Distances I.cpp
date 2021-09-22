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

int dfs(int startNode, bool calc)
{
    bool used[MAXARR];
    memset(used, false, sizeof(used));

    vector<int> step(MAXARR, 0);

    queue<int> q;
    q.push(startNode);

    int farthestNode = 0;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        used[u] = true;

        for (auto child : v[u])
        {
            if (!used[child])
            {
                q.push(child);
                step[child] += step[u] + 1;
                farthestNode = child;
                if (calc)
                    ans[child] = max(ans[child], step[child]);
            }
        }
    }

    return farthestNode;
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

    int last = dfs(1, false);
    int last2 = dfs(last, true);
    last = dfs(last2, true);
    
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
