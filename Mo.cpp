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
const int N =200100;
int n , ANS[N] , a[N] , q ;
struct tt {
int  l , r , k , id ;
};
tt Q[N] ;
map < int , int > mp ;
int frq[N] , above[N] , sqr ;
bool cmp ( tt a , tt b ){
if ( a.l/sqr == b.l/sqr ) return (((a.l/sqr)&1) ? a.r < b.r : a.r > b.r ) ;
return a.l/sqr < b.l/sqr ;
}
void add ( int x ){
 above[frq[x]]++;
 frq[x]++;
}
void del ( int x ){
 frq[x]--;
 above[frq[x]]--;
}
void solve() {
 scanf("%d%d",&n,&q);
 sqr = 350;
 for ( int i = 1;  i<= n ;i++ ) {
        scanf("%d",a+i);
   mp[a[i]] ;
 }
 int cnt =0  ;
 for ( auto &x : mp ){
      x.S = ++cnt ;
 }
 for ( int i = 1 ; i <= n ;i++ ) a[i]= mp[a[i]];
 for ( int i = 1;  i<= q ;i++ ){
     scanf("%d%d%d",&(Q[i].l),&(Q[i].r),&(Q[i].k));
     Q[i].id = i ;
 }
 sort(Q+1,Q+1+q,cmp);
 int L , R , l = 1, r=0 ;
 
 for ( int i = 1;  i<= q ; i++ ){
    L = Q[i].l , R=Q[i].r ;
 
 
    while ( r > R ){
       del(a[r]);
       r--;
     }
    while ( r < R ){
        r++;
        add(a[r]);
    }
 
    while ( l < L ){
         del(a[l]);
         l++;
    }
    while ( l > L ){
        l--;
        add(a[l]);
    }
 //   cerr << frq[1] << " " << frq[2] <<" " << frq[3] <<endl;
    ANS[Q[i].id] = above[0]-above[Q[i].k]  ;
    //cerr << l <<" " << r <<" " << L << " " << R <<endl;
 }
 for ( int i = 1 ; i <= q ; i++ )
    printf("%d\n",ANS[i]);
}
int main ( ){
int t ;
scanf("%d",&t);
while (t--){
    solve();
    mp.clear();
    memset( above , 0 , sizeof above );
    memset( ANS , 0 , sizeof ANS );
    memset( frq , 0 , sizeof frq );
}
 
return 0 ;
}

///////////////////////////////////////////////////
store ans in blocks !!!
inline void add(int idx){
	int val=v[idx];
	fre[val]++;
	if(fre[val]==1){answer++;block[val/sqN]++;}
	if(fre[val]==2){answer--;block[val/sqN]--;}
}
 
inline void rem(int idx){
	int val=v[idx];
	fre[val]--;
	if(fre[val]==1){answer++;block[val/sqN]++;}
	if(fre[val]==0){answer--;block[val/sqN]--;}
}
inline int solve(){
	if(answer==0){
		return 0;
	}
          //while (!bl.empty() && block[bl.back()] < 1) flag[bl.back()] = 0 , bl.pop_back();
	//	 int i = bl.back();
	for(int i=0;i<sqN;i++){
		if(block[i]>0){
			for(int j=i*sqN;j<i*sqN+sqN;j++){
				if(fre[j]==1){
					return j;
				}
			}
		}
	}
}
 