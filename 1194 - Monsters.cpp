//https://www.e-olymp.com/ru/problems/7818
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int runX[4] = {0, 1, 0, -1};
int runY[4] = {1, 0, -1, 0};

map<pair<int,int>, char> mp = {
	{{0,1}, 'R'},
	{{0,-1}, 'L'},
	{{1,0}, 'D'},
	{{-1,0}, 'U'}
};

void solve()
{
    int n,m;
    cin>>n>>m;
    string v[n];
    bool used[n][m];
    int len[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) len[i][j] = INT_MAX;
    //memset(len, 0, sizeof len);
    memset(used, false, sizeof used);
    
    queue<tuple<bool, int,int>> q;
    int ma=-1, mb=-1;
    for(int i=0;i<n;i++)
    {
    	cin>>v[i];
    	for(int j=0;j<int(v[i].size());j++)
    		if(v[i][j]=='M') q.push({true, i, j}), used[i][j] = true;
    		else if(v[i][j]=='A') ma=i, mb=j, used[i][j] = true, len[i][j]=0;
    }
    assert(ma!=-1 && mb!=-1);
    if(ma == 0 || ma==n-1 || mb==0 || mb==m-1)
    {
        cout<<"YES\n0"; return;
    }
    
    
    q.push({false, ma, mb});
    
    while(!q.empty())
    {
    	auto cur = q.front();
    	q.pop();
    	auto&[isMonster, a, b] = cur;
    	for(int i=0;i<4;i++)
    	{
    		int aa = a+runX[i];
    		int bb = b+runY[i];
    		bool isArea = aa>=0&&aa<n&&bb>=0&&bb<m;
    		if(!isArea || v[aa][bb] == '#' || used[aa][bb]) continue;
    		
    		used[aa][bb] = true;
    		q.push({isMonster, aa, bb});
    		
    		if(!isMonster)
    			len[aa][bb] = len[a][b]+1;
    		
    		if(!isMonster && (aa==0 || aa==n-1 || bb==0 || bb==m-1) && v[aa][bb]=='.')
    		{
    			cout<< "YES"<<"\n";
    			stack<char> st;
    			while(true)
    			{
    			    if(aa==ma && bb==mb) break;
    				for(int k=0;k<4;k++)
    				{
    					int aaa = aa + runX[k];
    					int bbb = bb + runY[k];
    					bool isArea = aaa>=0&&aaa<n&&bbb>=0&&bbb<m;
    					if(!isArea) continue;
    					
    					if(len[aa][bb] == len[aaa][bbb]+1)
    					{
    						st.push(mp[{aa-aaa, bb-bbb}]);
    						aa=aaa, bb=bbb;
    						break;
    					}
    				}
    			}
    			cout<<st.size()<<"\n";
    			while(!st.empty())
    				{cout<<st.top(); st.pop();}
    			return;
    		}
    	}
    }
    cout<<"NO";
}

int main()
{
    //ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    solve();
    //int t; cin >> t; while(t--) solve();

    return 0;
}