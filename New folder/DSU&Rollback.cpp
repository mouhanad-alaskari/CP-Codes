#define pb push_back
#define all(x) (x).begin(), (x).end()


struct Rollback {
  vector<pair<int*, int>> st;
  void set(int& v, int x) {
    st.pb({&v, v});
    v = x;
  }
  void rollback(int t) {
    while((int)st.size() > t) {
      *st.back().first = st.back().second;
      st.pop_back();
    }
  }
  int snapshot() const { return st.size(); }
};

struct Dsu {
  Rollback rb;
  vector<int> r, sz;
  int comps;

  Dsu() {}
  Dsu(int n) : r(n), sz(n), comps(n) {
    fill(all(sz), 1);
    iota(all(r), 0);
  }

  int get(int i) const { return r[i] == i ? i : get(r[i]); }
  int join(int u, int v) {
    u = get(u);
    v = get(v);
    if(u == v) return 0;
    if(sz[u] > sz[v]) swap(u, v);
   // if( rand()&1 )swap(u,v);
    rb.set(sz[v], sz[u] + sz[v]);
    rb.set(r[u], v);
    rb.set(comps, comps - 1);
    return 1;
  }
  int join(pair<int, int> e) { return join(e.first, e.second); }
};
Dsu dsu;
