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

    int n,m;
    cin>>n>>m;
    vector<array<int,2>>edges(m);
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>edges[i][0]>>edges[i][1];
        adj[edges[i][0]].push_back({edges[i][1],i});
        adj[edges[i][1]].push_back({edges[i][0],i});
    }
    // low[u] -> minimum value of some node in subtree of u such that there is a backedge from that node to u or ancestor of u(which is upmost in dfs tree)

    int timer=0;
    vector<int>vis(n+1);
    vector<int>in_time(n+1);
    vector<int>low(n+1);
    vector<bool>is_bridge(m);
    function<void(int,int)>dfs=[&](int curr,int p)
    {
    	vis[curr]=1;
    	in_time[curr]=timer++;
    	low[curr]=in_time[curr];
    	for(auto nxt:adj[curr])
    	{
    		if(nxt.first==p)
    			continue;
    		if(!vis[nxt.first])
    		{
    			dfs(nxt.first,curr);
    		}
    		else
    		{
    			// backedge from curr to nxt.first
    			low[curr]=min(low[curr],in_time[nxt.first]);
    		}
            
			low[curr]=min(low[curr],low[nxt.first]);
			if(low[nxt.first]>in_time[curr])
			{
				is_bridge[nxt.second]=true;
			}
    	}
    };
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,-1);
    }
    for(int i=0;i<m;i++)
    {
        if(is_bridge[i])
        {
            cout<<edges[i][0]<<" "<<edges[i][1]<<"\n";
        }
    }

    return 0;
}
