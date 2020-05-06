#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void refresh(vector<ull> &v, ll i, ll K)
{
    v[i] = K;
    i = i / 2;
    while (i >= 1)
    {
        v[i] = v[2 * i] + v[2 * i + 1];
        i = i / 2;
    }
}

ll sum(vector<ull> &v, ll L, ll R)
{
    ull ans = 0;
    while (L <= R)
    {
        if (L % 2 != 0)
            ans += v[L];
        if (R % 2 == 0)
            ans += v[R];
        L = (L + 1) / 2;
        R = (R - 1) / 2;
    }
    return ans;
}

void loadtree(vector<ull> &v, ll L, ll R)
{
    while (L <= R)
    {
        v[L] = v[2 * L] + v[2 * L + 1];
        v[R] = v[2 * R] + v[2 * R + 1];
        if (L % 2 == 0)
            L++;
        else
            L = L / 2;
        if (R % 2 != 0)
            R--;
        else
            R = R / 2;
    }
    v[1] = v[2] + v[3];
}

void solve()
{
    ll x = 0, y = 0;
    ll osn = 0;
    cin >> x >> y;
    osn = pow(2, ceil(log2(x)));
    cout << osn << endl;
    vector<ull> v(2 * osn);
    for (ll i = 1; i <= osn; i++)
    {
        if (i <= x)
            cin >> v[i + osn - 1];
        else
            v[i + osn - 1] = 0;
    }

    loadtree(v, osn / 2, (2 * osn - 1) / 2);

    // cout << v[1] << endl;
    // cout << v[2] << " " << v[3] << endl;
    // cout << v[4] << " " << v[5] << " " << v[6] << " " << v[7] << endl;
    // cout << v[8] << " " << v[9] << " " << v[10] << " " << v[11] << " " << v[12] << " " << v[13] << " " << v[14] << " " << v[15] << endl;

    ll x1, x2, x3;
    for (ll i = 1; i <= y; i++)
    {
        cin >> x1 >> x2 >> x3;
        if (x1 == 1)
        {
            refresh(v, x2 + osn - 1, x3);
        }
        else if (x1 == 2)
            cout << sum(v, x2 + osn - 1, x3 + osn - 1) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}