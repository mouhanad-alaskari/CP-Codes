//getline by scanf
char str[2 * N];
scanf("%*c%[^\n]", str);


// read char by char 

inline char nc() {
    static char buf[100000],*p1=buf,*p2=buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline void read(int &x) {
    char c = nc(), b = 1;
    for (; !(c >= '0' && c <= '9'); c = nc()) {
        if (c == '-') b = -b;
    }
    for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc()); x *= b;
}

void read(int &x) {
	ch = getchar();
	while (ch <= 32) ch = getchar();
	x = 0;
	while (ch > 32) x = x * 10 + ch - 48, ch = getchar();
}


///////
rand
mt19937 rnd(time(NULL));
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 