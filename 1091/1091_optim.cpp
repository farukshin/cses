#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

template <class T>
void ckmin(T &a, T b) { a = min(a, b); }
template <class T>
void ckmax(T &a, T b) { a = max(a, b); }

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define nl '\n'
#define nls "\n"
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(i, n) for (int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for (int i = (a); i <= (n); ++i)
#define repst(i, n) for (auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for (int i = (n); i >= (a); --i)

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    int tick[n];
    int cust[m];
    for (int i = 0; i < n; ++i)
    {
        cin >> tick[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> cust[i];
    }

    sort(tick, tick + n);

    int done[n] = {0};
    for (int i = 0; i < m; ++i)
    {
        int ans = -1;
        int opos = upper_bound(tick, tick + n, cust[i]) - tick - 1;
        int pos = opos;
        while (done[pos] && pos >= 0)
        {
            pos -= done[pos];
        }
        if (pos >= 0)
        {
            ans = tick[pos];
            done[opos] = opos - pos;
            done[pos] = 1;
        }
        cout << ans << nl;
    }
}

int main()
{
    ios_b;
    solve();
    return 0;
}