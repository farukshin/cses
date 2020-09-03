//https://cses.fi/problemset/task/1753
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int ALPHABET_SIZE = 26;

struct vertex
{
    vertex* next[ALPHABET_SIZE];
    vertex* go[ALPHABET_SIZE];
    vertex* link = 0;
    vertex* parent;
    vertex* prev;
    int parent_char;
    vector<int> ind;

    vertex();
    vertex(int parent_char, vertex* parent);
};

vertex::vertex()
{
    parent_char = 0;
    parent = nullptr;
    prev = nullptr;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        next[i] = nullptr;
        go[i] = nullptr;
    }
}

vertex::vertex(int parent_char, vertex* parent)
{
    this->parent_char = parent_char;
    this->parent = parent;
    prev = nullptr;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        next[i] = nullptr;
        go[i] = nullptr;
    }
}

vertex* root = new vertex(-1, 0);

void add_string(string& line, int ind)
{
    vertex* current = root;
    int n = line.length();
    for (int i = 0; i < n; ++i)
    {
        int symbol = line[i] - 'a';
        if (current->next[symbol] == nullptr)
        {
            current->next[symbol] = new vertex(symbol, current);
        }
        current = current->next[symbol];
    }
    current->ind.push_back(ind);
}

vertex* go(vertex* current, int c);

vertex* link(vertex* current)
{
    if (!current->link)
    {
        if (current == root || current->parent == root)
        {
            current->link = root;
        }
        else
        {
            current->link = go(link(current->parent), current->parent_char);
        }
    }
    return current->link;
}

vertex* go(vertex* current, int c)
{
    if (!current->go[c])
    {
        if (current->next[c])
        {
            current->go[c] = current->next[c];
        }
        else if (current == root)
        {
            current->go[c] = root;
        }
        else
        {
            current->go[c] = go(link(current), c);
        }
    }
    return current->go[c];
}

vertex* prev(vertex* current)
{
    if (current == root)
    {
        return nullptr;
    }
    if (!current->prev)
    {
        if (link(current)->ind.size() != 0)
        {
            current->prev = link(current);
        }
        else
        {
            current->prev = prev(link(current));
        }
    }
    return current->prev;
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;

    add_string(pattern, 0);

    vector<vector<int>> ans(1);
    vertex* cur = root;
    for (int i = 0; i < text.size(); i++)
    {
        cur = go(cur, text[i] - 'a');
        vertex* cur_ans = cur;
        while (cur_ans)
        {
            for (int ind : cur_ans->ind)
                ans[ind].push_back(i + 1);
            cur_ans = prev(cur_ans);
        }
    }

    cout << ans[0].size() << endl;

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
