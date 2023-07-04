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
};
 
 
bool segment_contains(P p1,P p2,P p3)
{
	if(p1.triangle(p2,p3)==0) // collinear
	{
		return (min(p1.x,p2.x)<=p3.x && p3.x<=max(p1.x,p2.x) && min(p1.y,p2.y)<=p3.y && p3.y<=max(p1.y,p2.y));  
	}
	else
		return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<P>polygon(n);
    for(int i=0;i<n;i++)
    	polygon[i].read();
 
	while(m--)
	{
		P k;
		k.read();
	    bool on_boundary=false;
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	    	// vertical ray slightly tilted to the right 
	    	// vertice.x <= k.x -> left
	    	// vertice.x > k.x -> right
	    	P curr=polygon[i],nxt=polygon[(i+1)%n];
	    	if(curr.x<=k.x && nxt.x>k.x)
	    	{
	    		// curr is left and nxt is right , segment should be above point k
	    		if(k.triangle(curr,nxt)<0)
	    			cnt++;
	    	}
	    	else if(curr.x>k.x && nxt.x<=k.x)
	    	{
	    		// nxt is left and curr is right , segment should be above point k
	    		if(k.triangle(nxt,curr)<0)
	    			cnt++;
	    	}
	    	if(segment_contains(curr,nxt,k))
	    		on_boundary=true;
	    }
	    if(on_boundary)
	    	cout<<"BOUNDARY\n";
	    else if(cnt%2==1)
	    	cout<<"INSIDE\n";
	    else
	    	cout<<"OUTSIDE\n";
	}
    return 0;
}
