//https://cses.fi/problemset/task/1192
//#tech_debt
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
    int k = 0;
    int n = 0, m = 0;
    vector<vector<int>> a(1000);
    map<int, int> maps;

    char b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        a[i] = vector<int>(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            if (b == '#')
            {
                a[i][j] = 0;
                continue;
            }

            int up = i > 0 ? a[i - 1][j] : 0;
            int left = i > 0 ? a[i][j - 1] : 0;

            int pre;

            int parent_up = up;
            while (maps.count(parent_up) != 0)
            {
                pre = parent_up;
                parent_up = maps[parent_up];
                if (parent_up != pre)
                {
                    maps[pre] = parent_up;
                }
            }

            int parent_left = left;
            while (maps.count(parent_left) != 0)
            {
                pre = parent_left;
                parent_left = maps[parent_left];
                if (parent_left != pre)
                {
                    maps[pre] = parent_left;
                }
            }

            if (up == 0 && left == 0)
            {
                a[i][j] = ++k;
            }
            else if (up == 0 || left == 0)
                if (up != 0)
                    a[i][j] = parent_up;
                else
                    a[i][j] = parent_left;
            else if (up != 0 && left != 0 && up == left)
                a[i][j] = parent_up;
            else if (up != 0 && left != 0 && up != left)
            {
                int t = min(parent_up, parent_left);
                a[i][j] = t;

                if (parent_up != t && maps.count(parent_up) == 0 || maps.count(parent_up) == 1 && maps[parent_up] > t)
                    maps[parent_up] = t;
                if (parent_left != t && maps.count(parent_left) == 0 || maps.count(parent_left) == 1 && maps[parent_left] > t)
                    maps[parent_left] = t;
            }
        }
    }

    cout << k - maps.size() << endl;
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
