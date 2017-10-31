#include <bits/stdc++.h>
#define loop(i, a, n) for (int i = a; i < int(n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const unsigned int mod = 1'000'000'007;

void trans(vi::iterator begin, vi::iterator end, int counter){
    if (counter == 0) return;
    int k = (end - begin) / 2;

    trans(begin, begin + k, counter - 1), trans(begin + k, end, counter - 1);
    loop(i, 0, k){
        unsigned int x = *(begin + i), y = *(begin + k + i);
        *(begin + i) = (x + y) % mod, *(begin + k + i) = (x + mod - y) % mod;
    }
}

vi mul(vi p1, vi p2, bool same = false){
    int k, counter;
    for (k = 1, counter = 0; k < (int)max(p1.size(), p2.size()); k *= 2, ++counter);
    p1.resize(k), p2.resize(k);

    trans(p1.begin(), p1.end(), counter);
    if (!same) trans(p2.begin(), p2.end(), counter);
    else p2 = p1;
    loop(i, 0, p1.size()) p1[i] = (ll(p1[i]) * ll(p2[i])) % mod;
    trans(p1.begin(), p1.end(), counter);

    int curr = 1, mul = mod / 2 + 1;
    loop(i, 0, counter) curr = (ll(curr) * ll(mul)) % mod;
    for (auto& x : p1) x = (ll(x) * ll(curr)) % mod;
    return p1;
}

vi power(vi p, int k){
    vi m = p;
    p.assign(p.size(), 0); p[0] = 1;
    while (k){
        if (k % 2 == 1) mul(p, m);
        k /= 2;
        mul(m, m, true);
    }
    return p;
}

int32_t main(){
    ios::sync_with_stdio(false);
    int k, l; cin >> k >> l;
    vi p(l + 1, 1);
    p[0] = p[1] = 0;
    loop(i, 2, p.size()) for (int j = 2 * i; j < (int)p.size(); j += i) p[j] = 0;

    p = power(p, k);
    cout << p[0] << endl;
    return 0;
}
