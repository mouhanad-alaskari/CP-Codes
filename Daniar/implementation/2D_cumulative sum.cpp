#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=10101;
ll a[N][N], sum[N][N];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            scanf("%lld",&a[i][j]);

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }

    int q;
    scanf("%d",&q);

    while(q--) {
        int x1,y1;
        scanf("%d%d",&x1,&y1);
        int x2,y2;
        scanf("%d%d",&x2,&y2);
        ll ans=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];

        printf("%lld\n",ans);
    }

    return 0;
}
