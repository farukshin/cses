#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

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
        cout << "YES" << endl << comand.size() << endl << comand << endl;
    }
    else
        cout << "NO" << endl;
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
