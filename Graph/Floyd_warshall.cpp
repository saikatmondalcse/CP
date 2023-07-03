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
ll inf=1e18L;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,inf));
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=min(dp[u][v],1LL*w);
        dp[v][u]=min(dp[v][u],1LL*w);
 
    }
 
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
 
    for(int intermediate_node=1;intermediate_node<=n;intermediate_node++)
    {
        for(int from=1;from<=n;from++)
        {
            for(int to=1;to<=n;to++)
            {
                if(dp[from][intermediate_node]!=inf && dp[intermediate_node][to]!=inf)
                {
                    dp[from][to]=min(dp[from][to],dp[from][intermediate_node]+dp[intermediate_node][to]);
                }
            }
        }
    }
 
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(dp[a][b]==inf)
            cout<<"-1\n";
        else
            cout<<dp[a][b]<<"\n";
    }
 
 
    return 0;
}
