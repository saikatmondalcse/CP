// problem link -> https://cses.fi/problemset/task/1679
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
typedef long long ll;
 
#ifndef ONLINE_JUDGE
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define deb2(x,y) cout<<"[ "<<#x<<"="<<x<<","<<#y<<"="<<y<<" ]\n"
#define deba(x,n) cout<<#x<<": [ ";for(int i=0;i<n;i++){cout<<x[i]<<" ";}cout<<"]\n";
#define deba2(x,n,m) cout<<#x<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<x[i][j]<<" ";cout<<"\n";};
#define debe(x) cout<<#x<<":[ ";for(auto i:x){cout<<i<<" ";}cout<<"]\n";
#else
#define deb(x)
#define deb2(x,y)
#define deba(x,n)
#define deba2(x,n,m)
#define debe(x)
#endif
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	vector<int>indegree(n+1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		indegree[b]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0){
			q.push(i);
		}
	}
	vector<int>topo_sort;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		topo_sort.pb(curr);
		for(int nxt:adj[curr])
		{
			indegree[nxt]--;
			if(indegree[nxt]==0)
				q.push(nxt);
		}
	}
	if(sz(topo_sort)==n)
	{
		for(auto x:topo_sort)
			cout<<x<<" ";
	}
	else // cycle exists
		cout<<"IMPOSSIBLE\n";
 
	return 0;
}
