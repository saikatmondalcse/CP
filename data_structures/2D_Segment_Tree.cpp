template<typename T>
struct SegTree{

    vector<vector<T>>tree;
    T ne=0; // change neutral
    int sze;

    T combine(T a,T b)
    {
        T c=a+b;  // operation
        return c;
    }
    void build(vector<vector<int>>&a)
    {
        int n1=sz(a);
        int m=sz(a[0]);
        int n=max(n1,m);
        sze=n;  
        while(sze&(sze-1))
        {
            sze++;
        }
        tree.resize(2*sze,vector<T>(2*sze));

        for(int i=0;i<sze;i++)
        {
            for(int j=0;j<sze;j++)
            {
                if(i<n1 && j<m)
                    tree[sze+i][sze+j]=a[i][j];
                else
                    tree[sze+i][sze+j]=ne;
            }
            for(int j=sze-1;j>=1;j--)
            {
                tree[sze+i][j]=combine(tree[sze+i][2*j],tree[sze+i][2*j+1]);
            }
        }

        for(int i=sze-1;i>=1;i--)
        {
            for(int j=2*sze-1;j>=1;j--)
            {
                tree[i][j]=combine(tree[2*i][j],tree[2*i+1][j]);
            }
        }
    }

    T queryj(int vi,int sj,int ej,int lj,int rj,int vj){

        if(sj>rj || ej<lj)
            return ne;
        else if(sj>=lj && ej<=rj)
            return tree[vi][vj];
        else
        {
            int mid=(sj+ej)/2;
            T left=queryj(vi,sj,mid,lj,rj,2*vj);
            T right=queryj(vi,mid+1,ej,lj,rj,2*vj+1);
            return combine(left,right);
        }

    }

    T queryi(int si,int ei,int li,int ri,int lj,int rj,int vi)
    {
        if(si>ri || ei<li)
            return ne;
        else if(si>=li && ei<=ri){
            return queryj(vi,0,sze-1,lj,rj,1);
        }
        else
        {
            int mid=(si+ei)/2;
            T left=queryi(si,mid,li,ri,lj,rj,2*vi);
            T right=queryi(mid+1,ei,li,ri,lj,rj,2*vi+1);
            return combine(left,right);
        }
    }

    void Pupdate(int i,int j,T val)
    {
        tree[sze+i][sze+j]+=val;
        for(int j1=(sze+j)/2;j1>=1;j1/=2)
        {
            tree[sze+i][j1]=combine(tree[sze+i][2*j1],tree[sze+i][2*j1+1]);
        }
        for(int i1=(sze+i)/2;i1>=1;i1/=2)
        {
           for(int j1=(sze+j);j1>=1;j1/=2)
            {
                tree[i1][j1]=combine(tree[2*i1][j1],tree[2*i1+1][j1]);
            }
        }
    }
};
