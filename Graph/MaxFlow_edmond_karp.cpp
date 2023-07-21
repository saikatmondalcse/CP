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
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<vector<ll>>cap(n+1,vector<ll>(n+1));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(b);
        adj[b].pb(a);
        cap[a][b]+=c; // cap[b][a]=0;
    }


    vector<int>parent(n+1);
    
    function<long long(int,int)>bfs=[&](int s,int t)->long long{

        fill(all(parent),-1);
        parent[s]=-2;
        queue<pair<int,ll>>q;
        q.push({s,inf});

        while(!q.empty())
        {
            int curr=q.front().first;
            ll flow=q.front().second;
            q.pop();

            for(int nxt:adj[curr])
            {
                if(parent[nxt]==-1 && cap[curr][nxt])
                {
                    parent[nxt]=curr;
                    q.push({nxt,min(flow,cap[curr][nxt])});
                    if(nxt==t)
                        return min(flow,cap[curr][nxt]);
                }

            }
        }
        return 0;
    };
    int s=1,t=n;
    ll currflow=0;
    ll totflow=0;
    while(currflow=bfs(s,t))
    {
        totflow+=currflow;
        int curr=t;
        while(curr!=s)
        {
            int prev=parent[curr];
            cap[prev][curr]-=currflow;
            cap[curr][prev]+=currflow;
            curr=prev;
        }

    }
    cout<<totflow<<"\n";

    return 0;
}
