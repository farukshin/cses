#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

char s[1000000];
char m[1000000];

int main()
{
    cin >> s >> m;
    if (strlen(s) < strlen(m))
        cout << 0 << endl;
    
    return 0;
}