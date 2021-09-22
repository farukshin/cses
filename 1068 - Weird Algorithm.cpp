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
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;
    };
    cout << n << '\n';
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
