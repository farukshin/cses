#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

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

int k = 0;
int n = 0, m = 0;
vector<vector<int>> a(1000);
map<int, int> maps;

// int parent(int x)
// {
//     int cur = x;
//     int pre_cur = cur;
//     while (maps.count(cur) != 0)
//     {
//         cur = maps[cur];
//         if (cur != pre_cur)
//         {
//             maps[pre_cur] = cur;
//         }
//     }
//     return cur;
// }

void solve1()
{
    char b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        a[i] = vector<int>(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            if (b == '#')
            {
                a[i][j] = 0;
                continue;
            }

            int up = i > 0 ? a[i - 1][j] : 0;
            int left = i > 0 ? a[i][j - 1] : 0;

            int pre;

            int parent_up = up;
            while (maps.count(parent_up) != 0)
            {
                pre = parent_up;
                parent_up = maps[parent_up];
                if (parent_up != pre)
                {
                    maps[pre] = parent_up;
                }
            }

            int parent_left = left;
            while (maps.count(parent_left) != 0)
            {
                pre = parent_left;
                parent_left = maps[parent_left];
                if (parent_left != pre)
                {
                    maps[pre] = parent_left;
                }
            }

            if (up == 0 && left == 0)
            {
                a[i][j] = ++k;
            }
            else if (up == 0 || left == 0)
                if (up != 0)
                    a[i][j] = parent_up;
                else
                    a[i][j] = parent_left;
            else if (up != 0 && left != 0 && up == left)
                a[i][j] = parent_up;
            else if (up != 0 && left != 0 && up != left)
            {
                int t = min(parent_up, parent_left);
                a[i][j] = t;

                if (parent_up != t && maps.count(parent_up) == 0 || maps.count(parent_up) == 1 && maps[parent_up] > t)
                    maps[parent_up] = t;
                if (parent_left != t && maps.count(parent_left) == 0 || maps.count(parent_left) == 1 && maps[parent_left] > t)
                    maps[parent_left] = t;
            }
        }
    }

    cout << k - maps.size() << nl;
}

int main()
{
    ios_b;
    solve1();
    // solve2();
    return 0;
}
