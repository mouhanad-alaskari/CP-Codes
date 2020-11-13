#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ii pair < int , int >
const int N=100100;
int vis[N];
vector<int>v;
vector<ii>adj[N];
bool DFS(int x,int e=0){
    vis[x]=1;
    bool ret=0;

    for(auto y:adj[x]){
        if(vis[y.F] == 1){
            v.push_back(y.S);
            ret=1;
        }
        else if(!vis[y.F]) ret=DFS(y.F,y.S);
        if(ret){
            if(e) v.push_back(e);
            return 1;
        }
    }
    vis[x]=2;
    return 0;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=m ; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back({v,i});
    }

    for(int i=1 ; i<=n ; i++){
        if(vis[i] == 2) continue;
        if(DFS(i)) break;
    }
}
