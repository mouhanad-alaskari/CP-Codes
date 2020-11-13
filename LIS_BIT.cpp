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
const int N =1000100 , mod = 1000000007;
int n , a[N] , k ;
ll bit[N][4];
void add ( int i , int  j , ll val ){
 
  while ( i < N ){
 bit[i][j]+=val ;
  i += i & -i ;
  }
return ;
}
ll  get_ ( int i , int j ){
ll ret = 0 ;
while ( i ){
    ret += bit[i][j] ;
    i -= i & -i;
}
return ret ;
}
map < int , int > mp ;
int main ( ){
  scanf("%d",&n);
  int cnt = 1;
  for ( int i = 1;  i<= n ; i++ ) {
        scanf("%d",a+i);
        mp[a[i]] = 0;
  }
  for ( auto &x : mp ){
     x.S = cnt++;
  }
  for ( int i = 1;  i <= n ;i++ ) a[i] = mp[a[i]];
 
  reverse(a+1,a+1+n);
  for ( int i = 1;  i <= n ;i++ )
  for ( int j = 1 ; j <= 3 ; j++ ){
     if ( j == 1 ){
       add(a[i],1,1);
     }else {
        add ( a[i] , j , get_(a[i]-1,j-1));
     }
  }
  printf("%lld",get_(N-7,3));
return 0 ;
}