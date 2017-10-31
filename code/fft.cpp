#include <bits/stdc++.h>
#define loop(i, a, n) for (int i = a; i < int(n); ++i)
#define pi 3.14159265359
using namespace std;

typedef complex<double> com;

void dft(vector<com>& p, com mult){
    if (p.size() == 1) return;

    vector<com> p1(p.size() / 2), p2(p.size() / 2);
    loop(i, 0, p.size())
        if (i % 2 == 0) p1[i / 2] = p[i];
        else            p2[i / 2] = p[i];

    com curr = 1, new_mult = mult * mult;
    dft(p1, new_mult), dft(p2, new_mult);
    loop(i, 0, p.size() / 2){
        com a = p1[i], b = curr * p2[i];
        p[i] = a + b, p[i + p.size() / 2] = a - b;
        curr *= mult;
    }
}

void dft(vector<com>& p, int k){
    dft(p, polar(1., k * 2 * pi / p.size()));
}

vector<double> mul(const vector<double>& _p1, const vector<double>& _p2){
    vector<com> p1(_p1.size()), p2(_p2.size());
    loop(i, 0, p1.size()) p1[i] = _p1[i];
    loop(i, 0, p2.size()) p2[i] = _p2[i];

    int k = 1;
    while (k < 2 * (int)p1.size() - 1 || k < 2 * (int)p2.size() - 1) k *= 2;
    while ((int)p1.size() < k) p1.push_back(0);
    while ((int)p2.size() < k) p2.push_back(0);

    dft(p1, 1), dft(p2, 1);

    vector<com> p(p1.size());
    loop(i, 0, p1.size()) p[i] = p1[i] * p2[i];

    dft(p, -1);

    while (p.size() > 1 && norm(p.back()) < 0.001) p.pop_back();
    vector<double> res(p.size());
    loop(i, 0, res.size()) res[i] = real(p[i]) / p1.size();
    return res;
}