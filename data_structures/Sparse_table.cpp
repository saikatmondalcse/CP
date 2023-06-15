
int LOG=__lg(n); 
vector<vector<int>> sptable(n,vector<int>(LOG+1));
for(int i=0;i<=LOG;i++)
{
    for(int j=0;j+(1<<i)-1<n;j++)
    {
        if(i==0)
            sptable[j][i]=arr[j];
        else
            sptable[j][i]=min(sptable[j][i-1],sptable[j+(1<<(i-1))][i-1]);
    }
}
auto query = [&](int l,int r)->int{
    int len= r-l+1;
    int sp2=__lg(len);
    return min(sptable[l][sp2],sptable[r-(1<<sp2)+1][sp2]);
};
