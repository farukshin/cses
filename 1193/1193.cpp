#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <class T>
void ckmin(T &a, T b) { a = min(a, b); }
template <class T>
void ckmax(T &a, T b) { a = max(a, b); }

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
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
#define fori(i, n) for (ll i = 0; i < n; i++)
#define forj(j, m) for (ll j = 0; j < m; j++)

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

struct pnt
{
    int i = -1;
    int j = -1;
};
struct rd
{
    pnt begin;
    pnt end;
    char ch;
};

ll n = 0, m = 0;
vector<string> a(1000);
vector<vector<bool>> p(1000);
queue<pnt> q;
stack<rd> road;

void check(pnt point, int i, int j, char ch)
{
    if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || p[i][j])
        return;

    if (a[i][j] == '.' || a[i][j] == 'B')
    {
        pnt end;
        end.i = i;
        end.j = j;
        q.push(end);
        p[i][j] = true;

        rd l = {point, end, ch};
        road.push(l);
        return;
    }
}

void solve()
{
    cin >> n >> m;
    char x;
    pnt point;
    pnt point_req;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = vector<bool>(m, false);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                p[i][j] = true;
            }
            else if (a[i][j] == 'A')
            {
                point.i = i;
                point.j = j;
                q.push(point);
                p[i][j] = true;
            }
            else if (a[i][j] == 'B')
            {
                point_req.i = i;
                point_req.j = j;
            }
        }
    }

    while (!q.empty())
    {
        pnt point = q.front();
        q.pop();

        if (point.i == point_req.i && point.j == point_req.j)
            break;

        check(point, point.i + 1, point.j, 'D');
        check(point, point.i - 1, point.j, 'U');
        check(point, point.i, point.j + 1, 'R');
        check(point, point.i, point.j - 1, 'L');
    }

    string comand;
    while (!road.empty())
    {
        rd rdc = road.top();
        road.pop();
        if (rdc.end.i == point_req.i && rdc.end.j == point_req.j)
        {
            point_req = rdc.begin;
            comand += rdc.ch;
        }
    }

    if (comand.size())
    {
        reverse(comand.begin(), comand.end());
        cout << "YES" << nl << comand.size() << nl << comand << nl;
    }
    else
        cout << "NO" << nl;
}

int main()
{
    ios_b;
    solve();
    return 0;
}