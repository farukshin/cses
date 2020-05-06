//https://cses.fi/problemset/task/1642
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

void solve()
{
    map<int, pair<int, int>> lhs;
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    bool fl = false;
    for (int i = 0; i < n && !fl; i++)
    {
        for (int j = 0; j < i && !fl; j++)
            lhs[v[i] + v[j]] = {i, j};
        for (int j = i + 2; j < n && !fl; j++)
        {
            int k = v[j] + v[i + 1];
            auto it = lhs.find(sum - k);
            if (it == lhs.end())
                continue;
            cout << it->second.first + 1 << " " << it->second.second + 1 << " " << i + 2 << " " << j + 1 << endl;
            fl = true;
        }
    }
    if (!fl)
        cout << "IMPOSSIBLE" << endl;
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
