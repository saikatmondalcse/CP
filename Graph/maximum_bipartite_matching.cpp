
// matching b boys and g girls

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
    int B,G,m;
    cin>>B>>G>>m;
    vector<int>adj[B+1];
    for(int i=0;i<m;i++)
    {
        int b,g;
        cin>>b>>g;
        adj[b].pb(g);
    }

    vector<int>mt(G+1,-1); // mt[i] -> ith girl is matched with which boy , -1 means i th girl is free

    vector<int>vis(B+1);

    function<bool(int)>dfs=[&](int b){
        if(vis[b])
            return false;
        vis[b]=1;
        for(int g:adj[b])
        {
            if(mt[g]==-1 || dfs(mt[g])){
                mt[g]=b;
                return true;
            }
        }
        return false;
    };

    for(int i=1;i<=B;i++)
    {
        fill(all(vis),0);
        dfs(i);
    }
    vector<array<int,2>>matchings;
    for(int i=1;i<=G;i++)
    {   
        if(mt[i]!=-1)
        {
            matchings.pb({mt[i],i});
        }
    }
    cout<<sz(matchings)<<"\n";
    for(auto x:matchings)
        cout<<x[0]<<' '<<x[1]<<"\n";

    return 0;
}
