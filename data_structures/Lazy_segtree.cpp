// range update -> set [L...R]  to x
// range query  -> calculate sum from [L....R]

template<typename T>
struct SegTree{

    vector<T>tree;
    T ne=0; // change neutral
    int sze;
    vector<bool>lazy;
    vector<int>lazyvalue;
    T combine(T a,T b)
    {
        T c=a+b;  // operation
        return c;
    }
    void build(vector<int>a)
    {
        int n=sz(a);
        int ne2=0; // change neutral element of array
        sze=n;  
        while(sze&(sze-1))
        {
            sze++;
        }
        tree.resize(2*sze);
        lazy.resize(2*sze,false);
        lazyvalue.resize(2*sze);
        for(int i=0;i<sze;i++)
        {
            if(i<n)
                tree[sze+i]=a[i];
            else
                tree[sze+i]=ne2;
        }
        for(int i=sze-1;i>=1;i--)
        {
         tree[i]=combine(tree[2*i],tree[2*i+1]);
        }
    }



//::::::::::: range update range query:::::::::::::::::::::

//::::::::: assign l to r to x and find sum from l to r

    void Rupdate(int s,int e,int l,int r,int i,ll a)
    {
        if(lazy[i])
        {
            tree[i]=(e-s+1)*lazyvalue[i];
            if(s!=e)
            {
                lazy[2*i]=1;
                lazyvalue[2*i]=lazyvalue[i];
                lazy[2*i+1]=1;
                lazyvalue[2*i+1]=lazyvalue[i];
            }
            lazy[i]=0;
            lazyvalue[i]=0;
        }
        if(s>r || e<l)
            return;
        else if(s>=l && e<=r)
        {
            tree[i]=(e-s+1)*a;
            if(s!=e)
            {
                lazy[2*i]=1;
                lazyvalue[2*i]=a;
                lazy[2*i+1]=1;
                lazyvalue[2*i+1]=a;
            }
        }
        else
        {
            int mid=(s+e)/2;
            Rupdate(s,mid,l,r,2*i,a);
            Rupdate(mid+1,e,l,r,2*i+1,a);
            tree[i]=combine(tree[2*i],tree[2*i+1]);
        }
    }

    T query(int s,int e,int l,int r,int i)
    {

        if(lazy[i])
        {
            tree[i]=(e-s+1)*lazyvalue[i];
            if(s!=e)
            {
                lazy[2*i]=1;
                lazyvalue[2*i]=lazyvalue[i];
                lazy[2*i+1]=1;
                lazyvalue[2*i+1]=lazyvalue[i];
            }
            lazy[i]=0;
            lazyvalue[i]=0;
        }
        if(s>r || e<l)
            return ne;
        else if(s>=l && e<=r)
        {
            return tree[i];
        }
        else
        {
            int mid=(s+e)/2;
            T left=query(s,mid,l,r,2*i);
            T right=query(mid+1,e,l,r,2*i+1);
            return combine(left,right);
        }
    }

};


//:::::::::::::::: type -2 :::::::::::::::::::::::::::::::
// range update -> add x to [L...R]  
// range query  -> calculate min from [L....R]


template<typename T>
struct SegTree{

    vector<T>tree;
    T ne=1e18L; // change neutral
    int sze;
    vector<bool>lazy;
    vector<ll>lazyvalue;
    T combine(T a,T b)
    {
        T c=min(a,b);  // operation
        return c;
    }
    void build(vector<int>a)
    {
        int n=sz(a);
        ll ne2=1e18L; // change neutral element of array
        sze=n;  
        while(sze&(sze-1))
        {
            sze++;
        }
        tree.resize(2*sze);
        lazy.resize(2*sze,false);
        lazyvalue.resize(2*sze);
        for(int i=0;i<sze;i++)
        {
            if(i<n)
                tree[sze+i]=a[i];
            else
                tree[sze+i]=ne2;
        }
        for(int i=sze-1;i>=1;i--)
        {
         tree[i]=combine(tree[2*i],tree[2*i+1]);
        }
    }



//::::::::::: range update range query:::::::::::::::::::::

//::::::::: increment l to r to by x and find min from l to r

    void Rupdate(int s,int e,int l,int r,int i,ll a)
    {
        if(lazy[i])
        {
            tree[i]+=lazyvalue[i];
            if(s!=e)
            {
                lazy[2*i]=1;
                lazyvalue[2*i]+=lazyvalue[i];
                lazy[2*i+1]=1;
                lazyvalue[2*i+1]+=lazyvalue[i];
            }
            lazy[i]=0;
            lazyvalue[i]=0;
        }
        if(s>r || e<l)
            return;
        else if(s>=l && e<=r)
        {
            tree[i]+=a;
            if(s!=e)
            {
                lazy[2*i]=1;
                lazyvalue[2*i]+=a;
                lazy[2*i+1]=1;
                lazyvalue[2*i+1]+=a;
            }
        }
        else
        {
            int mid=(s+e)/2;
            Rupdate(s,mid,l,r,2*i,a);
            Rupdate(mid+1,e,l,r,2*i+1,a);
            tree[i]=combine(tree[2*i],tree[2*i+1]);
        }
    }

    T query(int s,int e,int l,int r,int i)
    {

        if(lazy[i])
        {
            tree[i]+=lazyvalue[i];
            if(s!=e)
            {
                lazy[2*i]=1;
                lazyvalue[2*i]+=lazyvalue[i];
                lazy[2*i+1]=1;
                lazyvalue[2*i+1]+=lazyvalue[i];
            }
            lazy[i]=0;
            lazyvalue[i]=0;
        }
        if(s>r || e<l)
            return ne;
        else if(s>=l && e<=r)
        {
            return tree[i];
        }
        else
        {
            int mid=(s+e)/2;
            T left=query(s,mid,l,r,2*i);
            T right=query(mid+1,e,l,r,2*i+1);
            return combine(left,right);
        }
    }
};
