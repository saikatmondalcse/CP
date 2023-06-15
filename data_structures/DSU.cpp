vector<int>par;
vector<int>siz;
 
void make_set(int n)
{
    par.resize(n);
    siz.resize(n);
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        siz[i]=1;
    }
}
 
int find_set(int node)
{
    if(node==par[node])
        return node;
    else
    {
        return par[node]=find_set(par[node]);
    }
}
 
void union_sets(int u,int v)
{
 
    u=find_set(u);
    v=find_set(v);
    if(u==v)
        return;
    if(siz[u]>siz[v])
        swap(u,v);
    par[u]=v;
    siz[v]+=siz[u];
    siz[u]=0;
}
