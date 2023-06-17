template<typename T>
struct SegTree{

    vector<T>tree;
    T ne=0; // change neutral
    int sze;

    T combine(T a,T b)
    {
        T c=a+b;  // operation
        return c;
    }
    void build(vector<ll>a)
    {
        int n=sz(a);
        ll ne2=0; // change neutral element of array
        sze=n;  
        while(sze&(sze-1))
        {
            sze++;
        }
        tree.resize(2*sze);
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

//::::::::::: point update range query:::::::::::::::::::::

    T query(int s,int e,int l,int r,int i)
    {
        if(s>r || e<l)
            return ne;
        else if(s>=l && e<=r)
            return tree[i];
        else
        {
            int mid=(s+e)/2;

            T left=query(s,mid,l,r,2*i);
            T right=query(mid+1,e,l,r,2*i+1);
            return combine(left,right);
        }
    }

    void Pupdate(int i,T val)
    {
        tree[sze+i]=val;

        for(int j=(sze+i)/2;j>=1;j/=2)
        {
            tree[j]=combine(tree[2*j],tree[2*j+1]);
        }
    }

//::::::::::: for range update and point query :::::::::::::::::::
 
    void static_range_update(int s,int e,int l,int r,int i,ll ax,ll dx){
 
        if(s>r || e<l)
            return;
        else if(s>=l && e<=r)
        {
            // tree[i] do operation lazily
        }
        else
        {
            int mid=(s+e)/2;
            static_range_update(s,mid,l,r,2*i,ax,dx);
            static_range_update(mid+1,e,l,r,2*i+1,ax,dx);
        }
    }
 
    T range_point_query(int i)
    {
        T inc=0;

        int l=i,r=i;
        int j=(sze+i);
        int k=1;
        for(j;j>=1;j/=2)
        {
            // l and r of current node
            // tree[j].ai+(tree[j].l-i)*tree[j].di // add ap
            // inc+=(tree[j].ai+(i-l)*tree[j].di);
            
            if(j&1)
            {
                l-=k;  
            }
            else
                r+=k;
            k*=2;
        }

        return inc;
    } 

};
