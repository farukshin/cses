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
    long long N = 0, i = 0;
    long long a = 0, prea = 0, k = 0;

    cin >> N;
    cin >> a;
    for (i = 2; i <= N; i++)
    {
        prea = a;
        cin >> a;
        if (prea > a)
        {
            k += prea - a;
            a = prea;
        }
    }
    cout << k;
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
