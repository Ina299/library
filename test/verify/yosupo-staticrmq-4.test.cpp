#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../template/template.cpp"

#include "../../graph/graph-template.cpp"
#include "../../graph/tree/pmormq-lowest-common-ancestor.cpp"

#include "../../graph/others/cartesian-tree.cpp"

int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int > A(N);
  cin >> A;
  auto t = cartesian_tree(A);
  PMORMQLowestCommonAncestor< int > g(N);
  int root = -1;
  for(int i = 0; i < N; i++) {
    if(t[i] == -1) {
      root = i;
      continue;
    }
    g.add_directed_edge(t[i], i);
  }
  g.build(root);
  while(Q--) {
    int l, r;
    cin >> l >> r;
    cout << A[g.lca(l, r - 1)] << "\n";
  }
}
