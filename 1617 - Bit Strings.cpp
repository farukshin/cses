#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const int mod = 1000000007;

int pow(int a, int W, int m)
{

    int V = 0;
    long long S = 1, c = a;

    V = W;
    c = a;
    while (V != 0)
    {
        if (V % 2 != 0)
        {
            S = (S * c) % m;
        }
        c = (c * c) % m;
        V >>= 1;
    }
    return S;
}

void solve()
{
    int W = 0;

    cin >> W;
    cout << pow(2, W, mod) << endl;
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
