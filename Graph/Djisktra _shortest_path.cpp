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
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
    }
 
    ll inf=1e18L;
    vector<ll>dp(n+1,inf); 
    // dp[i] -> shortest distance from source to node i
 
    int src=1;
 
    dp[src]=0;
 
    priority_queue<pair<ll,int>>pq;
    pq.push({-dp[src],src});
 
    while(!pq.empty())
    {
        ll curr_cost=-pq.top().ff,curr=pq.top().ss;
        pq.pop();
 
        if(curr_cost>dp[curr])
            continue;
 
        for(auto nxt:adj[curr])
        {
            ll next_cost=curr_cost+nxt.ss;
            if(dp[nxt.ff]>next_cost)
            {
                dp[nxt.ff]=next_cost;
                pq.push({-dp[nxt.ff],nxt.ff});
            }
        }
    }
 
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
  
 
    return 0;
}
