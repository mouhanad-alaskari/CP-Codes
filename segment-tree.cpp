/**
*
* Author: Mouhanad
* Lang: GNU C++14
*
**/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >
typedef long long ll;
const int inf = 1<<30;
const int N =100100;
int n , a[N];
int seg[N<<2];
//int lazy[N<<2];

void build(int nd,int L,int R){
    if( L == R ){
        seg[nd]=a[L];
        return ;
    }
    int mid = (L+R) >>1;
    build(nd<<1  ,L , mid);
    build(nd<<1|1,mid+1,R);
    seg[nd]=max( seg[nd<<|1] , seg[nd<<1|1] );
}

/*void push(int nd,int L,int R){
    if( lazy[nd]==0 )return;
    seg[nd]+=lazy[nd];

    if( L != R ) { // have children
    lazy[nd<<1  ]+=lazy[nd];// push to left child
    lazy[nd<<1|1]+=lazy[nd];// push to right child
    }
    lazy[nd]=0;
}*/


void update(int nd,int L,int R,int idx,int val){
    if( L == R ){
        seg[nd]=val;
        return ;
    }
    int mid = (L+R) >>1;
    if( idx<=mid )
         update(nd<<1  ,  L  ,mid,idx,val);
    else update(nd<<1|1,mid+1, R ,idx,val);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

int query(int nd,int L,int R,int from,int to){
//    push(nd,L,R);

    if( from<=L && R<=to )return seg[nd];
    if( from>R || to<L )return -inf;

    int mid = (L+R) >>1;

    int leftAns = query(nd<<1  ,  L  ,mid,from,to);
    int rightAns= query(nd<<1|1,mid+1, R ,from,to);
    return max( leftAns ,rightAns );
}

/*void updateRange(int nd,int L,int R,int from,int to,int val){
    push(nd,L,R);

    if( R <from  || L>to )return; // out
    if( from<=L && R<=to ){       // in
        lazy[nd]+=val;
        push(nd);
        return;
    }

    int mid = (L+R) >>1;
    updateRange(nd<<1  ,  L  ,mid,from,to,val);
    updateRange(nd<<1|1,mid+1, R ,from,to,val);

    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
 }*/



int main(){

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];


    build( 1 , 1 , n );
    cout<<query( 1 , 1 , n , 4 , 6 )<<endl;
    update(1,1,n,5,100);
    cout<<query( 1 , 1 , n , 4 , 6 )<<endl;
    updateRange( 1 , 1 , n , 1 , n , 10 );
    cout<<query( 1 , 1 , n , 4 , 6 )<<endl;

    return 0;
    }
