//https://cses.fi/problemset/task/1641
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
    int n, sum;
    cin >> n >> sum;
    int cur;
    vector<tuple<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        v[i] = {cur, i + 1};
    }
    sort(v.begin(), v.end());

    int a, b;
    int x, y;
    bool fl = false;
    for (int i = 0; i < n - 2 && !fl; i++)
    {
        tie(a, x) = v[i];
        if (a >= sum)
            break;
        for (int j = i + 1; j < n - 1 && !fl; j++)
        {
            tie(b, y) = v[j];
            if (a + b >= sum)
                break;

            auto it = lower_bound(&v[j + 1], &v[n], make_tuple(sum - (a + b), 0));
            if (a + b + get<0>(*it) != sum)
                continue;

            cout << x << " " << y << " " << get<1>(*it) << endl;
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
