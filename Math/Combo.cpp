#include <bits/stdc++.h>

using namespace std;

int MAXN = 2e5;
int MOD = 1e9 + 7;
vector<long long> fac(MAXN + 1);
vector<long long> inv(MAXN + 1);

long long exp(long long x, long long n) {
    x %= MOD;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % MOD; }
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
    inv[MAXN] = exp(fac[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

long long choose(long long n, long long r) {
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}
