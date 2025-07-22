#include <bits/stdc++.h>

using namespace std;

struct seg_tree{
    int n;
    vector<int> t;
    vector<int> a;
    seg_tree(vector<int> arr){
        a = arr;
        n = a.size();
        t.resize(4 * n);
    }

    int merge(int a, int b){
        return max(a, b);
    }

    void build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }else{
            int mid = (tl + tr) / 2;
            build(2 * v, tl, mid);
            build(2 * v + 1, mid + 1, tr);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }

    void update(int v, int tl, int tr, int pos, int val){
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

    int query(int v, int tl, int tr, int l, int r){
        if(l > r)
            return 0;
        if(l == tl && r == tr){
            return t[v];
        }
        int mid = (tl + tr) / 2;
        return merge(query(v * 2, tl, mid, l, min(r, mid)), query(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r));
    }

};