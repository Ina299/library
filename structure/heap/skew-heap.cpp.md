---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/mst/directed-minimum-spanning-tree.cpp
    title: "Directed-Minimum-Spanning-Tree(\u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728\
      )"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-2415.test.cpp
    title: test/verify/aoj-2415.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-2-b.test.cpp
    title: test/verify/aoj-grl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-directedmst.test.cpp
    title: test/verify/yosupo-directedmst.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Skew-Heap
    links: []
  bundledCode: "#line 1 \"structure/heap/skew-heap.cpp\"\n/**\n * @brief Skew-Heap\n\
    \ */\ntemplate< typename T, bool isMin = true >\nstruct SkewHeap {\n  struct Node\
    \ {\n    T key, lazy;\n    Node *l, *r;\n    int idx;\n\n    explicit Node(const\
    \ T &key, int idx) : key(key), idx(idx), lazy(0), l(nullptr), r(nullptr) {}\n\
    \  };\n\n  SkewHeap() = default;\n\n  Node *alloc(const T &key, int idx = -1)\
    \ {\n    return new Node(key, idx);\n  }\n\n  Node *propagate(Node *t) {\n   \
    \ if(t && t->lazy != 0) {\n      if(t->l) t->l->lazy += t->lazy;\n      if(t->r)\
    \ t->r->lazy += t->lazy;\n      t->key += t->lazy;\n      t->lazy = 0;\n    }\n\
    \    return t;\n  }\n\n  Node *meld(Node *x, Node *y) {\n    propagate(x), propagate(y);\n\
    \    if(!x || !y) return x ? x : y;\n    if((x->key < y->key) ^ isMin) swap(x,\
    \ y);\n    x->r = meld(y, x->r);\n    swap(x->l, x->r);\n    return x;\n  }\n\n\
    \  Node *push(Node *t, const T &key, int idx = -1) {\n    return meld(t, alloc(key,\
    \ idx));\n  }\n\n  Node *pop(Node *t) {\n    assert(t != nullptr);\n    return\
    \ meld(t->l, t->r);\n  }\n\n  Node *add(Node *t, const T &lazy) {\n    if(t) {\n\
    \      t->lazy += lazy;\n      propagate(t);\n    }\n    return t;\n  }\n\n  Node\
    \ *make_root() {\n    return nullptr;\n  }\n};\n"
  code: "/**\n * @brief Skew-Heap\n */\ntemplate< typename T, bool isMin = true >\n\
    struct SkewHeap {\n  struct Node {\n    T key, lazy;\n    Node *l, *r;\n    int\
    \ idx;\n\n    explicit Node(const T &key, int idx) : key(key), idx(idx), lazy(0),\
    \ l(nullptr), r(nullptr) {}\n  };\n\n  SkewHeap() = default;\n\n  Node *alloc(const\
    \ T &key, int idx = -1) {\n    return new Node(key, idx);\n  }\n\n  Node *propagate(Node\
    \ *t) {\n    if(t && t->lazy != 0) {\n      if(t->l) t->l->lazy += t->lazy;\n\
    \      if(t->r) t->r->lazy += t->lazy;\n      t->key += t->lazy;\n      t->lazy\
    \ = 0;\n    }\n    return t;\n  }\n\n  Node *meld(Node *x, Node *y) {\n    propagate(x),\
    \ propagate(y);\n    if(!x || !y) return x ? x : y;\n    if((x->key < y->key)\
    \ ^ isMin) swap(x, y);\n    x->r = meld(y, x->r);\n    swap(x->l, x->r);\n   \
    \ return x;\n  }\n\n  Node *push(Node *t, const T &key, int idx = -1) {\n    return\
    \ meld(t, alloc(key, idx));\n  }\n\n  Node *pop(Node *t) {\n    assert(t != nullptr);\n\
    \    return meld(t->l, t->r);\n  }\n\n  Node *add(Node *t, const T &lazy) {\n\
    \    if(t) {\n      t->lazy += lazy;\n      propagate(t);\n    }\n    return t;\n\
    \  }\n\n  Node *make_root() {\n    return nullptr;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/heap/skew-heap.cpp
  requiredBy:
  - graph/mst/directed-minimum-spanning-tree.cpp
  timestamp: '2020-12-18 21:55:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/aoj-2415.test.cpp
  - test/verify/aoj-grl-2-b.test.cpp
  - test/verify/yosupo-directedmst.test.cpp
documentation_of: structure/heap/skew-heap.cpp
layout: document
redirect_from:
- /library/structure/heap/skew-heap.cpp
- /library/structure/heap/skew-heap.cpp.html
title: Skew-Heap
---