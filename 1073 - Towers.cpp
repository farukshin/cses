// https://cses.fi/problemset/task/1073
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void solve()
{
    int n;
    cin >> n;
    multiset<int> st;
    while (n--) {
        int k;
        cin >> k;
        auto it = st.lower_bound(k + 1);
        if (it == st.end())
            st.insert(k);
        else {
            st.erase(it);
            st.insert(k);
        }
    }
    cout << st.size() << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif
 
    solve();
    //int t; cin >> t; while(t--) solve();
 
    return 0;
}