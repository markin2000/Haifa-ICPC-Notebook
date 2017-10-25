#include <bits/stdc++.h>
#define loop(i, a, n) for (ll i = a; i < ll(n); ++i)
#define loop_rev(i, b, a) for (ll i = b; i >= ll(a); --i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

struct fraction{
    ll a, b;
    fraction(ll _a, ll _b = 1) : a(_a), b(_b){}
};

inline bool operator<(const fraction& f1, const fraction& f2){
    return f1.a * f2.b < f2.a * f1.b;
}

struct line{
    ll a, b;

    line(ll _a, ll _b) : a(_a), b(_b){}

    ll operator()(ll x) const{
        return a * x + b;
    }
};

inline fraction intersection(const line& l1, const line& l2){
    return fraction(l1.b - l2.b, l2.a - l1.a);
}

struct cht{
    ll pos = 0;
    vector<line> arr = {};

    cht(){}

    void insert_line_at_end(const line& l){
        if (arr.size() != 0 && !(ii(l.a, l.b) < ii(arr.back().a, arr.back().b))) return;
        if (arr.size() != 0 && l.a == arr.back().a) arr.pop_back();
        while (arr.size() >= 2 && !(intersection(arr[arr.size() - 2], arr.back()) < intersection(arr.back(), l))) arr.pop_back();
        arr.push_back(l);
    }

    ll operator()(ll x){
        while (pos != ll(arr.size()) - 1 && arr[pos](x) > arr[pos + 1](x)) ++pos;
        return arr[pos](x);
    }
};

int main(){
    cht yuval;

    return 0;
}
