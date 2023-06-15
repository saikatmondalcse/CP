const int N=1e5+5;
vector<ll> spf(N);
void spf_cal(int n)
{
    for(ll i=2;i<=n;i++)
        spf[i]=i;
       for(ll i=2;i*i<=n;i++)
       {
           if(spf[i]==i)
           {
               for(ll j=i*i;j<=n;j+=i)
               {
                   spf[j]=min(spf[j],i);
               }
           }
       }        
}
