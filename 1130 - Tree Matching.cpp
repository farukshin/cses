//https://cses.fi/problemset/task/1130
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;
const int MAXARR = 2e5 + 5;
vector<int> dp1(MAXARR), dp2(MAXARR);
vector<vector<int>> ss(MAXARR);

void dfs(int node, int parent)
{
    for (auto child : ss[node])
        if (child != parent)
        {
            dfs(child, node);
            dp2[node] += max(dp1[child], dp2[child]);
        }

    for (auto child : ss[node])
        if (child != parent)
            dp1[node] = max(dp1[node], 1 + dp2[node] + dp2[child] - max(dp1[child], dp2[child]));
}

void solve()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        ss[a - 1].push_back(b - 1);
        ss[b - 1].push_back(a - 1);
    }
    dfs(0, 0);
    cout << max(dp1[0], dp2[0]) << endl;
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
