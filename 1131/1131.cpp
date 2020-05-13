//https://cses.fi/problemset/task/1131
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
vector<vector<int>> v(MAXARR);

int dfs(int startNode, bool last)
{
    bool used[MAXARR];
    vector<int> dist(MAXARR);

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

                dist[child] += dist[u] + 1;
                if (dist[child] > maxStep)
                {
                    maxStep = dist[child];
                    farthestNode = child;
                }
            }
        }
    }

    if (last)
        return farthestNode;
    else
        return maxStep;
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

    int last = dfs(1, true);
    int ans = dfs(last, false);

    cout << ans << endl;
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
