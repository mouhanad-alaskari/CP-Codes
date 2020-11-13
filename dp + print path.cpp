#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

typedef long long ll;

struct req {
	int sz, price,ind;

	req(){}
	req(int s, int p,int i) {
		sz = s;
		price = p;
		ind = i;
	}

	bool operator<(const req & o) const {
		if (sz != o.sz)
			return sz < o.sz;
		return price > o.price;
	}
};

struct req2 {
	int sz, price, ind, t;

	req2(int s, int p, int i,int tt) {
		sz = s;
		price = p;
		ind = i;
		t = tt;
	}

	bool operator<(const req2 & o) const {
		return ind < o.ind;
	}
};

struct table {
	int sz, i;

	table(){}
	table(int s, int ii) {
		sz = s;
		i = ii;
	}

	bool operator<(const table & o) const {
		if(sz!=o.sz)
			return sz < o.sz;
		return i < o.i;
	}
};

const int N = 1001;
req tab[N];
table r[N];
int dp[N][N];
int sol[N][N];
int n, m;
vector<req2> ans;

int calc(int i, int j) {
	if (i == n || j==m)
		return 0;

	int &ret = dp[i][j];

	if (ret != -1)
		return ret;

	int c1 = 0, c2 = 0, c3 = 0;

	c1 = calc(i + 1, j);
	if (tab[i].sz <= r[j].sz) {
		c2 = calc(i + 1, j + 1) + tab[i].price;
		c3 = -(int)1e8;
	} 
	else {
		c3 = calc(i, j + 1);
		c2 = -(int)1e8;
	}

	if (c1 >= c2 && c1 >= c3)
		sol[i][j] = 0;
	else if (c2 >= c1 && c2 >= c3)
		sol[i][j] = 1;
	else sol[i][j] = 2;

	return ret = max(max(c1, c2), c3);
}

int build_sol(int i, int j) {
	if (i == n || j == m)
		return 0;

	if (sol[i][j] == 0) 
		return build_sol(i + 1, j);

	//cout << i << " , " << j << " : " << sol[i][j] << endl;
	if (sol[i][j] == 1) {
		ans.push_back(req2(tab[i].sz, tab[i].price, tab[i].ind,r[j].i));
		return build_sol(i + 1, j + 1)+1;
	}

	return build_sol(i, j + 1);
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		tab[i] = req(a, b, i);
	}
	sort(tab,tab+n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		r[i] = table(x, i);
	}
	sort(r, r + m);

	memset(dp, -1, sizeof(dp));
	
	int sum = calc(0, 0);
	int cnt = build_sol(0, 0);
	sort(ans.begin(), ans.end());

	printf("%d %d\n", cnt, sum);

	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d\n", ans[i].ind+1, ans[i].t+1);

	return 0;
}