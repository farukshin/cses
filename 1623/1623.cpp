//https://cses.fi/problemset/task/1623
// #tech_debt
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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<ll>());
    int a, b = 0;
    a = v[0];
    for (int i = 1; i < n; i++)
    {

        if (b < a)
            b += v[i];
        else
            a += v[i];

        cout << v[i] << " a=" << a << " b=" << b << endl;
    }
    cout << max(a, b) - min(a, b) << endl;
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
