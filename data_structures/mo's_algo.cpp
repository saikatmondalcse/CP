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

int B;

struct Qr{
    int l,r,idx;

    inline pair<int,int>toPair()const
    {
        return make_pair(l/B,((l/B)&1)?r:-r);
    }

    inline bool operator<(const Qr &other)const
    {
        return toPair()<other.toPair();
    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    vector<Qr>qr(q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        --l,--r;
        qr[i]={l,r,i};
    }

    B=(int)sqrt(n);
    sort(all(qr));


    vector<ll>res(q);
    int mo_l=0,mo_r=-1;
    ll ans=0;

    for(int i=0;i<q;i++)
    {
        int l=qr[i].l,r=qr[i].r,idx=qr[i].idx;
        // deb2(l,r);

        while(mo_r<r)
        {
            mo_r++;
            //add

        }

        while(mo_r>r)
        {
            //remove

        }
        while(mo_l<l)
        {
            //remove

        }

        while(mo_l>l)
        {
            --mo_l;
            //add

        }
        res[idx]=ans;
    }

    for(auto x:res)
        cout<<x<<"\n";


    return 0;
}
