#include <bits/stdc++.h>

using namespace std;
 
// stolen from usaco guide
class HashedString {
  private:
    // change M and B if you want
    static const long long M = (1long long << 61) - 1;
    static const long long B;

    // pow[i] contains B^i % M
    static vector<long long> pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector<long long> p_hash;

    __int128 mul(long long a, long long b) { return (__int128)a * b; }
    long long mod_mul(long long a, long long b) { return mul(a, b) % M; }

  public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
        }
    }

    long long get_hash(int start, int end) {
        long long raw_val =
            p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
        return (raw_val + M) % M;
    }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> HashedString::pow = {1};
const long long HashedString::B = uniform_int_distribution<long long>(0, M - 1)(rng);