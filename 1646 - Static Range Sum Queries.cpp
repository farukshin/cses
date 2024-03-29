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
    int x, y;
    cin >> x >> y;
    ll a[200001];
    a[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int min, max;
    while (y--)
    {
        cin >> min >> max;
        cout << a[max] - a[min - 1] << endl;
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
