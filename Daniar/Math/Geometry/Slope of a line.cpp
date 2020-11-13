#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef long long ll;
const ll inf = 1LL<<30;

ii Get_Inc(ii a,ii b)
{
    int ma=a.S-b.S , mb=a.F-b.F;
    bool f=0;
    if(ma < 0) f=!f;
    if(mb < 0) f=!f;
    ma=abs(ma);
    mb=abs(mb);

    if(!ma) ma=inf , mb=a.S;
    else if(!mb) mb=inf , ma=a.F;
    else
    {
        int c=__gcd(ma,mb);
        ma/=c;
        mb/=c;
        if(f) ma*=-1;
    }

    return make_pair(ma,mb);
}

int main()
{

    return 0;
}
