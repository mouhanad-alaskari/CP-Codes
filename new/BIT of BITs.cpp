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

K-th number on bit *-* 

inline int getVal(int v){
	++v;
	if(getPrefix(N-2)<v)return -1; // mafesh idx v
	int bst = 0;
	for(int j=1<<19;j;j>>=1)
		if(BIT[bst+j]<v)
			v-=BIT[bst+j],bst+=j;
	return bst;
}