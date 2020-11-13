

inline int get(int mask,int i){return (mask>>i)&1;}
inline int on(int mask,int i){return mask|(1<<i);}
inline int off(int mask,int i){return mask&(~(1<<i));}
inline int msb(int x) {
	union { double a; int b[2]; };
	a = x;
	return (b[1] >> 20) - 1023;
}
inline int popcount(int mask){
    int ret = 0;
    for (;mask;mask-=mask&-mask)ret++;
    return ret;
}