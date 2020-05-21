//https://cses.fi/problemset/task/1139
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
vector<vector<int>> ss;
vector<int> colors;
vector<set<int>> distColors;

void dfs(int node, int parent)
{
    distColors[node].insert(colors[node]);

    for (int child : ss[node])
        if (child != parent)
        {
            dfs(child, node);
            distColors[node].insert(colors[child]);
            for (auto x : distColors[child])
                distColors[node].insert(x);
        }
}

void solve()
{
    int n, a, b;
    cin >> n;
    ss.resize(n + 1);
    colors.resize(n + 1);
    distColors.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> colors[i];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        ss[a].push_back(b);
        ss[b].push_back(a);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        cout << distColors[i].size() << " ";
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
