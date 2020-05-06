//https://cses.fi/problemset/task/1092
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

ll arif_prog(ll n)
{
    return (n + 1) * n / 2;
}

void print_stack(stack<int> st)
{
    if (st.size())
    {
        cout << st.size() << endl;
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}

void solve()
{
    int n;
    cin >> n;
    ll sum = arif_prog(n);

    if (sum % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    stack<int> st1, st2;
    sum /= 2;

    while (n)
    {
        if (sum >= n)
        {
            st1.push(n);
            sum -= n;
        }
        else
            st2.push(n);

        n--;
    }

    print_stack(st1);
    print_stack(st2);
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
