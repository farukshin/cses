//https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

vector<vector<int>> ss;
int n, m;
vector<int> parrent, dist;
int MAXARR = 2e5 + 5;

void bfs(int startNnode)
{
    queue<int> bfs;
    bfs.push(startNnode);
    parrent[1] = 1;
    dist[1] = 0;

    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();
        int d = dist[cur] + 1;

        for (int chield : ss[cur])
        {
            if (d >= dist[chield])
                continue;

            dist[chield] = d;
            parrent[chield] = cur;
            bfs.push(chield);
        }
    }
}

void solve()
{
    cin >> n >> m;

    ss.resize(n + 1);
    parrent.resize(n + 1);
    parrent[1] = 0;
    dist.resize(n + 1);

    for (int i = 1; i <= n; i++)
        dist[i] = MAXARR, parrent[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ss[a].push_back(b);
        ss[b].push_back(a);
    }

    bfs(1);

    if (dist[n] > n)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    stack<int> ans;
    while (n > 1)
    {
        ans.push(n);
        n = parrent[n];
    }
    ans.push(1);

    cout << ans.size() << endl;
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
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
