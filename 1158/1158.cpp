//https://cses.fi/problemset/task/1158
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
    int h[1005];
    int s[1005];
    int a[100005];
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
        cin >> h[i];

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        for (int j = x; j >= 1; j--)
            if (h[i] <= j)
                a[j] = max(a[j], a[j - h[i]] + s[i]);

    cout << a[x] << endl;
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
