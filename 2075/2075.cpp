// https://cses.fi/problemset/task/2075/
#include <iostream>
#include <random>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

class TreapImplicit {
    static minstd_rand generator;

    struct Node {
        int priority, size = 1, value;
        bool rev = false;
        Node* l = nullptr, * r = nullptr, * p = nullptr;
        Node(ll _value) : priority(generator()), value(_value) {};
    } *root = nullptr;

    map<int, Node *> location;

    static int getSize(Node* n)
    {
        return n ? n->size : 0;
    }

    static void setParrent(Node* n, Node* p)
    {
        if(n) n->p = p;
    }

    static void push(Node *n)
    {
    	if(n){
    		if(n->rev)
    		{
    			swap(n->l, n->r);
    			if(n->l) n->l->rev ^=1;
	    		if(n->r) n->r->rev ^=1;
    			n->rev = false;
    		}
    	}
    }

    static void update(Node* n)
    {
        if (n)
        {
           	n->size = getSize(n->l) + 1 + getSize(n->r);
           	setParrent(n->l, n);
           	setParrent(n->r, n);
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
        setParrent(a, nullptr);
        setParrent(b, nullptr);
    }

    static int getIndex(Node *n)
    {
    	int index = getSize(n->l);
    	while(n->p)
    	{
    		if(n->p->r == n) index += getSize(n->p->l)+1;
    		n = n->p;
    	}
    	return index;
    }

public:

    ll get(int index) {
        Node* less, * greater, * equal;
        split(root, index, less, greater);
        split(greater, 1, equal, greater);
        auto result = equal->value;
        root = merge(merge(less, equal), greater);
        return result;
    }

    void pushBack(int value) {
    	location[value] = new Node(value);
        root = merge(root, location[value]);
    }

    int size() {
        return getSize(root);
    }

    void reverse(int l, int r) {
        Node* less, * greater, * equal;
        split(root, l, less, greater);
        split(greater, r - l + 1, equal, greater);
        equal->rev ^= 1;
        root = merge(merge(less, equal), greater);
    }

    int getIndex(int value)
    {
    	if(location.count(value))
    		return getIndex(location[value]);
    	else
    		return -1;
    }
};

minstd_rand TreapImplicit::generator;

void solve()
{
	int n;
	cin>>n;

	TreapImplicit t;
	for(int i=0;i<n;i++)
	{
		ll cur;
		cin>>cur;
		t.pushBack(cur);
	}

	int l=0, r = n-1;
	queue<pair<int,int>> q;
	while(r>l)
	{
		// todo
		for(int i=0;i<t.size();i++)
			int node = t.get(i);
		int pos = t.getIndex(l+1);
		if(pos!=l)
			t.reverse(l, pos), q.push({l,pos});
		l++;
	}

	cout<<q.size()<<"\n";
	while(!q.empty())
	{
		cout<<q.front().first+1<<" "<< q.front().second+1<<"\n";
		q.pop();
	}
}

int main()
{
	solve();
	return 0;
}
