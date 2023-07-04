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



struct P{
    int x, y;
    void read(){
        cin>>x>>y;
    }
    P operator -(const P & other) const
    {
        P res;
        res.x=x-other.x;
        res.y=y-other.y;
        return res;
    }
    void operator -=(const P &other)
    {
        x-=other.x;
        y-=other.y;
    }
    P operator +(const P & other) const
    {
        P res;
        res.x=x+other.x;
        res.y=y-other.y;
        return res;
    }
    void operator +=(const P &other)
    {
        x+=other.x;
        y+=other.y;
    }
    long long operator *(const P &other) const
    {
        return 1LL*x*other.y-1LL*y*other.x;
    }
    long long triangle(const P& other1,const P&other2)const
    {
        return (other1-*this)*(other2-*this);
    }
    bool operator <(const P &other)const
    {
        if(this->x==other.x)
            return this->y<other.y;
        else
            return this->x<other.x;
    }
    bool operator <=(const P& other)const
    {
        if(this->x==other.x)
            return this->y<other.y;
        else
            return this->x<=other.x;
    }
};

ll mxdis=9e18L;

ll dis(P a,P b)
{
    return 1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y);
}



ll cal_min(vector<P>&a,vector<P>&b)
{
    int n=sz(a);
    if(n<=1)
        return mxdis;
    vector<P>leftx(a.begin(),a.begin()+n/2);
    vector<P>rightx(a.begin()+n/2,a.end());
    P mid=leftx.back();
    vector<P>lefty,righty;
    for(P p:b)
    {
        if(p<=mid && sz(lefty)<sz(leftx))
        {
            lefty.pb(p);
        }
        else
            righty.pb(p);
    }
    ll d1=cal_min(leftx,lefty);
    ll d2=cal_min(rightx,righty);
    ll d=min(d1,d2);
    vector<P>stripe;
    for(P p:b)
    {
        if(1LL*(p.x-mid.x)*(p.x-mid.x)<d)
        {
            stripe.pb(p);
        }
    }
    for(int i=0;i<sz(stripe);i++)
    {
        for(int j=i+1;j<sz(stripe) && 1LL*(stripe[j].y-stripe[i].y)*(stripe[j].y-stripe[i].y)<d;j++)
        {
            d=min(d,dis(stripe[i],stripe[j]));
        }
    }
    return d;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<P>a(n);
    for(int i=0;i<n;i++)
        a[i].read();

    vector<P>b=a;

    sort(all(a));
    sort(all(b),[](P a,P b){return a.y<b.y;});

    cout<<cal_min(a,b);

    return 0;
}
