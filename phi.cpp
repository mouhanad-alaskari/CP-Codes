#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{

    ll n , ans=1 ;
    scanf("%lld",&n);
    if( n == 1 )ans=2;
    else
    {

        for(ll i=2; i*i<=n; i++)
        {
            if( n%i )continue;

            ll pk=1;
            while( n%i==0 )
            {
                n/=i;
                pk*=i;
            }
            ans*= (pk-pk/i);
        }
        if( n>1 )ans*=(n-1);
    }
    printf("%lld\n",ans);
    return 0;
}