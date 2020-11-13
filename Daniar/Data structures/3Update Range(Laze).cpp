#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100100;
const ll inf=1ll<<60;

int a[N];
ll seg[N<<2] , lazy[N<<2];


void build(int nd,int L,int R)
{
    if( L == R )
    {
        seg[nd]=a[L];
        return ;
    }
    int mid = (L+R) >>1;
    build(nd<<1  ,L , mid);
    build(nd<<1|1,mid+1,R);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

void push(int nd,int L,int R)
{
    if( lazy[nd]==0 )return;
    seg[nd]+=lazy[nd];
    if( L != R )
    {
        lazy[nd<<1  ]+=lazy[nd];
        lazy[nd<<1|1]+=lazy[nd];
    }
    lazy[nd]=0;
}


void update(int nd,int L,int R,int idx,int val)
{
    if( L == R )
    {
        seg[nd]=val;
        return ;
    }
    int mid = (L+R) >>1;
    if( idx<=mid )
        update(nd<<1  ,  L  ,mid,idx,val);
    else update(nd<<1|1,mid+1, R,idx,val);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}


ll query(int nd,int L,int R,int from,int to)
{
    push(nd,L,R);

    if( from<=L && R<=to )return seg[nd];
    if( from>R || to<L )return -inf;

    int mid = (L+R) >>1;

    ll leftAns = query(nd<<1  ,  L  ,mid,from,to);
    ll rightAns= query(nd<<1|1,mid+1, R ,from,to);
    return max( leftAns ,rightAns );
}



void updateRange(int nd,int L,int R,int from,int to,int val)
{
    push(nd,L,R);

    if( R <from  || L>to )return;
    if( from<=L && R<=to )
    {
        lazy[nd]+=val;
        push(nd,L,R);
        return;
    }

    int mid = (L+R) >>1;
    updateRange(nd<<1  ,  L  ,mid,from,to,val);
    updateRange(nd<<1|1,mid+1, R ,from,to,val);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

int main()
{
    ll n , q;
    return 0;
}
