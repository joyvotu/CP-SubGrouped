/*
MAKE SCC
select the largest scc
prit it
*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e5 + 1;
const int mod = 1e9+7;

vector<int> g[nax];
vector<int> tg[nax];
vector<bool> visted(nax, 0);
vector<vector<int>> comp;
stack<int> s;

void dfs1(int node){
	visted[node]=1;
	for(auto child: g[node]){
		if(!visted[child]){
			dfs1(child);
		}
	}
	s.push(node);
}

void dfs2(int node, vector<int> &temp){
	visted[node]=0;

	for(auto child:tg[node]){
		if(visted[child]){
			dfs2(child, temp);
		}
	}

	temp.pb(node);
}



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		u--; v--;
		g[u].push_back(v);
		tg[v].push_back(u);
	}

	for(int i=0; i<n; i++){
		if(!visted[i]){
			dfs1(i);
		}
	}

	while(!s.empty()){
		int node = s.top();
		s.pop();
		if(visted[node]){
			vector<int> temp;
			dfs2(node, temp);
			comp.pb(temp);
			temp.clear();
		}
	}
	int id=0;
	for(int i=0; i<comp.size(); i++){
		id = comp[i].size() > comp[id].size() ? i : id;
	}
	if(comp[id].size() == 1){
		cout<<0;
		return 0;
	}
	cout<<comp[id].size()<<endl;
	sort(comp[id].begin(), comp[id].end());
	for(int i=0; i<comp[id].size(); i++){
		cout<<comp[id][i]+1<<" ";
	}
}