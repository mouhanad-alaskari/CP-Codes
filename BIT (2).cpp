struct BIT{
    int N;
    vector<ll>a;
    BIT(){ N=1; a=vector<ll>(1,0); }
    BIT(int _N){ N=2+_N; a=vector<ll>(N,0); }

    void add(int i){
        while( i<N ){
            a[i]++;
            i+=i&-i;
        }
    }

    ll get(int i){
        int ret=0;
        while( i >0 ){
            ret += a[i];
            i-=i&-i;
        }
        return ret;
    }
    ll get(int l,int r){
        if( r < l )return 0ll;
        return get(r)-get(l-1);
    }
}bit[100100];