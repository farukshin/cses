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
  string s;
  cin >> s;
  char c = s[0];
  int k = 1;
  int m = 1;
  for (int i = 1; i < s.size(); i++)
  {
    if (s[i] == c)
      k++;
    else
    {
      m = max(m, k);
      k = 1;
      c = s[i];
    }
  }
  cout << max(m, k) << endl;
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
