const int K = 25; // floor(log2(MAX ARRAY SIZE))
const int MAXN = 2e5 + 5;

struct SparseTable{
    vector<vector<ll>> st;
    int N;
    SparseTable(vector<int> &a){
        N = a.size();
        st = vector<vector<ll>>(K + 1, vector<ll>(MAXN));
        for(int i = 0; i < N;i++){
            st[0][i] = a[i];
        }
    }

    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }

    ll f(ll x, ll y){
        return min(x, y);
    }
    void build(){
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    ll query(int L, int R){
        int i = log2_floor(R - L + 1);
        return min(st[i][L], st[i][R - (1 << i) + 1]);
    }
};