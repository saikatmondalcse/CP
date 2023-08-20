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




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    set<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	adj[a].insert(b); // no edge between a and b in original graph
    	adj[b].insert(a);
    }

    set<int>notvisited;
    for(int i=1;i<=n;i++)
    {
   		notvisited.insert(i);
    }
    int cc=0;
    function<void(int)>dfs=[&](int curr){
    	++cc;
       	notvisited.erase(curr);
    	auto it=notvisited.begin();
    	while(1)
    	{
    		if(it==notvisited.end())
    			break;
    		int nxt=*it;
    		if(!adj[curr].count(nxt))
    		{
    			dfs(nxt);
    		}
    		it=notvisited.upper_bound(nxt);
    	}
    };

    vector<int>components;
   	for(int i=1;i<=n;i++)
   	{
   		if(notvisited.count(i)){
   			cc=0;
   			dfs(i);
   			components.pb(cc);
   		}
   	}
   	sort(all(components));
   	cout<<sz(components)<<"\n";
   	for(auto x:components)
   		cout<<x<<" ";

    return 0;
}
