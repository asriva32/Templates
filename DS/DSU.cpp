#include <bits/stdc++.h>

using namespace std;

class DSU{
    private:
        void make_set(int v) {
            par[v] = v;
            S[v] = 1;
        }
        int find_set(int v) {
            if (v == par[v])
                return v;
            return par[v] = find_set(par[v]);
        }

        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                if (S[a] < S[b])
                    swap(a, b);
                par[b] = a;
                S[a] += S[b];
            }
        }
    public:
        vector<int> par;
        vector<int> S;
        DSU(int n) {
            par.resize(n);
            S.resize(n);
            for (int i = 0; i < n; ++i) {
                make_set(i);
            }
        }

        void make_set(int v);
        int find_set(int v);
        void union_sets(int a, int b);
};


