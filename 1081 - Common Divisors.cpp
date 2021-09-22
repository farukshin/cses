//https://cses.fi/problemset/task/1081
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
    const int MAXARR = 1e6 + 1;
    vector<int> v(MAXARR);
    int n, cur;
    cin >> n;
    while (n--)
    {
        cin >> cur;
        v[cur]++;
    }

    for (int i = MAXARR - 1; i > 0; i--)
    {
        int sum = 0;
        for (int j = i; j < MAXARR && sum < 2; j += i)
            sum += v[j];

        if (sum > 1)
        {
            cout << i << endl;
            break;
        }
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
