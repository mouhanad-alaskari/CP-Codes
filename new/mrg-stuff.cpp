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
int n , a[N] ;
ll ANS[N] ;
vector < int > adj[N];
struct stuff {
 map < int , ll > freqSum ;
 map < int , int > colorCnt;
 int mxFreq ;
};
void mrg ( stuff& a ,  stuff& b ){
  if ( a.colorCnt.size() < b.colorCnt.size() ) swap(a,b);
  for ( auto x : b.colorCnt ){
    int color = x.F , cnt = x.S ;
    int curFreq = a.colorCnt[color];
    a.freqSum[curFreq] -= color ;
    int nwFreq = curFreq + cnt ;
    a.freqSum[nwFreq] += color ;
    a.colorCnt[color] = nwFreq ;
    if ( a.mxFreq < nwFreq ) a.mxFreq = nwFreq ;
  }
  b.colorCnt.clear();
  b.freqSum.clear();
}
stuff dfs ( int u , int par  ){

   stuff cur ;
   cur.colorCnt[a[u]]= 1;
   cur.freqSum[1] = a[u];
   cur.mxFreq = 1 ;
   for ( auto v : adj[u] ){
    if ( v != par ){
       stuff other = dfs ( v , u );
      mrg( cur , other );
    }
   }
   ANS [u] = cur.freqSum[cur.mxFreq];
   return cur ;
}
int main ( ){
  scanf("%d",&n);
  for  (int i = 1; i <= n; i++ ) scanf("%d",a+i);
  for  ( int i = 1; i < n ;i++ ){
    int  x, y ;
    scanf("%d %d",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1,0);

  for ( int i = 1; i <= n; i++ ) printf("%lld ",ANS[i]);
return 0 ;
}