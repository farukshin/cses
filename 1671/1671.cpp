//https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void dejkstra(const vector<vector<pair<int, int>>>& ss, const int& countNode, const int& start, vector<ll>& dist) {

    dist.resize(countNode, LONG_LONG_MAX);
    dist[0] = 0;

    priority_queue< pair<ll, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        int cur = u.second;
        if (-u.first > dist[cur])
            continue;

        for (auto chield : ss[cur])
        {
            int to = chield.first, len = chield.second;
            if (dist[to] > dist[cur] + len)
            {
                dist[to] = dist[cur] + len;
                q.push(make_pair(-dist[to], to));
            }
        }
    }
}

void solve()
{
    vector<vector<pair<int, int>>> ss;
    vector<ll> dist;

    int n, m;
    cin >> n >> m;
    ss.resize(n);

    for (int i = 0;i < m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ss[--a].push_back({ --b, c });
    }

    int start = 0;
    dejkstra(ss, n, start, dist);

    for (int i = 0; i < n;i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif

    solve();
    //int t; cin >> t; while(t--) solve();

    return 0;
}
