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

int parent(int x){
    int cur = x;
    while (maps.count(cur) != 0)
    {
        cur = maps[cur];
    }
    return cur;
}

void load(int x, int y, char b)
{
    if (b == '#')
    {
        a[x][y] = 0;
        return;
    }

    int up = x > 0 ? a[x - 1][y] : 0;
    int left = y > 0 ? a[x][y - 1] : 0;

    int p_up = parent(up);
    int p_left = parent(left);

    if (up == 0 && left == 0)
    {
        a[x][y] = ++k;
        //cout << "k = " << k << nl;
    }
    else if (up == 0 || left == 0)
        if (up != 0)
            a[x][y] = maps.count(up) == 0 ? up : maps[up];
        else
            a[x][y] = maps.count(up) == 0 ? left : maps[left];
    else if (up != 0 && left != 0 && up == left)
        a[x][y] = maps.count(up) == 0 ? up : maps[up];
    else if (up != 0 && left != 0 && up != left)
    {
        int t = min(p_up, p_left);
        a[x][y] = t;

        if (p_up != t && maps.count(p_up) == 0 || maps.count(p_up) == 1 && maps[p_up] > t)
            maps[p_up] = t;
        if (p_left != t && maps.count(p_left) == 0 || maps.count(p_left) == 1 && maps[p_left] > t)
            maps[p_left] = t;

        // cout << "up = " << up << nl;
        // cout << "left = " << left << nl;
        // cout << "t = " << t << nl;
        // cout << "maps.size() = " << maps.size() << nl;
    }
}

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
            load(i, j, b);
        }
    }

    //cout << k << " - " << maps.size() << nl;
    cout << k - maps.size() << nl;
}

//vector<vector<int>> f(1000);

// void find(int i, int j)
// {
//     if (a[i][j])
//         f[i][j] = 1;

//     if (i > 0 && a[i - 1][j] && !f[i - 1][j])
//         find(i - 1, j);

//     if (i != n - 1 && a[i + 1][j] && !f[i + 1][j])
//         find(i + 1, j);

//     if (j > 0 && a[i][j - 1] && !f[i][j - 1])
//         find(i, j - 1);

//     if (j != m - 1 && a[i][j + 1] && !f[i][j + 1])
//         find(i, j + 1);
// }

// void solve2()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         a[i] = vector<int>(m, 0);
//         f[i] = vector<int>(m, 0);
//         for (int j = 0; j < m; j++)
//         {
//             char b;
//             cin >> b;
//             a[i][j] = (b == '#' ? 0 : 1);
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//             if (a[i][j] && !f[i][j])
//             {
//                 k++;
//                 find(i, j);
//             }
//     }
//     cout << k << nl;
// }

int main()
{
    ios_b;
    solve1();
    // solve2();
    return 0;
}
