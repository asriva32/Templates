#include <bits/stdc++.h>

using namespace std;


class NT {
    constexpr int mxN = 1e5;
    
    vector<bool> is_prime(mxN+1, true);
    vector<int> lp(mxN+1);
    vector<int> pr;
    void sieve(){
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= mxN; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= mxN; j += i)
                    is_prime[j] = false;
            }
        }
    }
    
    void lin_sieve(){
        for (int i=2; i <= mxN; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for (int j = 0; i * pr[j] <= mxN; ++j) {
                lp[i * pr[j]] = pr[j];
                if (pr[j] == lp[i]) {
                    break;
                }  
            }
        }
    }
    
    vector<int> factorize(int x)
    {
        vector<int> ret;
        while (x != 1) {
            ret.push_back(lp[x]);
            x = x / lp[x];
        }
        return ret;
    }
}