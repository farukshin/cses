// https://cses.fi/problemset/task/2074
#include <iostream>
#include <random>

using namespace std;
typedef long long ll;

class TreapImplicit {
    static minstd_rand generator;

    struct Node {
        int priority, size = 1;
        ll value, sum;
        bool rev = false;
        Node* l = nullptr, * r = nullptr;
        Node(ll _value) : priority(generator()), value(_value), sum(_value) {};
    } *root = nullptr;

    static int getSize(Node* n)
    {
        return n ? n->size : 0;
    }
    
    static ll getSum(Node* n)
    {
        return n ? n->sum : 0;
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
           	n->sum = getSum(n->l) + n->value + getSum(n->r);
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

    ll get(int index) {
        Node* less, * greater, * equal;
        split(root, index, less, greater);
        split(greater, 1, equal, greater);
        auto result = equal->value;
        root = merge(merge(less, equal), greater);
        return result;
    }

    void pushBack(ll value) {
        root = merge(root, new Node(value));
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
    
    ll sum(int l, int r)
    {
    	Node *less, *greater, *equal;
    	split(root, l, less, greater);
    	split(greater, r-l+1, equal, greater);
    	ll res = equal->sum;
    	root = merge(merge(less, equal), greater);
    	return res;
    }
};

minstd_rand TreapImplicit::generator;

void solve()
{
	int n,q;
	cin>>n>>q;
	
	TreapImplicit t;
	for(int i=0;i<n;i++)
	{
		ll cur; 
		cin>>cur;
		t.pushBack(cur);
	}
	
	for(int i=0;i<q;i++)
	{
		int c,l,r;
		cin>>c>>l>>r;
		--l,--r;
		if(c==1)
			t.reverse(l, r);
		else if(c==2) 
			cout<<t.sum(l, r)<<"\n";
	}
}

int main()
{
	solve();
	return 0;
}

