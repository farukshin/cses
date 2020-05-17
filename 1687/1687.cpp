//https://cses.fi/problemset/task/1687
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

int MAXARR = 2e5 + 5;
vector<vector<int>> v(MAXARR);
vector<int> boss(MAXARR, -1);

void dfs(int node, int parent = -1)
{
    for (int child : v[node])
    {
        boss[child] = node;
        dfs(child, node);
    }
}

int getBoss(int emp, int up)
{
    int ans = -1;
    while (up--)
    {
        ans = boss[emp];
        emp = ans;
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int cur;
    for (int i = 2; i <= n; i++)
    {
        cin >> cur;
        //v[cur].push_back(i);
        boss[i] = cur;
    }
    //dfs(1);

    int up;
    while (q--)
    {
        cin >> cur >> up;
        cout << getBoss(cur, up) << endl;
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
