#include <bits/stdc++.h>

using namespace std;

template<typename T>
class SegmentTree{
    private:
        void update(int v, int tl, int tr, int pos, long long val){
            if(tl == tr){
                t[v] = val;
            }else{
                int mid = (tl + tr) / 2;
                if(pos <= mid){
                    update(v * 2, tl, mid, pos, val);
                }else{
                    update(v * 2 + 1, mid + 1, tr, pos, val);
                }
                t[v] = merge(t[v * 2], t[v * 2 + 1]); 
            }
        }

        T query(int v, int tl, int tr, int l, int r){
            if(l > r){
                T def; // dependes on merge
                return def;
            }
            if(l == tl && r == tr){
                return t[v];
            }
            int mid = (tl + tr) / 2;
            return merge(query(v * 2, tl, mid, l, min(r, mid)), query(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r));
        }

    public:
        vector<T> t;
        vector<long long> a; // type could be anything
        function<T(T, T)> merge;
        int N;
        
        SegmentTree(vector<long long> &a, function<T(T, T)> merge): a(a), merge(merge), N((int)a.size()){
            t = vector<T>(4 * N);
        }

        void build(){
            build(1, 0, N - 1);
        }
        void update(int pos, long long val){
            update(1, 0, N - 1, pos, val);
        }
        T query(int l, int r){
            return query(1, 0, N - 1, l, r);
        }
};