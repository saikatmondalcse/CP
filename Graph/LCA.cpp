int LOG=__lg(n);
vector<int>tin(n+1);	
vector<int>tout(n+1);

vector<vector<int>>dp(n+1,vector<int>(LOG+1));

int timer=0;
function<void(int,int)>dfs=[&](int curr,int p)
{
	tin[curr]=++timer;
	dp[curr][0]=p;
	for(auto child:adj[curr])
	{
		if(child!=p)
			dfs(child,curr);
	}
	tout[curr]=++timer;
};

dfs(1,-1);
// debe(tin);
// debe(tout);

for(int j=1;j<=LOG;j++)
{
	for(int i=1;i<=n;i++)
	{
		if(dp[i][j-1]!=-1)
			dp[i][j]=dp[dp[i][j-1]][j-1];
		else
			dp[i][j]=-1;
	}
}

function<bool(int ,int )>is_ancestor=[&](int a,int b)->bool{
	return tin[a]<=tin[b] && tout[b]<=tout[a];
};


function<int(int ,int)>get_lca=[&](int a,int b)->int{
	if(is_ancestor(a,b))
		return a;
	if(is_ancestor(b,a))
		return b;
	for(int j=LOG;j>=0;j--)
	{
		if(dp[b][j]!=-1 && !is_ancestor(dp[b][j],a) )
		{
			b=dp[b][j];
		}
	}
	return dp[b][0];
};
