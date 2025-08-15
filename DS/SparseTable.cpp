#include <bits/stdc++.h>

using namespace std;

// floor(log2(MAX ARRAY SIZE))
constexpr int K = 25; 

struct SparseTable{
    vector<vector<long long>> st;
    int N;
    SparseTable(vector<int> &a){
        N = a.size();
        st = vector<vector<long long>>(K + 1, vector<long long>(N + 1));
        for(int i = 0; i < N;i++){
            st[0][i] = a[i];
        }
    }

    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }

    long long f(long long  x, long long y){
        return min(x, y);
    }
    void build(){
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    long long query(int L, int R){
        int i = log2_floor(R - L + 1);
        return min(st[i][L], st[i][R - (1 << i) + 1]);
    }
};