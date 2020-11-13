#include <bits/stdc++.h>
using namespace std;

const int N = 19;
const double eps = 1e-8;
int h , w , n ;
int start_X , start_Y;
int x[N] , y[N] ;
double dis[N][N];
double mem[1<<N][N];
int vis [1<<N][N];
int x1,y1,x2,y2;

double F(double x,double y){
    return sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)) +  sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
}
double mn (int x , int y ) {
return min ( x , min ( y , min (w-x , h-y) ));
}
double diss(){

    double ans= 100100;

    double lo=0 , hi = h;
    while(hi-lo > eps){
        double mid=(lo+hi)/2.0;
        if(F(0,mid) > F(0,mid+eps)) lo=mid+eps;
        else hi=mid;
    }

    ans=min(ans,F(0,lo));

    lo=0 , hi = w;
    while(hi-lo > eps){
        double mid=(lo+hi)/2.0;
        if(F(mid,0) > F(mid+eps,0)) lo=mid+eps;
        else hi=mid;
    }

    ans=min(ans,F(lo,0));

    lo=0 , hi = w;
    while(hi-lo > eps){
        double mid=(lo+hi)/2.0;
        if(F(mid,h) > F(mid+eps,h)) lo=mid+eps;
        else hi=mid;
    }

    ans=min(ans,F(lo,h));

    lo = 0 , hi = h;
    while(hi-lo > eps){
        double mid=(lo+hi)/2.0;
        if(F(w,mid) > F(w,mid+eps)) lo=mid+eps;
        else hi=mid;
    }

    ans=min(ans,F(w,lo));

    return ans;
}

double dp(int mask,int last){
if( mask == 0 )
    { return mn(x[last] , y[last]);}
double &ret=mem[mask][last];

if( vis[mask][last] )return ret;
ret = 1<<30;
vis[mask][last] = 1 ;
for(int i=0;i<n;i++)
    if( mask&( 1<<i ) )
    ret=min( ret , dp(mask^(1<<i),i)+dis[last][i] );
    //cout << ret <<endl;
return ret;
}
int main(){
freopen("kitchen.in","r",stdin);
freopen("kitchen.out","w",stdout);
scanf("%d%d%d" ,&w,&h,&n);
for(int i=0;i<n;i++)
    scanf("%d%d",&(x[i]),&(y[i]));

scanf("%d%d",&start_X,&start_Y);

x[n]=start_X;
y[n]=start_Y;

for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
        { x1=x[i] , y1=y[i] , x2=x[j] , y2=y[j] ;
            dis[i][j]=dis[j][i]=diss();
        }
    for ( int i = 0 ; i < n ; i++ ) {
        dis[i][n] = dis[n][i] = hypot( x[i]-x[n] , y[i]-y[n] );
   //    cout << x[i] << " " << y[i] <<" " << dis[i][n] <<endl;
    }
for ( int i = 0; i <= n ; i++ ) dis[i][i] = 0.0 ;


  printf("%.8f" , dp( (1<<n)-1 , n ));

return 0;
}
