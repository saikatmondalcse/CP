struct Edge{
    int from,to,rev,cap; // from variable redundant
};

int inf=1e9;


struct MaxFlow{
    vector<Edge>e;
    int V;
    vector<vector<int>>adj;
    vector<int>par;
    MaxFlow(int mxV){
        V=mxV;
        adj.resize(V+1);  
        par.resize(V+1,-1); 
    }
    void addEdge(int fr,int t,int cap){
        int s=e.size();
        e.pb({fr,t,s+1,cap});
        e.pb({t,fr,s,0});  // for undirected change 0 to cap
        adj[fr].pb(s);
        adj[t].pb(s+1);
    }
    int bfs(int S,int T)
    {
        fill(all(par),-1);
        queue<pair<int,int>>q;
        par[S]=0; 
        q.push({S,inf});
        while(!q.empty()){
            int curr=q.front().ff,F=q.front().ss;
            // deb(curr);
            q.pop();
            for(auto i:adj[curr]){
                // deb2(e[i].to,e[i].cap);
                if(par[e[i].to]==-1 && e[i].cap>0){
                    par[e[i].to]=i;
                    int nF=min(F,e[i].cap);
                    if(e[i].to==T)
                        return nF;
                    q.push({e[i].to,nF});
                }
            }
        }
        return 0;
    }
    ll getMaxFlow(int S,int T){
        ll totF=0;
        while(1){
            int F=bfs(S,T);
            if(F==0)
                break;
            int x=T;
            while(x!=S){
                e[par[x]].cap-=F;
                e[e[par[x]].rev].cap+=F;
                x=e[par[x]].from;
            }
            totF+=F;
       }
       return totF;
    }

};
