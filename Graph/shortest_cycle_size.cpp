// O (V.(E+V))
// length of shortest cycle
  int inf=1e9;
  int cycle=inf;
  for(int i=1;i<=n;i++)
  {
      queue<int>q;
      vector<int>dis(n+1);
      vector<int>parent(n+1,-1);
      parent[i]=-2;
      dis[i]=0;
      q.push(i);
      while(!q.empty())
      {
          int curr=q.front();
          q.pop();
          for(int nxt:adj[curr])
          {
              if(parent[nxt]==-1)
              {
                  q.push(nxt);
                  parent[nxt]=curr;
                  dis[nxt]=dis[curr]+1;
              }
              else if(nxt!=parent[curr])
              {
                  cycle=min(cycle,1+dis[curr]+dis[nxt]);
              }
          }
      }
  }
  if(cycle==inf)
      cout<<"-1\n";
  else
      cout<<cycle;
