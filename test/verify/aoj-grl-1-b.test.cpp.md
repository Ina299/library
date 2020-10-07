---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.cpp
    title: graph/graph-template.cpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/bellman-ford.cpp
    title: "Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/verify/aoj-grl-1-b.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll\
    \ = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \n\ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream &is, pair<\
    \ T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n  for(int i =\
    \ 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream\
    \ &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b &&\
    \ (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64\
    \ >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate<\
    \ typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector<\
    \ decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename\
    \ T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T\
    \ &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto\
    \ &e : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n\
    \  FixPoint(F &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n\
    \  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 2 \"graph/graph-template.cpp\"\
    \n\ntemplate< typename T = int >\nstruct Edge {\n  int from, to;\n  T cost;\n\
    \  int idx;\n\n  Edge() = default;\n\n  Edge(int from, int to, T cost = 1, int\
    \ idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n\n  operator int()\
    \ const { return to; }\n};\n\ntemplate< typename T = int >\nstruct Graph {\n \
    \ vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph() = default;\n\n  explicit\
    \ Graph(int n) : g(n), es(0) {}\n\n  size_t size() const {\n    return g.size();\n\
    \  }\n\n  void add_directed_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es++);\n  }\n\n  void add_edge(int from, int to, T cost = 1) {\n \
    \   g[from].emplace_back(from, to, cost, es);\n    g[to].emplace_back(to, from,\
    \ cost, es++);\n  }\n\n  void read(int M, int padding = -1, bool weighted = false,\
    \ bool directed = false) {\n    for(int i = 0; i < M; i++) {\n      int a, b;\n\
    \      cin >> a >> b;\n      a += padding;\n      b += padding;\n      T c = T(1);\n\
    \      if(weighted) cin >> c;\n      if(directed) add_directed_edge(a, b, c);\n\
    \      else add_edge(a, b, c);\n    }\n  }\n};\n\ntemplate< typename T = int >\n\
    using Edges = vector< Edge< T > >;\n#line 5 \"test/verify/aoj-grl-1-b.test.cpp\"\
    \n\n#line 1 \"graph/shortest-path/bellman-ford.cpp\"\n/**\n * @brief Bellman-Ford(\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)\n * @docs docs/bellman-ford.md\n */\ntemplate<\
    \ typename T >\nvector< T > bellman_ford(const Edges< T > &edges, int V, int s)\
    \ {\n  const auto INF = numeric_limits< T >::max();\n  vector< T > dist(V, INF);\n\
    \  dist[s] = 0;\n  for(int i = 0; i < V - 1; i++) {\n    for(auto &e : edges)\
    \ {\n      if(dist[e.from] == INF) continue;\n      dist[e.to] = min(dist[e.to],\
    \ dist[e.from] + e.cost);\n    }\n  }\n  for(auto &e : edges) {\n    if(dist[e.from]\
    \ == INF) continue;\n    if(dist[e.from] + e.cost < dist[e.to]) return vector<\
    \ T >();\n  }\n  return dist;\n}\n#line 7 \"test/verify/aoj-grl-1-b.test.cpp\"\
    \n\nint main() {\n  int V, E, R;\n  cin >> V >> E >> R;\n  Edges< > es;\n  for(int\
    \ i = 0; i < E; i++) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    es.emplace_back(a,\
    \ b, c);\n  }\n  auto dists = bellman_ford(es, V, R);\n  if(dists.empty()) cout\
    \ << \"NEGATIVE CYCLE\\n\";\n  for(auto &dist : dists) {\n    if(dist == numeric_limits<\
    \ int >::max()) cout << \"INF\\n\";\n    else cout << dist << \"\\n\";\n  }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../template/template.cpp\"\n#include \"../../graph/graph-template.cpp\"\
    \n\n#include \"../../graph/shortest-path/bellman-ford.cpp\"\n\nint main() {\n\
    \  int V, E, R;\n  cin >> V >> E >> R;\n  Edges< > es;\n  for(int i = 0; i < E;\
    \ i++) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    es.emplace_back(a, b,\
    \ c);\n  }\n  auto dists = bellman_ford(es, V, R);\n  if(dists.empty()) cout <<\
    \ \"NEGATIVE CYCLE\\n\";\n  for(auto &dist : dists) {\n    if(dist == numeric_limits<\
    \ int >::max()) cout << \"INF\\n\";\n    else cout << dist << \"\\n\";\n  }\n\
    }\n"
  dependsOn:
  - template/template.cpp
  - graph/graph-template.cpp
  - graph/shortest-path/bellman-ford.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-1-b.test.cpp
  requiredBy: []
  timestamp: '2020-10-07 14:06:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-1-b.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-1-b.test.cpp
- /verify/test/verify/aoj-grl-1-b.test.cpp.html
title: test/verify/aoj-grl-1-b.test.cpp
---