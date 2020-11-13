#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1000010;
ll BIT[N];
int n;

/// query(r) - query(l-1)

ll query(int x)
{
    ll sum = 0 ;
    for(; x > 0; x -= x&-x) sum += BIT[x];
    return sum;
}

/// update(index,-old value) -> update(index,new value)

void update(int x, ll delta)
{
    for(; x <= n ; x += x&-x)
        BIT[x] += delta;
}


int main()
{

    return 0;
}
