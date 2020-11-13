/**
*
* Author: MARC
* Lang: GNU C++11 5.1.0
*
**/

#include<bits/stdc++.h>
using namespace std;

#define FF first
#define SS second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const long double pi = 3.1415926535897932385;
const long double E = 2.71828182845904523536;
const ll mod = 1e9+7;
const ll eps = 1e-15;
const ll inf = 1e15;

/** /////////// ** Code ** /////////// **/

const int N = 100100;
int p[N] ;
vector< pair< int, pair<int,int> > >edge;


int Par(int i){ return p[i]=( i==p[i] )?i:Par(p[i]); }
bool same(int i,int j){ return Par(i)==Par(j); }

void mrg(int i,int j){
    if(same(i,j))return;
    i=Par(i);j=Par(j);
    if( rand()&1 )swap(i,j);
    p[i]=p[j];
}

void solve(){
    for(int i=0;i<N;i++)
        p[i]=i;
    edge.clear();

    int n,m; scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a , b , c ;
        scanf("%d %d %d",&a,&b,&c);
        edge.push_back( {c,{a,b}} );
    }
    sort(edge.begin(),edge.end());

    int ans=0;
    for(int i=0;i<m;i++){
    int a = edge[i].second.first;
    int b = edge[i].second.second;
    int c = edge[i].first;
    if( same(a,b) )continue;
    mrg(a,b);
    ans+=c;
    }

    printf("%d\n",ans);
}

int main(){

    int T; scanf("%d",&T);
    while( T-- )solve();

return 0;
}