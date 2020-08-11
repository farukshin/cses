//https://cses.fi/problemset/task/1624
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const int MAXARR = 8;
string area[MAXARR];
int rasstan[MAXARR];

bool step(int &k, int y)
{
    int i = 0;
    while (i < k && y != rasstan[i] && abs(k - i) != abs(y - rasstan[i]))
        i++;
    return i == k;
}

bool check()
{
    for (int i = 0; i < MAXARR; i++)
        if (area[rasstan[i]][i] == '*')
            return false;

    return true;
}

void Backtraking(int k, int &ans)
{
    for (int y = 0; y < MAXARR; y++)
        if (step(k, y))
        {
            rasstan[k] = y;
            if (k + 1 == MAXARR && check())
                ans++;
            Backtraking(k + 1, ans);
        }
}

void solve()
{

    for (int i = 0; i < 8; i++)
        cin >> area[i];
    int ans = 0;

    Backtraking(0, ans);

    cout << ans << endl;
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
