#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<string> v;

    cin >> s;

    sort(s.begin(), s.end());
    do
    {
        v.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << v.size() << endl;
    for(string s : v)
        cout << s << endl;

    return 0;
}