// use ford flukerson to calculate maxflow , 
// capacity[i][j] -> will denote residual capacity of edge i-> j

// now there is no path remaining with positive capacity from s to t

// so there is a min cut , where there are some nodes that are reachable from s

// so using bfs calculate all the nodes that are reachable from s . reachable meaning there is a positive capcaity path from s to that reachable node

// so let for each u in reachable node list of s , if v is not in reachable node list of s and there is a edge between u->v then this edge is part of mincut

// this reachable nodes are already calculated in the last iteration of ford fulkerson bfs nodes that are visited





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
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        int c=1;
        cap[a][b]+=c;
        cap[b][a]+=c;
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

    vector<array<int,2>>edges;

    for(int i=1;i<=n;i++)
    {
        if(parent[i]!=-1)
        {
            for(int j:adj[i])
            {
                if(parent[j]==-1)
                {
                    edges.pb({i,j});
                }
            }

        }
    }
    assert(sz(edges)==totflow);
    cout<<sz(edges)<<"\n";
    for(auto x:edges)
        cout<<x[0]<<' '<<x[1]<<"\n";

    return 0;
}
