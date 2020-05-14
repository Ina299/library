---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/verify/aoj-grl-6-a-3.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a4423c79a88aeb6104a40a645f9430c">test/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/verify/aoj-grl-6-a-3.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-30 01:47:11+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/flow/push-relabel.cpp.html">graph/flow/push-relabel.cpp</a>
* :heavy_check_mark: <a href="../../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../template/template.cpp"

#include "../../graph/flow/push-relabel.cpp"

int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  PushRelabel< int > g(V);
  for(int i = 0; i < E; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g.add_edge(a, b, c);
  }
  printf("%d\n", g.max_flow(0, V - 1));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/verify/aoj-grl-6-a-3.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#line 1 "template/template.cpp"
#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}
 
  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};
 
template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}
#line 4 "test/verify/aoj-grl-6-a-3.test.cpp"

#line 1 "graph/flow/push-relabel.cpp"
class Stack {
private:
  const int N, H;
  vector< int > node;
 
public:
  Stack(const int N, const int H) : N(N), H(H), node(N + H) { clear(); }
 
  inline bool empty(const int h) const { return node[N + h] == N + h; }
 
  inline int top(const int h) const { return node[N + h]; }
 
  inline void pop(const int h) { node[N + h] = node[node[N + h]]; }
 
  inline void push(const int h, const int u) { node[u] = node[N + h], node[N + h] = u; }
 
  inline void clear() { iota(node.begin() + N, node.end(), N); }
};
 
class List {
public:
  struct node {
    int prev, next;
  };
  const int N, H;
  vector< node > dat;
 
  List(const int N, const int H) : N(N), H(H), dat(N + H) { clear(); }
 
  inline bool empty(const int h) const { return (dat[N + h].next == N + h); }
 
  inline bool more_one(const int h) const { return dat[N + h].prev != dat[N + h].next; }
 
  inline void insert(const int h, const int u) {
    dat[u].prev = dat[N + h].prev, dat[u].next = N + h;
    dat[dat[N + h].prev].next = u, dat[N + h].prev = u;
  }
 
  inline void erase(const int u) {
    dat[dat[u].prev].next = dat[u].next, dat[dat[u].next].prev = dat[u].prev;
  }
 
  inline void clear() {
    for(int i = N; i < N + H; ++i) dat[i].prev = dat[i].next = i;
  }
};

template< typename flow_t >
struct PushRelabel {
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > potential, cur_edge;
  vector< flow_t > ex;
  int V, height, relabels;
  List all_ver;
  Stack act_ver;

  PushRelabel(int V)
      : V(V), height(-1), relabels(0), ex(V, flow_t(0)), potential(V, 0), cur_edge(V), all_ver(V, V), act_ver(V, V), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  int calc_active(int t) {
    height = -1;
    for(int i = 0; i < V; i++) {
      if(potential[i] < V) {
        cur_edge[i] = 0;
        height = max(height, potential[i]);
        all_ver.insert(potential[i], i);
        if(ex[i] > 0 && i != t) act_ver.push(potential[i], i);
      } else {
        potential[i] = V + 1;
      }
    }
    return height;
  }

  void bfs(int t) {
    for(int i = 0; i < V; i++) {
      potential[i] = max(potential[i], V);
    }
    potential[t] = 0;
    queue< int > que;
    que.emplace(t);
    while(!que.empty()) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(potential[e.to] == V && graph[e.to][e.rev].cap > 0) {
          potential[e.to] = potential[p] + 1;
          que.emplace(e.to);
        }
      }
    }
  }

  int init(int s, int t) {
    potential[s] = V + 1;
    bfs(t);
    for(auto &e : graph[s]) {
      if(potential[e.to] < V) {
        graph[e.to][e.rev].cap = e.cap;
        ex[s] -= e.cap;
        ex[e.to] += e.cap;
      }
      e.cap = 0;
    }
    return calc_active(t);
  }

  bool push(int u, int t, edge &e) {
    flow_t f = min(e.cap, ex[u]);
    int v = e.to;
    e.cap -= f, ex[u] -= f;
    graph[v][e.rev].cap += f, ex[v] += f;
    if(ex[v] == f && v != t) act_ver.push(potential[v], v);
    return ex[u] == 0;
  }

  int discharge(int u, int t) {
    for(int &i = cur_edge[u]; i < graph[u].size(); i++) {
      auto &e = graph[u][i];
      if(potential[u] == potential[e.to] + 1 && e.cap > 0) {
        if(push(u, t, e)) return potential[u];
      }
    }
    return relabel(u);
  }

  int global_relabel(int t) {
    bfs(t);
    all_ver.clear(), act_ver.clear();
    return calc_active(t);
  }

  void gap_relabel(const int u) {
    for(int i = potential[u]; i <= height; ++i) {
      for(int id = all_ver.dat[V + i].next; id < V; id = all_ver.dat[id].next) {
        potential[id] = V + 1;
      }
      all_ver.dat[V + i].prev = all_ver.dat[V + i].next = V + i;
    }
  }

  int relabel(const int u) {
    ++relabels;
    int prv = potential[u], cur = V;
    for(int i = 0; i < (int) graph[u].size(); ++i) {
      const edge &e = graph[u][i];
      if(cur > potential[e.to] + 1 && e.cap > 0) {
        cur_edge[u] = i;
        cur = potential[e.to] + 1;
      }
    }
    if(all_ver.more_one(prv)) {
      all_ver.erase(u);
      if((potential[u] = cur) == V) return potential[u] = V + 1, prv;
      act_ver.push(cur, u);
      all_ver.insert(cur, u);
      height = max(height, cur);
    } else {
      gap_relabel(u);
      return height = prv - 1;
    }
    return cur;
  }

  flow_t max_flow(int s, int t) {
    int level = init(s, t);
    while(level >= 0) {
      if(act_ver.empty(level)) {
        --level;
        continue;
      }
      int u = act_ver.top(level);
      act_ver.pop(level);
      level = discharge(u, t);
      if(relabels * 2 >= V) {
        level = global_relabel(t);
        relabels = 0;
      }
    }
    return ex[t];
  }
};
#line 6 "test/verify/aoj-grl-6-a-3.test.cpp"

int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  PushRelabel< int > g(V);
  for(int i = 0; i < E; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g.add_edge(a, b, c);
  }
  printf("%d\n", g.max_flow(0, V - 1));
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
