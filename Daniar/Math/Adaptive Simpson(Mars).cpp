#include<bits/stdc++.h>
using namespace std;
typedef double dbl;

/**
Integration x * sin(x) in Range [0,1]
∫ x sin(x) dx = –x cos(x) +  sin(x) + c
**/

int main()
{
    dbl REAL_ANS=(-cos(1.0)+sin(1.0))-(sin(0.0));
    printf("%.20f\n",REAL_ANS);

    int n=1000;
    dbl a=0.0 , b=1.0; /// Integration limits
    dbl h=(b-a)/(n*1.0);

    dbl ANS=0, SUM1=0, SUM2=0;
    int i=1;

    for(dbl x=a+h ; x < b ; i++ , x+=h)
    {
        if(i&1) SUM1 += (x*sin(x));
        else    SUM2 += (x*sin(x));
    }

    ANS = 4.0*SUM1 + 2.0*SUM2 + (a*sin(a)) + (b*sin(b));
    ANS *= (h/3.0);

    printf("%.20f\n",ANS);

    return 0;
}
