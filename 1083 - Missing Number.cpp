#include <bits/stdc++.h>
using namespace std;

#define ios_b                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

typedef long long ll;
typedef long double ld;

void solve()
{
  int n, x, i;
  cin >> n;
  long sum = 0;
  for (i = 0; i < n - 1; i++)
  {
    cin >> x;
    sum += x;
  }
  cout << long(n) * (n + 1) / 2 - sum << endl;
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
