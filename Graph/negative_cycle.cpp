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
    vector<array<int,3>>edges(m);
    for(int i=0;i<m;i++)
    {
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
 
    vector<ll>dp(n+1,0); 
    vector<ll>parent(n+1,0);
    int relax_node=-1;
    for(int phase=0;phase<n;phase++)
    {
        relax_node=-1;
        for(auto [from,to,w]:edges)
        {
            if(dp[to]>dp[from]+w)
            {
                dp[to]=dp[from]+w;
                parent[to]=from;
                relax_node=to;
            }
        }
        if(relax_node==-1)
            break;
    }
 
    if(relax_node==-1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n";
        vector<int>cycle;
        vector<int>vis(n+1);
 
        while(!vis[relax_node]) // to find starting node of cycle , this loop will run atmost n times
        {
            vis[relax_node]=1;
            relax_node=parent[relax_node];
        }
 
        int curr=relax_node;
 
        do{
            cycle.pb(curr);
            curr=parent[curr];
        }
        while(curr!=relax_node);
 
        cycle.pb(relax_node);
        reverse(all(cycle));
        for(auto x:cycle)
            cout<<x<<" ";
 
    }
  
    return 0;
}
