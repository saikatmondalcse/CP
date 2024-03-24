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
 
/*
    lps[i] -> length of longest proper prefix suffix
 
    lps[string] -> maximum length string both prefix and suffix of != s
 
    lps[i] -> lps [ s[0..i-1]]
 
 
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string t; //text
    cin>>t;
    string s; //pattern
    cin>>s;
 
 
 
 
    int n=s.length();
    int m=t.length();
 
    s+='#';
    for(int i=0;i<m;i++)
        s+=t[i];
 
    vector<int>lps(n+m+2);
 
    lps[0]=-1;
    int cnt=0;
    for(int i=1;i<=n+m+1;i++)
    {
        int k=lps[i-1];
        while(k>=0 && s[k]!=s[i-1])
        {
            k=lps[k];
        }
        lps[i]=k+1;
 
        if(i>n+1 && lps[i]==n)
        {
            // 0 based index in t -> i-2*n-1;
            cnt++;
        }
    }
 
    cout<<cnt<<"\n";
 
    return 0;
}
