struct MergeSortTree{

    vector<vector<int>>tree;
    int sze;

    vector<int>combine(vector<int>& a,vector<int>& b)
    {
        vector<int>c;
        int i=0,j=0;
        while(i<sz(a) && j<sz(b))
        {
            if(a[i]<=b[j])
                c.pb(a[i]),i++;
            else
                c.pb(b[j]),j++;
        }
        while(i<sz(a))
            c.pb(a[i]),i++;
        while(j<sz(b))
            c.pb(b[j]),j++;
        return c;
    }
    void build(vector<int>a)
    {
        int n=sz(a);
        sze=n;  
        while(sze&(sze-1))
        {
            sze++;
            a.pb(0);
        }
        tree.resize(2*sze);
        for(int i=0;i<sze;i++)
        {
            tree[sze+i]={a[i]};
        }
        for(int i=sze-1;i>=1;i--)
        {
            tree[i]=combine(tree[2*i],tree[2*i+1]);
        }
    }

    int get(int i,int k)
    {
        // <k
        return lower_bound(all(tree[i]),k)-tree[i].begin();
    }

    int query(int l, int r,int k){
        l+=sze; r+=sze;
        int resl=0, resr=0;
        while(l and l<=r) {
            if(l%2==1) resl+=get(l++,k);
            if(r%2==0) resr+=get(r--,k);
            l/=2; r/=2;
        }
        return resl+resr;
    }
};
