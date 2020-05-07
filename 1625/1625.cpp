//https://cses.fi/problemset/task/1625
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

struct at
{
    int x;
    int y;
    int step;
};

void solve()
{
    int ans = 0;
    string s;
    cin >> s;

    const int MAXARR = 9;
    int used[MAXARR][MAXARR];

    for (int i = 0; i < MAXARR; i++)
        for (int j = 0; j < MAXARR; j++)
            if (i == 0 || j == 0 || i == MAXARR - 1 || j == MAXARR - 1)
                used[i][j] = 50;
            else
                used[i][j] = 0;

    stack<at> st;
    st.push({7, 1, 48});
    while (!st.empty())
    {
        at cur = st.top();
        st.pop();
        if (cur.step == 0 && cur.x == 1 && cur.y == 1)
            ans++;
        if (cur.step == 0)
            continue;
        used[cur.x][cur.y] = cur.step;

        int x_next = cur.x, y_next = cur.y, step_next = cur.step - 1;

        if (s[cur.step - 1] == '?')
        {
            if (used[x_next - 1][y_next] < step_next)
                st.push({x_next - 1, y_next, step_next});
            if (used[x_next + 1][y_next] < step_next)
                st.push({x_next + 1, y_next, step_next});
            if (used[x_next][y_next - 1] < step_next)
                st.push({x_next, y_next - 1, step_next});
            if (used[x_next][y_next + 1] < step_next)
                st.push({x_next, y_next + 1, step_next});
        }
        else
        {
            if (s[cur.step - 1] == 'L')
                x_next++;
            else if (s[cur.step - 1] == 'R')
                x_next--;
            else if (s[cur.step - 1] == 'U')
                y_next--;
            else if (s[cur.step - 1] == 'D')
                y_next++;

            if (used[x_next][y_next] < step_next)
                st.push({x_next, y_next, step_next});
        }
    }

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
