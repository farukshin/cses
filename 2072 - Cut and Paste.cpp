// https://cses.fi/problemset/task/2072
#include <iostream>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class TreapImplicit {
    static minstd_rand generator;

    struct Node {
        int priority, size = 1;
        char value;
        Node* l = nullptr, * r = nullptr;
        Node(char _value) : priority(generator()), value(_value) {};
    } *root = nullptr;

    static int getSize(Node* n)
    {
        return n ? n->size : 0;
    }
    
    static void push(Node *n)
    {
    	if(n){
    		;
    	}
    }

    static void update(Node* n)
    {
        if (n)
        {
           	n->size = getSize(n->l) + 1 + getSize(n->r);
        }
    }

    static Node* merge(Node* a, Node* b) {
    	push(a);
    	push(b);
        if (!a || !b) return a ? a : b;
        if (a->priority > b->priority)
        {
            a->r = merge(a->r, b);
            update(a);
            return a;
        }
        else {
            b->l = merge(a, b->l);
            update(b);
            return b;
        }
    }

    static void split(Node* n, int k, Node*& a, Node*& b)
    {
    	push(n);
        if (!n) { a = b = nullptr; return; }
        if (getSize(n->l) < k)
        {
            split(n->r, k - getSize(n->l) - 1, n->r, b);
            a = n;
        }
        else {
            split(n->l, k, a, n->l);
            b = n;
        }
        update(a);
        update(b);
    }

public:

    char get(int index) {
        Node* less, * greater, * equal;
        split(root, index, less, greater);
        split(greater, 1, equal, greater);
        char result = equal->value;
        root = merge(merge(less, equal), greater);
        return result;
    }

    void pushBack(char value) {
        root = merge(root, new Node(value));
    }

    int size() {
        return getSize(root);
    }

    void toBack(int l, int r) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        root = merge(merge(less, greater), equal);
    }

};

minstd_rand TreapImplicit::generator;

void solve()
{
	int n,m;
	string s;
	cin>>n>>m>>s;
	TreapImplicit t;
	
	for(auto ch:s)
		t.pushBack(ch);
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		t.toBack(a-1, b-1);
	}
	
	for(int i=0;i<t.size();i++)
		cout<<t.get(i);
}

int main()
{
	solve();
	return 0;
}

