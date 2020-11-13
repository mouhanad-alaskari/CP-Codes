
void treset(){
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            dp[i][j] = 0;
}
void init(){
    memset(dp, 0, sizeof dp);
}
for(int i=0;i<n;++i)memset(f[i],0xff,n*sizeof(int));

    if(vis[beg][ed] == cs) return dp[beg][ed];
    vis[beg][ed]=cs;