//https://cses.fi/problemset/task/1713
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
    int MAXARR = 1e6 + 1;
    vector<int> v(MAXARR);

    for (int i = 1; i < MAXARR; i++)
        for (int j = i; j < MAXARR; j += i)
            v[j]++;

    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        cout << v[x] << endl;
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
