const int mod=1e9+7;

struct Matrix
{
    vector<vector<ll>> val;
    ll n_;
    Matrix (ll n) : n_(n)
    {
        val.resize(n_);
        for(ll i=0;i<n_;++i)
            val[i].resize(n_);
    }
    void print()
    {
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
                cout<<val[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set(ll x)
    {
        for(ll i=0;i<n_;++i)
            for(ll j=0;j<n_;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        ll n=n_;
        Matrix ans(n);
        ans.set(0);
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
            {
                ans.val[i][j]=0;
                for(ll k=0;k<n_;++k)
                {
                    ans.val[i][j]+=val[i][k]*b.val[k][j];
                    ans.val[i][j]%=mod;
                }
 
            }
        }
        return ans;
    }
};

Matrix I(ll n)
{
    Matrix Iden(n);
    Iden.set(0);
    for(ll i=0;i<n;++i)
        Iden.val[i][i]=1;
    return Iden;
}
