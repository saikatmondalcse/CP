// 2 D prefix sum
    
vector<vector<int>> pre(n,vector<int>(n));

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		if(i+1<n)
			pre[i+1][j]+=pre[i][j];
		if(j>0)
		pre[i][j]+=pre[i][j-1];
	}
}
auto query = [&](int x1,int y1,int x2,int y2)->int{
	int ans=pre[x2][y2];
	if(y1>0)
		ans-=pre[x2][y1-1];
	if(x1>0)
		ans-=pre[x1-1][y2];
	if(x1>0 && y1>0)
		ans+=pre[x1-1][y1-1];
	return ans;
};
