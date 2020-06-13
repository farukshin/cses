//https://cses.fi/problemset/task/1140
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

struct project
{
    int a, b, p;
};

int sort_proj(project p1, project p2)
{
    return p1.a < p2.a;
}

vector<project> v;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        project aux = {a, b, p};
        v.push_back(aux);
    }

    sort(v.begin(), v.end(), sort_proj);
    set<pair<int, int>> dp;
    int mx = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        a = v[i].a;
        b = v[i].b;
        p = v[i].p;

        while (dp.size() > 0 && dp.begin()->first < a)
        {
            mx = max(mx, dp.begin()->second);
            dp.erase(dp.begin());
        }

        ans = max(ans, mx + p);
        dp.insert({b, mx + p});
    }

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
