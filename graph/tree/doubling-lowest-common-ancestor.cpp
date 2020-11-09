/**
 * @brief Doubling-Lowest-Common-Ancestor(最小共通祖先)
 * @docs docs/doubling-lowest-common-ancestor.md
 */
template< typename T >
struct DoublingLowestCommonAncestor : Graph< T > {
public:
  using Graph< T >::g;
  vector< int > dep;
  vector< T > sum;
  vector< vector< int > > table;
  const int LOG;

  explicit DoublingLowestCommonAncestor(int n)
      : LOG(32 - __builtin_clz(g.size())), Graph< T >(n) {}

  explicit DoublingLowestCommonAncestor(const Graph< T > &g)
      : LOG(32 - __builtin_clz(g.size())), Graph< T >(g) {}

  void build() {
    dep.assign(g.size(), 0);
    sum.assign(g.size(), 0);
    table.assign(LOG, vector< int >(g.size(), -1));
    dfs(0, -1, 0);
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }

  T dist(int u, int v) {
    return sum[u] + sum[v] - 2 * sum[lca(u, v)];
  }

private:
  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to : g[idx]) {
      if(to != par) {
        sum[to] = sum[idx] + to.cost;
        dfs(to, idx, d + 1);
      }
    }
  }
};
