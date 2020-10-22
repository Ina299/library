---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/combinatorics/mod-int.cpp
    title: math/combinatorics/mod-int.cpp
  - icon: ':heavy_check_mark:'
    path: math/fps/berlekamp-massey.cpp
    title: math/fps/berlekamp-massey.cpp
  - icon: ':question:'
    path: math/fps/formal-power-series.cpp
    title: "Formal-Power-Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/fps/sparse-matrix.cpp
    title: math/fps/sparse-matrix.cpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sparse_matrix_det
    links:
    - https://judge.yosupo.jp/problem/sparse_matrix_det
  bundledCode: "#line 1 \"test/verify/yosupo-sparse-matrix-det.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n\n#line 1 \"\
    template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll = (1LL <<\
    \ 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed <<\
    \ setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
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
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-sparse-matrix-det.test.cpp\"\
    \n\n#line 1 \"math/combinatorics/mod-int.cpp\"\ntemplate< int mod >\nstruct ModInt\
    \ {\n  int x;\n\n  ModInt() : x(0) {}\n\n  ModInt(int64_t y) : x(y >= 0 ? y %\
    \ mod : (mod - (-y) % mod) % mod) {}\n\n  ModInt &operator+=(const ModInt &p)\
    \ {\n    if((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  ModInt &operator-=(const\
    \ ModInt &p) {\n    if((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n\
    \  }\n\n  ModInt &operator*=(const ModInt &p) {\n    x = (int) (1LL * x * p.x\
    \ % mod);\n    return *this;\n  }\n\n  ModInt &operator/=(const ModInt &p) {\n\
    \    *this *= p.inverse();\n    return *this;\n  }\n\n  ModInt operator-() const\
    \ { return ModInt(-x); }\n\n  ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n\n  ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n\n  ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n\n  ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n\n  bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n\n  bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \n  ModInt inverse() const {\n    int a = x, b = mod, u = 1, v = 0, t;\n    while(b\
    \ > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v,\
    \ v);\n    }\n    return ModInt(u);\n  }\n\n  ModInt pow(int64_t n) const {\n\
    \    ModInt ret(1), mul(x);\n    while(n > 0) {\n      if(n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &p) {\n    return os << p.x;\n  }\n\n\
    \  friend istream &operator>>(istream &is, ModInt &a) {\n    int64_t t;\n    is\
    \ >> t;\n    a = ModInt< mod >(t);\n    return (is);\n  }\n\n  static int get_mod()\
    \ { return mod; }\n};\n\nusing modint = ModInt< mod >;\n#line 6 \"test/verify/yosupo-sparse-matrix-det.test.cpp\"\
    \n\n#line 2 \"math/fps/formal-power-series.cpp\"\n\n/**\n * @brief Formal-Power-Series(\u5F62\
    \u5F0F\u7684\u51AA\u7D1A\u6570)\n */\ntemplate< typename T >\nstruct FormalPowerSeries\
    \ : vector< T > {\n  using vector< T >::vector;\n  using P = FormalPowerSeries;\n\
    \n  using MULT = function< vector< T >(P, P) >;\n  using FFT = function< void(P\
    \ &) >;\n  using SQRT = function< T(T) >;\n\n  static MULT &get_mult() {\n   \
    \ static MULT mult = nullptr;\n    return mult;\n  }\n\n  static void set_mult(MULT\
    \ f) {\n    get_mult() = f;\n  }\n\n  static FFT &get_fft() {\n    static FFT\
    \ fft = nullptr;\n    return fft;\n  }\n\n  static FFT &get_ifft() {\n    static\
    \ FFT ifft = nullptr;\n    return ifft;\n  }\n\n  static void set_fft(FFT f, FFT\
    \ g) {\n    get_fft() = f;\n    get_ifft() = g;\n    if(get_mult() == nullptr)\
    \ {\n      auto mult = [&](P a, P b) {\n        int need = a.size() + b.size()\
    \ - 1;\n        int nbase = 1;\n        while((1 << nbase) < need) nbase++;\n\
    \        int sz = 1 << nbase;\n        a.resize(sz, T(0));\n        b.resize(sz,\
    \ T(0));\n        get_fft()(a);\n        get_fft()(b);\n        for(int i = 0;\
    \ i < sz; i++) a[i] *= b[i];\n        get_ifft()(a);\n        a.resize(need);\n\
    \        return a;\n      };\n      set_mult(mult);\n    }\n  }\n\n  static SQRT\
    \ &get_sqrt() {\n    static SQRT sqr = nullptr;\n    return sqr;\n  }\n\n  static\
    \ void set_sqrt(SQRT sqr) {\n    get_sqrt() = sqr;\n  }\n\n  void shrink() {\n\
    \    while(this->size() && this->back() == T(0)) this->pop_back();\n  }\n\n  P\
    \ operator+(const P &r) const { return P(*this) += r; }\n\n  P operator+(const\
    \ T &v) const { return P(*this) += v; }\n\n  P operator-(const P &r) const { return\
    \ P(*this) -= r; }\n\n  P operator-(const T &v) const { return P(*this) -= v;\
    \ }\n\n  P operator*(const P &r) const { return P(*this) *= r; }\n\n  P operator*(const\
    \ T &v) const { return P(*this) *= v; }\n\n  P operator/(const P &r) const { return\
    \ P(*this) /= r; }\n\n  P operator%(const P &r) const { return P(*this) %= r;\
    \ }\n\n  P &operator+=(const P &r) {\n    if(r.size() > this->size()) this->resize(r.size());\n\
    \    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  P &operator+=(const T &r) {\n    if(this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  P &operator-=(const P &r) {\n\
    \    if(r.size() > this->size()) this->resize(r.size());\n    for(int i = 0; i\
    \ < r.size(); i++) (*this)[i] -= r[i];\n    shrink();\n    return *this;\n  }\n\
    \n  P &operator-=(const T &r) {\n    if(this->empty()) this->resize(1);\n    (*this)[0]\
    \ -= r;\n    shrink();\n    return *this;\n  }\n\n  P &operator*=(const T &v)\
    \ {\n    const int n = (int) this->size();\n    for(int k = 0; k < n; k++) (*this)[k]\
    \ *= v;\n    return *this;\n  }\n\n  P &operator*=(const P &r) {\n    if(this->empty()\
    \ || r.empty()) {\n      this->clear();\n      return *this;\n    }\n    assert(get_mult()\
    \ != nullptr);\n    auto ret = get_mult()(*this, r);\n    return *this = P(begin(ret),\
    \ end(ret));\n  }\n\n  P &operator%=(const P &r) {\n    return *this -= *this\
    \ / r * r;\n  }\n\n  P operator-() const {\n    P ret(this->size());\n    for(int\
    \ i = 0; i < this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n\
    \  P &operator/=(const P &r) {\n    if(this->size() < r.size()) {\n      this->clear();\n\
    \      return *this;\n    }\n    int n = this->size() - r.size() + 1;\n    return\
    \ *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n  }\n\n  P dot(P r)\
    \ const {\n    P ret(min(this->size(), r.size()));\n    for(int i = 0; i < ret.size();\
    \ i++) ret[i] = (*this)[i] * r[i];\n    return ret;\n  }\n\n  P pre(int sz) const\
    \ {\n    return P(begin(*this), begin(*this) + min((int) this->size(), sz));\n\
    \  }\n\n  P operator>>(int sz) const {\n    if(this->size() <= sz) return {};\n\
    \    P ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  P operator<<(int sz) const {\n    P ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, T(0));\n    return ret;\n  }\n\n  P rev(int deg = -1) const {\n    P ret(*this);\n\
    \    if(deg != -1) ret.resize(deg, T(0));\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n  }\n\n  T operator()(T x) const {\n    T r = 0, w = 1;\n  \
    \  for(auto &v : *this) {\n      r += w * v;\n      w *= x;\n    }\n    return\
    \ r;\n  }\n\n  P diff() const;\n\n  P integral() const;\n\n  // F(0) must not\
    \ be 0\n  P inv_fast() const;\n\n  P inv(int deg = -1) const;\n\n  // F(0) must\
    \ be 1\n  P log(int deg = -1) const;\n\n  P sqrt(int deg = -1) const;\n\n  //\
    \ F(0) must be 0\n  P exp_fast(int deg = -1) const;\n\n  P exp(int deg = -1) const;\n\
    \n  P pow(int64_t k, int deg = -1) const;\n\n  P mod_pow(int64_t k, P g) const;\n\
    \n  P taylor_shift(T c) const;\n};\n#line 8 \"test/verify/yosupo-sparse-matrix-det.test.cpp\"\
    \n\n#line 1 \"math/fps/berlekamp-massey.cpp\"\ntemplate< class T >\nFormalPowerSeries<\
    \ T > berlekamp_massey(const FormalPowerSeries< T > &s) {\n  const int N = (int)\
    \ s.size();\n  FormalPowerSeries< T > b = {T(-1)}, c = {T(-1)};\n  T y = T(1);\n\
    \  for(int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()), m = int(b.size());\n\
    \    T x = 0;\n    for(int i = 0; i < l; i++) x += c[i] * s[ed - l + i];\n   \
    \ b.emplace_back(0);\n    m++;\n    if(x == T(0)) continue;\n    T freq = x /\
    \ y;\n    if(l < m) {\n      auto tmp = c;\n      c.insert(begin(c), m - l, T(0));\n\
    \      for(int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n     \
    \ b = tmp;\n      y = x;\n    } else {\n      for(int i = 0; i < m; i++) c[l -\
    \ 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  return c;\n}\n#line 1 \"math/fps/sparse-matrix.cpp\"\
    \ntemplate< typename T >\nusing FPSGraph = vector< vector< pair< int, T > > >;\n\
    \ntemplate< typename T >\nFormalPowerSeries< T > random_poly(int n) {\n  mt19937\
    \ mt(1333333);\n  FormalPowerSeries< T > res(n);\n  uniform_int_distribution<\
    \ int > rand(0, T::get_mod() - 1);\n  for(int i = 0; i < n; i++) res[i] = rand(mt);\n\
    \  return res;\n}\n\ntemplate< typename T >\nFormalPowerSeries< T > next_poly(const\
    \ FormalPowerSeries< T > &dp, const FPSGraph< T > &g) {\n  const int N = (int)\
    \ dp.size();\n  FormalPowerSeries< T > nxt(N);\n  for(int i = 0; i < N; i++) {\n\
    \    for(auto &p : g[i]) nxt[p.first] += p.second * dp[i];\n  }\n  return nxt;\n\
    }\n\ntemplate< typename T >\nFormalPowerSeries< T > minimum_poly(const FPSGraph<\
    \ T > &g) {\n  const int N = (int) g.size();\n  auto dp = random_poly< T >(N),\
    \ u = random_poly< T >(N);\n  FormalPowerSeries< T > f(2 * N);\n  for(int i =\
    \ 0; i < 2 * N; i++) {\n    for(auto &p : u.dot(dp)) f[i] += p;\n    dp = next_poly(dp,\
    \ g);\n  }\n  return berlekamp_massey(f);\n}\n\n/* O(N(N+S) + N log N log Q) (O(S):\
    \ time complexity of nex) */\ntemplate< typename T >\nFormalPowerSeries< T > sparse_pow(int64_t\
    \ Q, FormalPowerSeries< T > dp, const FPSGraph< T > &g) {\n  const int N = (int)\
    \ dp.size();\n  auto A = FormalPowerSeries< T >({0, 1}).pow_mod(Q, minimum_poly(g));\n\
    \  FormalPowerSeries< T > res(N);\n  for(int i = 0; i < A.size(); i++) {\n   \
    \ res += dp * A[i];\n    dp = next_poly(dp, g);\n  }\n  return res;\n}\n\n/* O(N(N+S))\
    \ (S: none-zero elements)*/\ntemplate< typename T >\nT sparse_determinant(FPSGraph<\
    \ T > g) {\n  using FPS = FormalPowerSeries< T >;\n  int N = (int) g.size();\n\
    \  auto C = random_poly< T >(N);\n  for(int i = 0; i < N; i++) for(auto &p : g[i])\
    \ p.second *= C[i];\n  auto u = minimum_poly(g);\n  T acdet = u[0];\n  if(N %\
    \ 2 == 0) acdet *= -1;\n  T cdet = 1;\n  for(int i = 0; i < N; i++) cdet *= C[i];\n\
    \  return acdet / cdet;\n}\n#line 11 \"test/verify/yosupo-sparse-matrix-det.test.cpp\"\
    \n\nconst int MOD = 998244353;\nusing mint = ModInt< MOD >;\n\nint main() {\n\
    \  int N, K;\n  cin >> N >> K;\n  FPSGraph< mint > g(N);\n  for(int i = 0; i <\
    \ K; i++) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    g[a].emplace_back(b,\
    \ c);\n  }\n  cout << sparse_determinant(g) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n\n\
    #include \"../../template/template.cpp\"\n\n#include \"../../math/combinatorics/mod-int.cpp\"\
    \n\n#include \"../../math/fps/formal-power-series.cpp\"\n\n#include \"../../math/fps/berlekamp-massey.cpp\"\
    \n#include \"../../math/fps/sparse-matrix.cpp\"\n\nconst int MOD = 998244353;\n\
    using mint = ModInt< MOD >;\n\nint main() {\n  int N, K;\n  cin >> N >> K;\n \
    \ FPSGraph< mint > g(N);\n  for(int i = 0; i < K; i++) {\n    int a, b, c;\n \
    \   cin >> a >> b >> c;\n    g[a].emplace_back(b, c);\n  }\n  cout << sparse_determinant(g)\
    \ << endl;\n}\n"
  dependsOn:
  - template/template.cpp
  - math/combinatorics/mod-int.cpp
  - math/fps/formal-power-series.cpp
  - math/fps/berlekamp-massey.cpp
  - math/fps/sparse-matrix.cpp
  isVerificationFile: true
  path: test/verify/yosupo-sparse-matrix-det.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 03:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-sparse-matrix-det.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-sparse-matrix-det.test.cpp
- /verify/test/verify/yosupo-sparse-matrix-det.test.cpp.html
title: test/verify/yosupo-sparse-matrix-det.test.cpp
---