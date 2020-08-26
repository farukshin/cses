//https://cses.fi/problemset/task/1671
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<vector<pair<int, int>>> ss;
vector<int> d;
vector<bool> used;

void solve()
{
    int n, m;
    cin >> n >> m;
    ss.resize(n);
    d.resize(n, INT_MAX);
    d[0] = 0;
    used.resize(n, false);


    for (int i = 0;i < m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ss[--a].push_back({ --b, c });
    }

    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0;j < n;j++)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INT_MAX)
            break;

        used[v] = true;

        for (auto chield : ss[v])
            if (d[v] + chield.second < d[chield.first])
                d[chield.first] = d[v] + chield.second;
    }

    for (int i = 0; i < n;i++)
        cout << d[i] << " ";
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
