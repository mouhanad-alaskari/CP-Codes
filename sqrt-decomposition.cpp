#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
const int M = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
const int oo = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define pb push_back 
#define all(c) (c).begin(),(c).end()
int n,q,v[N],root;
vector<int> b[400];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin>>n>>q;
	root=sqrt(n);
	int ct = (n+root-1)/root;
	for(int i=0; i<n; ++i)
		scanf("%d",&v[i]);
	for(int i=0; i<n; ++i)
		b[i/root].push_back(v[i]);
	for(int i=0; i<ct; ++i)
		sort(b[i].begin(), b[i].end());

	char c;
	for(int l,r,x,i=0; i<q; ++i){
		scanf(" %c", &c);
		if(c=='C'){
			scanf("%d%d%d",&l,&r,&x);
			--l;--r;
			int ans=0;
			for(int j=l; j<=r; ++j){
				if(j%root==0 && j+root-1<=r){
					ans+= upper_bound(b[j/root].begin(), b[j/root].end(), x) - b[j/root].begin();
					j+=root-1;
				}else if(v[j]<=x){
					++ans;
				}
			}
			printf("%d\n", ans);
		}else{
			scanf("%d%d",&l,&x);
			--l;
			v[l]=x;
			int bucket=l/root;
			b[bucket].clear();
			for(int j=bucket*root; j<n && j<(bucket+1)*root; ++j)
				b[bucket].push_back(v[j]);
			sort(b[bucket].begin(), b[bucket].end());
		}
	}
	return 0;	
}

