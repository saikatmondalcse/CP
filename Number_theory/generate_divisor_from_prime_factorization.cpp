
vector<int>generate_div(vector<pair<int,int>>pr) // prime and exponent {p,e} 
{
    vector<int>divisors;
    divisors.pb(1);
    for(auto p:pr)
    {
        int s=sz(divisors);
        for(int i=0;i<s;i++)
        {
            int x=divisors[i];
            int y=p.ff;
            for(int i=1;i<=p.ss;i++){
                divisors.pb(x*y);
                y*=(p.ff);
            }
        }   
    }
//     sort(all(divisors));
    return divisors;
}
