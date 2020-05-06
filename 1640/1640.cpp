//https://cses.fi/problemset/task/1640
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
    int n, x, cur;

    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        a[i] = make_pair(cur, i + 1);
    }
    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    while (i < j)
    {
        cur = a[i].first + a[j].first;
        if (cur == x)
        {
            cout << a[i].second << " " << a[j].second << endl;
            return;
        }
        else if (cur > x)
            j--;
        else
            i++;
    }
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
