// solution for https://www.codechef.com/status/PRIMEDST

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int N =50050;
int n , m ;
bool seive[N] , del[N];
int prime[N] , data[N] , tmp[N], f [N], all , c;
vector < int > adj[N];
int ANS ;
int sz[N];
void dfs1( int u , int p )
{
    sz[u] = 1;
    for ( auto v : adj[u] )
    {
        if ( v != p && !del[v])
        {
            dfs1(v,u);
            sz[u] += sz[v];
        }
    }
}
int dfs2 ( int u , int cnt , int p = 0 )
{
    for ( auto v : adj[u] )
    {
        if ( v != p && !del[v])
            if ( 2*sz[v] >= cnt )
                return dfs2(v,cnt,u);
    }
    return u;
}
void dfs3 ( int u , int p , int dst =1 )
{
    tmp[c++] = dst ;
    for ( auto v : adj[u] )
        if ( v != p && !del[v] )
            dfs3(v,u,dst+1);
}
void solve( int st )
{

    dfs1(st,0);

    int rt = dfs2(st,sz[st]);

    f[0] = 1 ;
    for  (auto v : adj[rt] )
    {
        if ( del[v] )continue;
        dfs3(v,rt);
        for ( int i = 0 ; i < c ; i++ )
        {
            int x = tmp[i];
            for (int  j = m-1 ; j>= 0 && prime[j] >= x  ; --j )
            {
                ANS += f[prime[j]-x];
            }
        }
        for  (int i =0 ; i < c ; i++ )
            f[tmp[i]]++,data[all++] = tmp[i];
        c = 0 ;
    }

    for ( int i = 0 ; i < all ; i++ )
        f[data[i]]--;
    all =0  ;
    del[rt] = 1 ;
    for ( auto v : adj[rt])
        if (!del[v])
            solve(v);
}

int main ( )
{
    scanf("%d",&n);
    for ( int i = 0; i <n-1;  i++ )
    {
        int x , y ;
        scanf("%d %d",&x , &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=2; i<N; i++)seive[i]=1;
    for(int i=2; i*i<N; i++)
        if( seive[i] )
            for(int j=i*i; j<N; j+=i)
                seive[j]=0;

    for(int j=2; j<N; j++)
        if( seive[j] )
            prime[m++]=j;

    solve(1);
    printf("%.9f\n",2.0*ANS/n/(n-1));
    return 0 ;
}

//////////////////////////////////////////////////
// same but faster i don't know why yet ):

#include<bits/stdc++.h>
using namespace std;

#define MX 50005
#define LL long long int
vector<int>v[MX];
vector<int>prime;
int n;
int tot_node;
int sub_size[MX];
bool centroid[MX],mark[MX];
int ndist[MX];
LL ans;

void SIEVE()
{
    prime.push_back(2);
    for(int i=4; i<MX; i+=2)    mark[i] = true;
    for(LL i=3; i<MX; i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            for(LL j=(i*i); j<MX; j+=i)    mark[j] = true;
        }
    }
    //cout<<prime.size()<<endl;
    //for(int i=0; i<(int)prime.size(); i++)  cout<<prime[i]<<endl;
    return;
}

void DFS(int s,int p)
{
    sub_size[s] = 1;
    for(int i=0; i<(int)v[s].size(); i++)
    {
        if(v[s][i]!=p && !centroid[v[s][i]])
        {
            DFS(v[s][i],s);
            sub_size[s] += sub_size[v[s][i]];
        }
    }
    return;
}

int get_Centroid(int s,int p)
{
    for(int i=0; i<(int)v[s].size(); i++)
    {
        if(v[s][i]!=p && !centroid[v[s][i]] && sub_size[v[s][i]]>(tot_node>>1)) return  get_Centroid(v[s][i],s);
    }
    return  s;
}

void DFS2(int s,int p,int l,int add)
{
    ndist[l] += add;
    for(int i=0; i<(int)v[s].size(); i++)
    {
        if(v[s][i]==p || centroid[v[s][i]])  continue;
        DFS2(v[s][i],s,l+1,add);
    }
    return;
}

LL DFS3(int s,int p,int l)
{
    LL res = 0;
    for(int i=0; i<(int)prime.size(); i++)
    {
        if(prime[i]<l)  continue;
        if(!ndist[prime[i]-l])   break;
        if(prime[i]==l) res += (2*ndist[prime[i]-l]);    /// x->root, root->x
        else    res += ndist[prime[i]-l];
    }
    for(int i=0; i<(int)v[s].size(); i++)
    {
        if(v[s][i]==p || centroid[v[s][i]])  continue;
        res += DFS3(v[s][i],s,l+1);
    }
    return  res;
}

void Decompose(int s,int p,int l)
{
    DFS(s,-1);
    tot_node = sub_size[s];
    int x = get_Centroid(s,p);
    centroid[x] = true;

    LL res = 0;
    DFS2(x,p,0,1);

    for(int i=0; i<(int)v[x].size(); i++)
    {
        if(v[x][i]==p || centroid[v[x][i]])  continue;
        DFS2(v[x][i],x,1,-1);
        res += DFS3(v[x][i],x,1);
        DFS2(v[x][i],x,1,1);
    }
    ans += (res/2);
    //cout<<x<<" "<<ans<<endl;
    for(int i=0; i<MX; i++)
    {
        if(!ndist[i])   break;
        ndist[i] = 0;
    }

    for(int i=0; i<(int)v[x].size(); i++)
    {
        if(!centroid[v[x][i]])  Decompose(v[x][i],x,l+1);
    }
    return;
}

int main()
{
    int x,y;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    SIEVE();
    Decompose(1,-1,0);
    LL down = n;
    down = (down*(down-1))/2;
    //cout<<ans<<" "<<down<<endl;
    double tmp = (double)ans/(double)down;
    printf("%0.10lf\n",tmp);
    return  0;
}

